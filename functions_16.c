#include "simpleshell.h"

/**
 * _exe_cmd - executes built in commands
 * @ss_info: simpleshell_t struct param.
 * Return: 0 (Success), 1 (builtin found but
 * not successful), 2 (builtin signals exit()),
 * -1 (Otherwise)
*/
int _exe_cmd(simpleshell_t *ss_info)
{
int index = 0, res = -1;
ss_table builtin_table[] = {
{"exit", _exit_shell},
{"env", _currenv},
{"help", _shell_help},
{"history", _hprint},
{"setenv", _my_updt_env},
{"unsetenv", _my_del_env},
{"cd", _updt_cd},
{"alias", _alias},
{NULL, NULL}
};

while (builtin_table[index].cmd_type)
{
if (_strcmp(ss_info->av[0], builtin_table[index].cmd_type) == 0)
{
ss_info->line_num++;
res = builtin_table[index].cmd_func(ss_info);
break;
}
index++;
}
return (res);
}

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
_reset_info(ss_info);
if (_interact(ss_info))
_puts("$ ");
_wcstderr(-1);
a = _exe_input(ss_info);
if (a != -1)
{
_init_info(ss_info, argv);
b_res = _exe_cmd(ss_info);
if (b_res == -1)
_find_exe(ss_info);
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

/**
 * _fork_exe - creates a child process and
 * exe a cmd in it.
 * @ss_info: simpleshell_t struct param.
 * Return: Nothing.
*/
void _fork_exe(simpleshell_t *ss_info)
{
pid_t cpid = fork();

if (cpid == -1)
{
perror("Failed to fork process:");
return;
}
if (cpid == 0)
{
if (execve(ss_info->cmd_path, ss_info->av,
_copy_env(ss_info)) == -1)
{
_clear_info(ss_info, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
}
else
{
wait(&(ss_info->last_cmd_status));
if (WIFEXITED(ss_info->last_cmd_status))
{
ss_info->last_cmd_status = WEXITSTATUS(ss_info->last_cmd_status);
if (ss_info->last_cmd_status == 126)
_eprint(ss_info, "Execution permission denied\n");
}
}
}

/**
 * _find_exe - searches for and executes a cmd.
 * @ss_info: simpleshell_t struct param.
 * Return: Nothing.
*/
void _find_exe(simpleshell_t *ss_info)
{
char *cmd_path = NULL;
int a = 0, b = 0;

ss_info->cmd_path = ss_info->av[0];
if (ss_info->line_count_tracker == 1)
{
ss_info->line_num++;
ss_info->line_count_tracker = 0;
}
while (ss_info->input_args[a])
{
if (!_del(ss_info->input_args[a], " \t\n"))
b++;
a++;
}
if (!b)
return;

cmd_path = _search_exe(ss_info, _envval(ss_info, "CUSTOM_PATH="),
ss_info->av[0]);
if (cmd_path)
{
ss_info->cmd_path = cmd_path;
_fork_exe(ss_info);
}
else
{
if ((_interact(ss_info) || _envval(ss_info, "CUSTOM_PATH=")
|| ss_info->av[0][0] == '/') && _check_cmd(ss_info, ss_info->av[0]))
_fork_exe(ss_info);
else if (*(ss_info->input_args) != '\n')
{
ss_info->last_cmd_status = 127;
_eprint(ss_info, "Command not found or not executable\n");
}
}
}
