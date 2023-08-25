#include "simpleshell.h"

/**
 * _r_hist - reads history from file
 * @ss_info: simpleshell_t struct param.
 * Return: histcount (Success), 0 (Otherwise)
 */
int _r_hist(simpleshell_t *ss_info)
{
int a, last_index = 0, histcount = 0;
struct stat st;
char *buffer = NULL, *filename = _histfile(ss_info);
ssize_t fd = open(filename, O_RDONLY), rdlen, fsize = 0;

if (!filename)
return (0);

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
for (a = 0; a < fsize; a++)
{
if (buffer[a] == '\n')
{
buffer[a] = 0;
_apnd_hist_list(ss_info, buffer + last_index, histcount++);
last_index = a + 1;
}
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
char **_strtow_1(char *str, char *del)
{
int a = 0, b = 0, c, d, count_words = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
if (!del)
del = " ";
for (; str[a] != '\0'; a++)
if (!_del(str[a], del) && (_del(str[a + 1], del) || !str[a + 1]))
count_words++;

if (count_words == 0)
return (NULL);
s = malloc((1 + count_words) *sizeof(char *));
if (!s)
return (NULL);
for (a = 0, b = 0; b < count_words; b++)
{
while (_check_del(str[a], del))
a++;
c = 0;
while (!_check_del(str[a + c], del) && str[a + c])
c++;
s[b] = malloc((c + 1) * sizeof(char));
if (!s[b])
{
for (c = 0; c < b; c++)
free(s[c]);
free(s);
return (NULL);
}
for (d = 0; d < c; d++)
s[b][d] = str[a++];
s[b][d] = 0;
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
int a, b, c, d, count_words = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);

for (a = 0; str[a] != '\0'; a++)
if ((str[a] != del && str[a + 1] == del) ||
(str[a] != del && !str[a + 1]) || str[a + 1] == del)
count_words++;

if (count_words == 0)
return (NULL);

s = malloc((1 + count_words) *sizeof(char *));
if (!s)
return (NULL);

for (a = 0, b = 0; b < count_words; b++)
{
while (str[a] == del && str[a] != del)
a++;

for (c = 0; str[a + c] != del && str[a + c] && str[a + c] != del; c++)
;

s[b] = malloc((c + 1) * sizeof(char));
if (!s[b])
{
for (c = 0; c < b; c++)
free(s[c]);
free(s);
return (NULL);
}
for (d = 0; d < c; d++)
s[b][d] = str[a++];
s[b][d] = 0;
}
s[b] = NULL;
return (s);
}

/**
 * _currenv - print current env
 * @ss_info: simpleshell_t struct param.
 * Return: 0 (Always)
*/
int _currenv(simpleshell_t *ss_info)
{
_print_str_ele(ss_info->local_env_list);
return (0);
}

/**
 * _init_env_list - fills an env linked list with vals.
 * @ss_info: simpleshell_t struct param.
 * Return: 0 (Always)
*/
int _init_env_list(simpleshell_t *ss_info)
{
list_t *n = NULL;
size_t a = 0;

while (environ[a])
{
_append_node(&n, environ[a], 0);
a++;
}
ss_info->local_env_list = n;
return (0);
}
