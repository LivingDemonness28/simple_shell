#include "simpleshell.h"

/**
 * _hist_list - adds entry to hist list.
 * @ss_info: simpleshell struct param
 * @buf: buffer
 * @hist_lc: history linecount
 * Return: 0 (Always)
*/
int _hist_list(ss_t *ss_info, char *buf, int hist_lc)
{
list_t *n = NULL;

if (ss_info->hist)
n = ss_info->hist;
_append_node(&n, buf, hist_lc);

if (!ss_info->hist)
ss_info->hist = n;
return (0);
}

/**
 * _hist_file - get history file
 * @ss_info: simpleshell struct param
 * Return: string containing hist file
*/
char *_hist_file(ss_t *ss_info)
{
char *buffer, *dir;

dir = _getenv(ss_info, "HOME=");
if (!dir)
return (NULL);
buffer = malloc(sizeof(char) * (_strlen(dir)
+ _strlen(".simple_shell_history") + 2));
if (!buffer)
return (NULL);
buffer[0] = 0;
_strcpy(buffer, dir);
_strcat(buffer, "/");
_strcat(buffer, ".simple_shell_history");
return (buffer);
}

/**
 * _whist - create file, or append to existing file
 * @ss_info: simpleshell struct param
 * Return: 1 (Success), -1 (Otherwise)
*/
int _whist(ss_t *ss_info)
{
ssize_t fd;
char *fname = _hist_file(ss_info);
list_t *n = NULL;

if (!fname)
return (-1);

fd = open(fname, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(fname);
if (fd == -1)
return (-1);
n = ss_info->hist;
while (n)
{
_putsfd(n->str, fd);
_putfd('\n', fd);
n = n->next;
}
_putfd(-1, fd);
close(fd);
return (1);
}

/**
 * _rhist - read history file
 * @ss_info: simpleshell struct param
 * Return: histcount (Success), 0 (Otherwise)
*/
int _rhist(ss_t *ss_info)
{
int a = 0, last = 0, lc = 0;
struct stat st;
char *buffer = NULL, *fname = _hist_file(ss_info);
ssize_t fd = open(fname, O_RDONLY), rdlen, fsize = 0;

if (!fname)
return (0);

free(fname);
if (fd == -1)
return (0);
if (!fstat(fd, &st))
fsize = st.st_size;
if (fsize < 2)
return (0);
buffer = malloc(sizeof(char) * (fsize + 1));
if (!buffer)
return (0);
rdlen = read(fd, buffer, fsize);
buffer[fsize] = 0;
if (rdlen <= 0)
return (free(buffer), 0);
close(fd);
for (; a < fsize; a++)
{
if (buffer[a] == '\n')
{
buffer[a] = 0;
_hist_list(ss_info, buffer + last, lc++);
last = a + 1;
}
}
if (last != a)
_hist_list(ss_info, buffer + last, lc++);
free(buffer);
ss_info->_histline = lc;
while (ss_info->_histline-- >= 4096)
del_node_ind(&(ss_info->hist), 0);
recount_hist(ss_info);
return (ss_info->_histline);
}
/**
 * print_list - print ele in list_t linked list
 * @h: ptr to head node
 * Return: list size
*/
size_t print_list(const list_t *h)
{
size_t a = 0;

while (h)
{
_puts(_itoa(h->number, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
a++;
}
return (a);
}
