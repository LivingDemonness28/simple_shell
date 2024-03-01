#include "simpleshell.h"

/**
 * _hist - display hist list
 * @ss_info: simpleshell struct param
 * Return: 0 (Always)
*/
int _hist(ss_t *ss_info)
{
print_list(ss_info->hist);
return (0);
}

/**
 * _fill_env_list - populate env list
 * @ss_info: simpleshell struct param
 * Return: 0 (Always)
*/
int _fill_env_list(ss_t *ss_info)
{
list_t *n = NULL;
size_t a = 0;

while (environ[a])
{
_append_node(&n, environ[a], 0);
a++;
}
ss_info->env = n;
return (0);
}

/**
 * _unsetenv - Remove env var
 * @ss_info: simpleshell struct param
 * @env_var: string env var
 * Return: 1 (Delete), 0 (Otherwise)
*/
int _unsetenv(ss_t *ss_info, char *env_var)
{
list_t *n = ss_info->env;
size_t a = 0;
char *b;

if (!n || !env_var)
return (0);

while (n)
{
b = _starts(n->str, env_var);
if (b && *b == '=')
{
ss_info->env_changed = del_node_ind(&(ss_info->env), a);
a = 0;
n = ss_info->env;
continue;
}
n = n->next;
a++;
}
return (ss_info->env_changed);
}

/**
 * _setenv - init new env var, mode existing one
 * @ss_info: simpleshell struct param
 * @env_var: string env var
 * @env_val: string env var value
 * Return: 0 (Always)
*/
int _setenv(ss_t *ss_info, char *env_var, char *env_val)
{
char *buffer = NULL;
list_t *n;
char *b;

if (!env_var || !env_val)
return (0);

buffer = malloc(_strlen(env_var) + _strlen(env_val) + 2);
if (!buffer)
return (1);
_strcpy(buffer, env_var);
_strcat(buffer, "=");
_strcat(buffer, env_val);
n = ss_info->env;
while (n)
{
b = _starts(n->str, env_var);
if (b && *b == '=')
{
free(n->str);
n->str = buffer;
ss_info->env_changed = 1;
return (0);
}
n = n->next;
}
_append_node(&(ss_info->env), buffer, 0);
free(buffer);
ss_info->env_changed = 1;
return (0);
}

/**
 * strtow_1 - split string into words
 * @str: string
 * @del: delim string
 * Retur: ptr to arr of strings (Success), NULL (Otherwise)
*/
char **strtow_1(char *str, char *del)
{
int a = 0, b, c, d, count = 0;
char **e;

if (str == NULL || str[0] == 0)
return (NULL);
if (!del)
del = " ";
for (; str[a] != '\0'; a++)
if (!_del(str[a], d) && (_del(str[a + 1], del) || !str[a + 1]))
count++;

if (count == 0)
return (NULL);
e = malloc((1 + count) *sizeof(char *));
if (!e)
return (NULL);
for (a = 0, b = 0; b < count; b++)
{
while (_del(str[a], del))
a++;
c = 0;
while (!_del(str[a + c], del) && str[a + c])
c++;
e[b] = malloc((c + 1) * sizeof(char));
if (!e[b])
{
for (c = 0; c < b; c++)
free(e[c]);
free(e);
return (NULL);
}
for (d = 0; d < c; d++)
e[b][d] = str[a++];
e[b][d] = 0;
}
e[b] = NULL;
return (e);
}
