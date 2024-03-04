#include "simpleshell.h"

/**
 * _getline - get next line of input from STDIN
 * @ss_info: simpleshell struct param
 * @ptr: pointer to buffer
 * @len: size of pointer buffer
 * Return: d
*/
int _getline(ss_t *ss_info, char **ptr, size_t *len)
{
static char buffer[1024];
static size_t a, len1;
size_t b;
ssize_t c = 0, d = 0;
char *e = NULL, *new_e = NULL, *f;

e = *ptr;
if (e && len)
d = *len;
if (a == len1)
a = len1 = 0;

c = _rbuffer(ss_info, buffer, &len1);
if (c == -1 || (c == 0 && len1 == 0))
return (-1);

f = _strchr(buffer + a, '\n');
b = f ? 1 + (unsigned int)(f - buffer) : len1;
new_e = _realloc(e, d, d ? d + b : b + 1);
if (!new_e)
return (e ? free(e), -1 : -1);

if (d)
_strncat(new_e, buffer + a, b - a);
else
_strncpy(new_e, buffer + a, b - a + 1);

d += b - a;
a = b;
e = new_e;

if (len)
*len = d;
*ptr = e;
return (d);
}

/**
 * _clear_shell - clear shell state
 * @ss_info: simpleshell struct param
 * @all: true if all fields are freed
 * Return: Nothing
*/
void _clear_shell(ss_t *ss_info, int all)
{
_free_str(ss_info->argv);
ss_info->argv = NULL;
ss_info->cmd_path = NULL;

if (all)
{
if (!ss_info->cmd_buffer)
free(ss_info->arg);
if (ss_info->env)
free_list(&(ss_info->env));
if (ss_info->hist)
free_list(&(ss_info->hist));
if (ss_info->_alias)
free_list(&(ss_info->_alias));

_free_str(ss_info->environ);
ss_info->environ = NULL;
_free_ptr((void **)ss_info->cmd_buffer);
if (ss_info->rfd > 2)
close(ss_info->rfd);
_putchar(-1);
}
}

/**
 * _append_node - adds a node to end of list
 * @h: ptr to head node
 * @str: string
 * @num: node index
 * Return: ptr to newly added node at end of linked list,
 * NULL (Error)
*/
list_t *_append_node(list_t **h, const char *str, int num)
{
list_t *nn = malloc(sizeof(list_t)), *n  = *h;

if (!h)
return (NULL);

if (!nn)
return (NULL);
_memset((void *)nn, 0, sizeof(list_t));
nn->number = num;
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
while (n->next)
n = n->next;
n->next = nn;
}
else
*h = nn;
return (nn);
}

/**
 * del_node_ind - deletes node at index
 * @h: ptr to first node
 * @ind: index
 * Return: 1 (Success), 0 (Otherwise)
*/
int del_node_ind(list_t **h, unsigned int ind)
{
list_t *n, *pn;
unsigned int a = 0;

if (!h || !*h)
return (0);

if (!ind)
{
n = *h;
*h = (*h)->next;
free(n->str);
free(n);
return (1);
}
n = *h;
for (a = 0; n; a++)
{
if (a == ind)
{
pn->next = n->next;
free(n->str);
free(n);
return (1);
}
pn = n;
n = n->next;
}
return (0);
}

/**
 * push_node - adds node to start of list
 * @h: ptr to head node
 * @str: string field
 * @num: node index
 * Return: size of list
*/
list_t *push_node(list_t **h, const char *str, int num)
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
nh->str = _strdup(str);
if (!nh->str)
{
free(nh);
return (NULL);
}
}
nh->next = *h;
*h = nh;
return (nh);
}
