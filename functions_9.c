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

while (h)
{
if (h == n)
return (a);
h = h->next;
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
return (NULL);
if (!strarr)
return (NULL);
while (a = 0; n; n = n->next, a++)
{
str = malloc(_strlen(n->string) + 1);
if (!str)
{
for (b = 0; b < a; b++)
free(strarr[b]);
free(strarr);
return (NULL);
}

str = _strcpy(str, n->string);
strarr[a] = str;
}
strarr[a] = NULL;
return (strarr);
}

/**
 * _apnd_hist_list - adds entry to hist list.
 * @ss_info: simpleshell_t struct param.
 * @buffer: the buffer.
 * @histcount: history line count.
 * Return: 0 (Always)
*/
int _apnd_hist_list(simpleshell_t *ss_info, char *buffer, int histcount)
{
list_t *n = NULL;

if (ss_info->cmd_hist)
n = ss_info->cmd_hist;
_append_node(&n, buffer, histcount);

if (!ss_info->cmd_hist)
ss_info->cmd_hist = n;
return (0);
}

/**
 * _histfile - gets the history file
 * @ss_info: simpleshell_t struct param
 * Return: allocated string containing history file
 */
char *_histfile(simpleshell_t *ss_info)
{
char *buffer, *home_dir = _envval(ss_info, "SS_HOME=");

if (!home_dir)
return (NULL);
buffer = malloc(sizeof(char) * (_strlen(home_dir) +
_strlen(".ss_history") + 2));
if (!buffer)
return (NULL);
buffer[0] = 0;
_strcpy(buffer, home_dir);
_strcat(buffer, "/");
_strcat(buffer, ".ss_history");
return (buffer);
}

/**
 * _w_hist - creates a file, or appends to
 * an existing file
 * @ss_info: simpleshell_t struct param
 * Return: 1 (Success), -1 (Otherwise)
 */
int _w_hist(simpleshell_t *ss_info)
{
char *fname = _histfile(ss_info);
ssize_t fd = open(fname, O_CREAT | O_TRUNC | O_RDWR, 0644);
list_t *n = NULL;

if (!fname)
return (-1);

free(fname);
if (fd == -1)
return (-1);
for (n = ss_info->cmd_hist; n; n = n->next)
{
_wsfd(n->string, fd);
_wcfd('\n', fd);
}
_wcfd(-1, fd);
close(fd);
return (1);
}
