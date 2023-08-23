#include "simpleshell.h"

/**
 * _clear_list - frees all nodes of a linked list.
 * @hp: head of list.
 * Return: Nothing.
*/
void _clear_list(list_t **hp)
{
list_t *n, *nn, *h;

if (!hp || !*hp)
return;

h = *hp;
for (n = h; n; n = nn)
{
nn = n->next;
free(n->string);
free(n);
}
*hp = NULL;
}
