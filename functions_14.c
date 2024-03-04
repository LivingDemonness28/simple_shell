#include "simpleshell.h"

/**
 * strtow_2 - splits a str into e.
 * @str: the input str.
 * @del: the del str.
 * Return: pointer to an arr of e (Success), NULL (Otherwise).
*/
char **strtow_2(char *str, char del)
{
int a = 0, b, c, d, count = 0;
char **e;

if (str == NULL || str[0] == '\0')
return (NULL);
for (; str[a] != '\0'; a++)
if ((str[a] != del && str[a + 1] == del) ||
(str[a] != del && !str[a + 1]) || str[a + 1] == del)
count++;
if (count == 0)
return (NULL);
e = malloc((1 + count) *sizeof(char *));
if (!e)
return (NULL);
for (a = 0, b = 0; b < count; b++)
{
while (str[a] == del && str[a] != del)
a++;
c = 0;
while (str[a + c] != del && str[a + c] != del)
c++;
e[b] = malloc((c + 1) *sizeof(char));
if (!e[b])
{
for (c = 0; c < b; c++)
free(e[c]);
free(e);
return (NULL);
}
for (d = 0; d < c; d++)
e[b][d] = str[a++];
e[b][d] = '\0';
}
e[b] = NULL;
return (e);
}

/**
 * _init_info - initialises shell info
 * @ss_info: simpleshell struct param
 * @av: arg vector
 * Return: Nothing
*/
void _init_info(ss_t *ss_info, char **av)
{
int a = 0;

ss_info->filename = av[0];
if (ss_info->arg)
{
ss_info->argv = strtow_1(ss_info->arg, "\t");
if (!ss_info->argv)
{
ss_info->argv = malloc(sizeof(char *) * 2);
if (ss_info->argv)
{
ss_info->argv[0] = _strdup(ss_info->arg);
ss_info->argv[1] = NULL;
}
}
for (a = 0; ss_info->argv && ss_info->argv[a]; a++)
;
ss_info->argc = a;

_repalias(ss_info);
_repvars(ss_info);
}
}

/**
 * _unsetenv2 - Remove env var
 * @ss_info: simpleshell struct param
 * Return: 0 (Always)
*/
int _unsetenv2(ss_t *ss_info)
{
int a = 1;

if (ss_info->argc == 1)
{
_eputs("Too few arguments. \n");
return (1);
}
for (; a <= ss_info->argc; a++)
_unsetenv(ss_info, ss_info->argv[a]);
return (0);
}

/**
 * _setenv2 - Init new env var, mode existing one
 * @ss_info: simpleshell struct param
 * Return: 0 (Always)
*/
int _setenv2(ss_t *ss_info)
{
if (ss_info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(ss_info, ss_info->argv[1], ss_info->argv[2]))
return (0);
return (1);
}

/**
 * unset_alias - set alias to str
 * @ss_info: simpleshell struct param
 * @str: alias string
 * Return: 0 (Success), 1 (Error)
*/
int unset_alias(ss_t *ss_info, char *str)
{
char *a, b;
int rets;

a = _strchr(str, '=');
if (!a)
return (1);
b = *a;
*a = 0;
rets = del_node_ind(&(ss_info->_alias),
node_index(ss_info->_alias, _pre_node(ss_info->_alias, str, -1)));
*a = b;
return (rets);
}
