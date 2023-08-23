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

/**
 * _append_node - adds node to end of list.
 * @h: head of list.
 * @str: string field of new node.
 * @num: node index.
 * Return: ptr to new node (Success), NULL (Otherwise).
*/
list_t *_append_node(list_t **h, const char *str, int num)
{
list_t *nn = malloc(sizeof(list_t)), *n = *h;

if (!h)
return NULL;

if (!nn)
return NULL;

_memset((void *)nn, 0, sizeof(list_t));
nn->num = num;

if (str)
{
nn->str = _strdup(str);
if (!nn->str)
{
free(nn);
return (NULL);
}
}

if (n)
{
for (; n->next; n = n->next)
{
}
n->next = nn;
}
else
{
*h = nn;
}

return (nn);
}
