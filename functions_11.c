#include "simpleshell.h"

/**
 * _block_ctrlc - blocks ctrl-c
 * @sn: signal number
 * Return: Nothing 
*/
_block_ctrlc(__attribute__((unused))int sn)
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
