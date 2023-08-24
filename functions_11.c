#include "simpleshell.h"

/**
 * _block_ctrlc - blocks ctrl-c
 * @sn: signal number
 * Return: Nothing
*/
void _block_ctrlc(__attribute__((unused))int sn)
{
_puts("\n");
_puts("ss$ ");
_putchar(-1);
}

/**
 * _updt_env - init new env var, or mod
 * existing one.
 * @ss_info: simpleshell_t struct param.
 * @envvar: string env var.
 * @envval: env var val.
 * Return: 0 (Always)
*/
int _updt_env(simpleshell_t *ss_info, char *envvar, char *envval)
{
char *buffer = malloc(_strlen(envvar) + _strlen(envval) + 2), *a;
list_t *n = ss_info->local_env_list;

if (!envvar || !envval)
return (0);

if (!buffer)
return (1);
_strcpy(buffer, envvar);
_strcat(buffer, "=");
_strcat(buffer, envval);

for (; n; n = n->next)
{
a = _starts(n->string, envvar);
if (a && *a == '=')
{
free(n->string);
n->string = buffer;
ss_info->env_mod = 1;
return (0);
}
n = n->next;
}
_append_node(&(ss_info->local_env_list), buffer, 0);
free(buffer);
ss_info->env_mod = 1;
return (0);
}

/**
 * _del_alias - unsets an alias and removes it
 * from the linked list.
 * @ss_info: simpleshell_t struct param.
 * @str: string.
 * Return: 0 (Success), 1 (Otherwise)
*/
int _del_alias(simpleshell_t *ss_info, char *str)
{
char *es = _strchr(str, '='), org_char = *es;
int res;

if (!es)
return (1);
*es = 0;
res =  _del_node_at_ind(&(ss_info->alias_node),
_node_ind(ss_info->alias_node, _prefix_node(ss_info->alias_node,
str, -1)));
*es = org_char;
return (res);
}

/**
 * _add_alias - adds an alias string or
 * updates an existing one.
 * @ss_info: simpleshell_t struct param.
 * @str: string alias.
 * Return: 0 (Success), 1 (Otherwise)
*/
int _add_alias(simpleshell_t *ss_info, char *str)
{
char *es = _strchr(str, '=');

if (!es)
return (1);
if (!*++es)
return (_del_alias(ss_info, str));

_del_alias(ss_info, str);
return (_append_node(&(ss_info->alias_node), str,
0) == NULL);
}

/**
 * _alias - mimics alias.
 * @ss_info: simpleshell_t struct param.
 * Return: 0 (Always)
*/
int _alias(simpleshell_t *ss_info)
{
int a = 1;
char *es = NULL;
list_t *n = NULL;

if (ss_info->ac == 1)
{
for (n = ss_info->alias_node; n; n = n->next)
{
_dis_alias(n);
}
return (0);
}
for (; ss_info->av[a]; a++)
{
es = _strchr(ss_info->av[a], '=');
if (es)
_add_alias(ss_info, ss_info->av[a]);
else
_dis_alias(_prefix_node(ss_info->alias_node, ss_info->av[a], '='));
}
return (0);
}
