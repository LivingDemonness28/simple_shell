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
_w_str_stderr("Insufficient arguments \n");
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
_w_str_stderr("Insufficient arguments\n");
return (1);
}
if (_updt_env(ss_info, ss_info->av[1], ss_info->av[2]))
return (0);
return (1);
}
