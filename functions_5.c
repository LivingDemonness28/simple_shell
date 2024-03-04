#include "simpleshell.h"

/**
 * free_list - free nodes of list
 * @hp: ptr to head node
 * Return: Nothing
*/
void free_list(list_t **hp)
{
list_t *n, *nn, *h;

if (!hp || !*hp)
return;
h = *hp;
n = h;
while (n)
{
nn = n->next;
free(n->str);
free(n);
n = nn;
}
*hp = NULL;
}

/**
 * plist_str - print only str element of
 * list
 * @h: ptr to first node
 * Return: list size
*/
size_t plist_str(const list_t *h)
{
size_t a = 0;

while (h)
{
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
a++;
}
return (a);
}

/**
 * recount_hist - recounts and updates in hist
 * linked list
 * @ss_info: simpleshell struct param
 * Return: new histcount
*/
int recount_hist(ss_t *ss_info)
{
list_t *n = ss_info->hist;
int a = 0;

while (n)
{
n->number = a++;
n = n->next;
}
return (ss_info->_histline = a);
}

/**
 * _strncpy - copy string
 * @dest: destination
 * @src: source str
 * @n: amount of chars to be copied
 * Return: ptr to dest
*/
char *_strncpy(char *dest, char *src, int n)
{
int a = 0, b;
char *s = dest;

while (src[a] != '\0' && a < n - 1)
{
dest[a] = src[a];
a++;
}
if (a < n)
{
b = a
for (b < n)
{
dest[b] = '\0';
}
}
return (s);
}

/**
 * _strchr - locates char in str
 * @str: string
 * @c: char
 * Return: ptr to mem area
*/
char *_strchr(char *str, char c)
{
while (*str != '\0')
{
if (*str == c)
{
return (str);
}
str++;
}
return (NULL);
}
