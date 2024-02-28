#include "simpleshell.h"

/**
 * dup_chars - duplicate chars
 * @pstr: Path string
 * @start: start index
 * @stop: stop index
 * Return: ptr to new buffer
*/
char *dup_chars(char *pstr, int start, int stop)
{
static char buffer[1024];
int a = start, b = 0;

while (a < stop)
{
if (pstr[a] != ':')
buffer[b++] = pstr[a];
a++;
}
buffer[b] = 0;
return (buffer);
}

/**
 * _cmd - determines if a file is
 * an exe cmd
 * @ss_info: simpleshell struct param
 * @fp: file path
 * Return: 1 (Sucess), 0 (Otherwise)
*/
int _cmd(ss_t *ss_info, char *fp)
{
struct stat st;

(void)ss_info;
if (!fp || stat(fp, &st))
return (0);

if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
 * node_index - get node index
 * @h: ptr to list head
 * @n: ptr to node
 * Return: node index (Success), -1 (Otherwise)
*/
ssize_t node_index(list_t *h, list_t *n)
{
size_t a = 0;

for (; h; a++)
{
if (h == n)
return (a);
h = h->next;
}
return (-1);
}

/**
 * _pre_node - returns node whose str starts
 * wit prefix
 * @n: ptr to list head
 * @pre: string
 * @c: char after pre
 * Return: match node (Success), null (Otherwise)
*/
list_t _pre_node(list_t *n, char *pre, char c)
{
char *ptr = NULL;

for (; n; n = n->next)
{
ptr = _starts(n->str, pre);
if (ptr && ((c == -1) || (*ptr == c)))
return (n);
}
return (NULL);
}

/**
 * _list_len - length of linked list
 * @h: ptr to first node
 * Return: list len
*/
size_t _list_len(const list_t *h)
{
size_t a = 0;

while (h)
{
h = h->next;
a++;
}
return (a);
}
