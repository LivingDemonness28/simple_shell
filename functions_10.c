#include "simpleshell.h"

/**
 * _r_hist - reads history from file
 * @ss_info: simpleshell_t struct param.
 * Return: histcount (Success), 0 (Otherwise)
 */
int _r_hist(simpleshell_t *ss_info)
{
int a, last_index = 0, histcount = 0;
ssize_t fd, rdlen, fsize = 0;
struct stat st;
char *buffer = NULL, *filename = _histfile(ss_info);

if (!filename)
return (0);

fd = open(filename, O_RDONLY);
free(filename);
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
a = 0;
while (a < fsize)
{
if (buffer[a] == '\n')
{
buffer[a] = 0;
_apnd_hist_list(ss_info, buffer + last_index, histcount++);
last_index = a + 1;
}
a++;
}

if (last_index != a)
_apnd_hist_list(ss_info, buffer + last_index, histcount++);

free(buffer);
ss_info->history_count = histcount;

while (ss_info->history_count-- >= 4096)
_del_node_at_ind(&(ss_info->cmd_hist), 0);

_updt_hist(ss_info);
return (ss_info->history_count);
}
