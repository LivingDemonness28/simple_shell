#include "simpleshell.h"

/**
 * fork_cmd - fork exe thread
 * @ss_info: simpleshell struct param
 * Return: Nothing
*/
void fork_cmd(ss_t *ss_info)
{
pid_t child_pid;

child_pid = fork();
if (child_pid == -1)
{
perror("Error:");
return;
}
if (child_pid == 0)
{
if (execve(ss_info->cmd_path, ss_info->argv, load_env(ss_info)) == -1)
{
_clear_shell(ss_info, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
}
else
{
wait(&(ss_info->status));
if (WIFEXITED(ss_info->status))
{
ss_info->status = WEXITSTATUS(ss_info->status);
if (ss_info->status == 126)
_eprint(ss_info, "Permission denied\n")
}
}
}

/**
 * find_cmd - finds cmd in path
 * @ss_info: simpleshell struct param
 * Return: Nothing
*/
void find_cmd(ss_t *ss_info)
{
char *path = NULL;
int a , b;

ss_info->cmd_path = ss_info->argv[0];
if (ss_info->linecount_flag == 1)
{
ss_info->linecount++;
ss_info->linecount_flag = 0;
}
for (a = 0, b = 0; ss_info->arg[a]; a++)
if (!_del(ss_info->arg[a], " \t\n"))
b++;
if (!b)
return;

path = exe_path(ss_info, _getenv(ss_info, "PATH="), ss_info->argv[0]);
if (path)
{
ss_info->cmd_path = path;
fork_cmd(ss_info);
}
else
{
if ((_interact(ss_info) || _getenv(ss_info, "PATH=")
|| ss_info->argv[0][0] == '/') && _cmd(ss_info, ss_info->argv[0]))
fork_cmd(ss_info);
else if (*(ss_info->arg) != '\n')
{
ss_info->status = 127;
_eprint(ss_info, "not found\n");
}
}
}

/**
 * _help - help function
 * @ss_info: simpleshell struct param
 * Return: 0 (Always)
*/
int _help(ss_t *ss_info)
{
return (0);
}

/**
 * find_builtin - find builtin cmd
 * @ss_info: simpleshell struct param
 * Return: -1 (Not found), 0 (Executed Successfully),
 * 1 (Found but not successful), 2 (Signals exit())
*/
int find_builtin(ss_t *ss_info)
{
int a = 0, buitin_ret = -1;
bi_table builtinbl[] = {
{"exit", _shellExit},
{"env", _print_env},
{"help", _help},
{"history", _hist},
{"setenv", _setenv2},
{"unsetenv", _unsetenv2},
{"cd", _cd},
{"alias", _alias},
{NULL, NULL}
};

for (; builtinbl[a].cmd_type; a++)
if (_strcmp(ss_info->argv[0], builtinbl[a].type) == 0)
{
ss_info->linecount++;
buitin_ret = builtinbl[a].func(ss_info);
break;
}
return (buitin_ret);
}

/**
 * hsh - main loop
 * @ss_info: simpleshell struct param
 * @av: arg vector
 * Return: 0 (Success), 1 (Error) or Error code
*/
int hsh(ss_t *ss_info, char **av)
{
ssize_t a = 0;
int builtin_ret = 0;

while (a != -1 && builtin_ret != -2)
{
clear_info(ss_info);
if (_interact(ss_info))
_puts("$ ");
_eputchar(-1);
a = get_input(ss_info);
if (a != -1)
{
_init_info(ss_info, av);
builtin_ret = find_builtin(ss_info);
if (builtin_ret == -1)
find_cmd(ss_info);
}
else if (_interact(ss_info))
_putchar('\n');
_clear_shell(ss_info, 0);
}
_whist(ss_info);
_clear_shell(ss_info, 1);
if (!_interact(ss_info) && ss_info->status)
exit(ss_info->status);
if (builtin_ret == -2)
{
if (ss_info->errnum == -1)
exit(ss_info->status);
exit(ss_info->errnum);
}
return (builtin_ret);
}
