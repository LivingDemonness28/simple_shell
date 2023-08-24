#include "simpleshell.h"

/**
 * _copy_env - str copy of env.
 * @ss_info: simpleshell_t struct param.
 * Return: 0 (Always)
*/
char **_copy_env(simpleshell_t *ss_info)
{
if (ss_info->custom_env || ss_info->env_mod)
{
ss_info->custom_env = _strarr(ss_info->local_env_list);
ss_info->env_mod = 0;
}
return (ss_info->custom_env);
}

/**
 * _del_env - unset an env var in the local
 * env list.
 * @ss_info: simpleshell_t struct param
 * @envvar: environment variable/
 * Return: 1 (Success), 0 (Otherwise)
*/
int _del_env(simpleshell_t *ss_info, char *envvar)
{
list_t *n = ss_info->local_env_list;
size_t a = 0;
char *es;

if (!n || !envvar)
return (0);

for (; n; a++)
{
es = _starts(n->string, envvar);
if (es && *es == '=')
{
ss_info->env_mod = _del_node_at_ind(&(ss_info->local_env_list), a);
a = 0;
n = ss_info->local_env_list;
continue;
}
n = n->next;
a++;
}
return (ss_info->env_mod);
}
