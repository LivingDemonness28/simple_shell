#include "simpleshell.h"

/**
 * _node_ind - fetch node index.
 * @h: head of list.
 * @n: ptr to node.
 * Return: node index (Success), -1 (Otherwise)
*/
ssize_t _node_ind(list_t *h, list_t *n)
{
size_t a = 0;

for (; h; h = h->next)
{
if (h == n)
return (a);
a++;
}
return (-1);
}
