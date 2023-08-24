#include "simpleshell.h"

/**
 * _exe_shell - runs the shell's main loop,
 * processing user input, executing cmds, and
 * managing the shell's behaviour
 * @ss_info: simpleshell_t struct param.
 * @argv: arg vector.
 * Return: 0 (Success), 1 or error code (Otherwise)
*/
int _exe_shell(simpleshell_t *ss_info, char **argv)
{
ssize_t a = 0;
int b_res = 0;

for (; a != -1 && b_res != -2;)
{
_re_init_info(ss_info);
if (_interact(ss_info))
_puts("$ ");
_w_stderr(-1);
a = _exe_input(ss_info);
if (a != -1)
{
_init_info(ss_info, argv);
b_res = find_builtin(ss_info);
if (b_res == -1)
find_cmd(ss_info);
}
else if (_interact(ss_info))
_putchar('\n');
_clear_info(ss_info, 0);
}
_w_hist(ss_info);
_clear_info(ss_info, 1);
if (!_interact(ss_info) && ss_info->last_cmd_status)
exit(ss_info->last_cmd_status);
if (b_res == -2)
{
if (ss_info->exit_error == -1)
exit(ss_info->last_cmd_status);
exit(ss_info->exit_error);
}
return (b_res);
}
