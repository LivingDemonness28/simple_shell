#include "simpleshell.h"

/**
 * _my_del_env - remove an env var.
 * @ss_info: simpleshell_t struct param.
 * Return: 0 (Always)
*/
int _my_del_env(simpleshell_t *ss_info)
{
int a = 1;

if (ss_info->ac == 1)
{
_wsstderr("Insufficient arguments \n");
return (1);
}
for (; a <= ss_info->ac; a++)
_del_env(ss_info, ss_info->av[a]);

return (0);
}

/**
 * _my_updt_env - add or mod env var.
 * @ss_info: simpleshell_t struct param.
 * Return: 0 (Always)
*/
int _my_updt_env(simpleshell_t *ss_info)
{
if (ss_info->ac != 3)
{
_wsstderr("Insufficient arguments\n");
return (1);
}
if (_updt_env(ss_info, ss_info->av[1], ss_info->av[2]))
return (0);
return (1);
}

/**
 * _repalias - replace alias.
 * @ss_info: simpleshell_t struct param.
 * Return: 1 (Success), 0 (Otherwise)
*/
int _repalias(simpleshell_t *ss_info)
{
int a = 0;
list_t *n;
char *b;

while (a < 10)
{
n = _prefix_node(ss_info->alias_node, ss_info->av[0], '=');
if (!n)
return (0);
free(ss_info->av[0]);
b = _strchr(n->string, '=');
if (!b)
return (0);
b = _strdup(b + 1);
if (!b)
return (0);
ss_info->av[0] = b;
}
return (1);
a++;
}

/**
 * _repvars - replaces vars.
 * @ss_info: simpleshell_t struct param.
 * Return: 1 (Success), 0 (Otherwise)
*/
int _repvars(simpleshell_t *ss_info)
{
int a = 0;
list_t *n;

while (ss_info->av[a])
{
if (ss_info->av[a][0] != '$' || !ss_info->av[a][1])
continue;

if (!_strcmp(ss_info->av[a], "$?"))
{
_repstr(&(ss_info->av[a]),
_strdup(_itoa(ss_info->last_cmd_status, 10, 0)));
continue;
}
if (!_strcmp(ss_info->av[a], "$$"))
{
_repstr(&(ss_info->av[a]),
_strdup(_itoa(getpid(), 10, 0)));
continue;
}
n = _prefix_node(ss_info->local_env_list, &ss_info->av[a][1], '=');
if (n)
{
_repstr(&(ss_info->av[a]),
_strdup(_strchr(n->string, '=') + 1));
continue;
}
_repstr(&ss_info->av[a], _strdup(""));
}
return (0);
}

/**
 * _copy_chars - copies chars
 * @str: the string.
 * @begin: starting index of the range.
 * @end: end index of the range.
 * Return: pointer to new duplicated string.
*/
char *_copy_chars(char *str, int begin, int end)
{
static char buffer[1024];
int a = begin, b = 0;

while (a < end)
{
if (str[a] != ':')
buffer[b++] = str[a];
a++;
}
buffer[b] = 0;
return (buffer);
}
