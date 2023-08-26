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
n = h;
while (n)
{
nn = n->next;
free(n->string);
free(n);
n = nn;
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
list_t *nn, *n;

if (!h)
return (NULL);

n = *h;
nn = malloc(sizeof(list_t));
if (!nn)
return (NULL);
_memset((void *)nn, 0, sizeof(list_t));
nn->number = num;
if (str)
{
nn->string = _strdup(str);
if (!nn->string)
{
free(nn);
return (NULL);
}
}
if (n)
{
while (n->next)
n = n->next;
n->next = nn;
}
else
*h = nn;
return (nn);
}

/**
 * _unshift_node - adds node to start of list.
 * @h: head of list.
 * @str: string field of new node.
 * @num: node index.
 * Return: ptr to new node (Success), NULL (Otherwise).
*/
list_t *_unshift_node(list_t **h, const char *str, int num)
{
list_t *nh = malloc(sizeof(list_t));

if (!h)
return (NULL);
if (!nh)
return (NULL);
_memset((void *)nh, 0, sizeof(list_t));
nh->number = num;
if (str)
{
nh->string = _strdup(str);
if (!nh->string)
{
free(nh);
return (NULL);
}
}
nh->next = *h;
*h = nh;
return (nh);
}

/**
 * _listlen - Determines the length of a linked list.
 * @head: head of list.
 * Return: The size of the linked list.
 */
size_t _listlen(const list_t *head)
{
size_t a = 0;

while (head)
{
head = head->next;
a++;
}
return (a);
}

/**
 * _prefix_node - returns node whose string
 * starts with a prefix
 * @h: head of list.
 * @start: string to match.
 * @c: next char after prefix to match.
 * Return: match node (Success), NULL (Otherwise)
*/
list_t *_prefix_node(list_t *h, char *start, char c)
{
char *a = NULL;

while (h)
{
a = _starts(h->string, start);
if (a && ((c == -1) || (*a == c)))
return (h);
h = h->next;
}
return (NULL);
}
