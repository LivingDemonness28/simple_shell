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

/**
 * _strtow_1 - splits a string into words.
 * Repeated delimiters are ignored.
 * @str: input string.
 * @del: delimiter string.
 * Return: ptr to arr of str (Success), NULL (Otherwise).
*/
char **strtow_1(char *str, char *del)
{
int a = 0, b = 0, c, d, word_count = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);

if (!del)
del = " ";

while (str[a] != '\0')
{
if (!_check_del(str[a], del) && (_check_del(str[a + 1], del) || !str[a + 1]))
word_count++;
a++;
}

if (word_count == 0)
return (NULL);

s = malloc((1 + word_count) * sizeof(char *));
if (!s)
return (NULL);

a = 0;
b = 0;
while (b < word_count)
{
while (_check_del(str[a], del))
a++;

c = 0;
while (!_check_del(str[a + c], del) && str[a + c])
c++;

s[b] = malloc((c + 1) * sizeof(char));
if (!s[b])
{
d = 0;
while (d < b)
{
free(s[d]);
d++;
}
free(s);
return (NULL);
}

d = 0;
while (d < c)
{
s[b][d] = str[a];
a++;
d++;
}
s[b][d] = 0;
b++;
}
s[b] = NULL;
return (s);
}

/**
 * _strtow_2 - splits a string into words.
 * @str: input string.
 * @del: delimiter string.
 * Return: ptr to arr of str (Success), NULL (Otherwise).
*/
char **_strtow_2(char *str, char del)
{
int a = 0, b = 0, c, d, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);

for (a = 0; str[a] != '\0'; a++)
{
if ((str[a] != del && str[a + 1] == del) ||
(str[a] != del && !str[a + 1]) || str[a + 1] == del)
numwords++;
}

if (numwords == 0)
return (NULL);

s = malloc((1 + numwords) * sizeof(char *));
if (!s)
return (NULL);

a = 0;
b = 0;
while (b < numwords)
{
while (str[a] == del && str[a] != del)
a++;

c = 0;
while (str[a + c] != del && str[a + c] && str[a + c] != del)
c++;

s[b] = malloc((c + 1) * sizeof(char));
if (!s[b])
{
d = 0;
while (d < b)
{
free(s[d]);
d++;
}
free(s);
return (NULL);
}

d = 0;
while (d < c)
{
s[b][d] = str[a];
a++;
d++;
}
s[b][d] = 0;
b++;
}

s[b] = NULL;
return (s);
}
