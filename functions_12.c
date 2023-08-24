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
