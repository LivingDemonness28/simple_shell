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
