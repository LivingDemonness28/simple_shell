#include "simpleshell.h"

/**
 * _lprint - prints all elements of a linked list.
 * @head: head of list.
 * Return: Num of nodes in list.
*/
size_t _lprint(const list_t *head)
{
size_t a = 0;

for (; head; a++)
{
_puts(_itoa(head->number, 10, 0));
_putchar(':');
_putchar(' ');
_puts(head->string ? head->string : "(nil)");
_puts("\n");
head = head->next;
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
