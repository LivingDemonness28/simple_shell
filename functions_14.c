#include "simpleshell.h"

/**
 * _lprint - prints all elements of a linked list.
 * @head: head of list.
 * Return: Num of nodes in list.
*/
size_t _lprint(const list_t *head)
{
size_t a = 0;

while (head)
{
_puts(_itoa(head->number, 10, 0));
_putchar(':');
_putchar(' ');
_puts(head->string ? head->string : "(nil)");
_puts("\n");
head = head->next;
a++;
}
return (a);
}

/**
 * _hprint - prints cmd hist, one per line.
 * @ss_info: simpleshell_t struct param.
 * Return: 0 (Always)
*/
int _hprint(simpleshell_t *ss_info)
{
_lprint(ss_info->cmd_hist);
return (0);
}

/**
 * _clear_info - clears and deallocates memory
 * used by the simpleshell_t struct.
 * @ss_info: simpleshell_t struct param.
 * @ff: true if all fields are freed.
 * Return: Nothing.
*/
void _clear_info(simpleshell_t *ss_info, int ff)
{
_free_strarr(ss_info->av);
ss_info->av = NULL;
ss_info->cmd_path = NULL;
if (ff)
{
if (!ss_info->command_buf)
free(ss_info->input_args);
if (ss_info->local_env_list)
_clear_list(&(ss_info->local_env_list));
if (ss_info->cmd_hist)
_clear_list(&(ss_info->cmd_hist));
if (ss_info->alias_node)
_clear_list(&(ss_info->alias_node));
_free_strarr(ss_info->custom_env);
ss_info->custom_env = NULL;
_free_ptr((void **)ss_info->command_buf);
if (ss_info->rfd > 2)
close(ss_info->rfd);
_putchar(-1);
}
}

/**
 * _init_info - sets simpleshell_t struct
 * @ss_info: simpleshell_t struct param.
 * @argv: arg vector.
 * Return: Nothing.
*/
void _init_info(simpleshell_t *ss_info, char **argv)
{
int a = 0;

ss_info->filename = argv[0];
if (ss_info->input_args)
{
ss_info->av = _strtow_1(ss_info->input_args, "\t");
if (!ss_info->av)
{
ss_info->av[0] = _strdup(ss_info->input_args);
ss_info->av[1] = NULL;
}
}
while (ss_info->av && ss_info->av[a])
{
a++;
}
ss_info->ac = a;
_repalias(ss_info);
_repvars(ss_info);
}

/**
 * _search_exe - searches for an exe cmd in the
 * specified paths.
 * @ss_info: simpleshell_t struct param.
 * @str: the str.
 * @command: command to find
 * Return: cmd path (Success), NULL (Otherwise)
*/
char *_search_exe(simpleshell_t *ss_info, char *str, char *command)
{
int a = 0, cp = 0;
char *cmd_path;

if (!str)
return (NULL);
if ((_strlen(command) > 2) && _starts(command, "./"))
{
if (_check_cmd(ss_info, command))
return (command);
}
for (; 1; a++)
{
if (!str[a] || str[a] == ':')
{
cmd_path = _copy_chars(str, cp, a);
if (!*cmd_path)
_strcat(cmd_path, command);
else
{
_strcat(cmd_path, "/");
_strcat(cmd_path, command);
}
if (_check_cmd(ss_info, cmd_path))
return (cmd_path);
if (!str[a])
break;
cp = a;
}
}
return (NULL);
}
