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

/**
 * _strarr - returns an array of strings.
 * @h: head of list.
 * Return: string array
*/
char **_strarr(list_t *h)
{
list_t *n = h;
size_t a = _listlen(h), b;
char **strarr = malloc(sizeof(char *) * (a + 1));
char *str;

if (!h || !a)
return NULL;

if (!strarr)
return NULL;

a = 0;
while (n)
{
str = malloc(_strlen(n->str) + 1);
if (!str)
{
for (b = 0; b < a; b++)
free(strarr[b]);
free(strarr);
return NULL;
}

str = _strcpy(str, n->str);
strarr[a] = str;
a++;
n = n->next;
}

strarr[a] = NULL;
return strarr;
}
