#include "simpleshell.h"

/**
 * _realloc - reallocate block of mem
 * @ptr: ptr to previous block
 * @os: size of previous block
 * @ns: size of new block
 * Return: ptr to old block name
*/
void *_realloc(void *ptr, unsigned int os, unsigned int ns)
{
char *p = malloc(ns);

if (!ptr)
return (malloc(ns));
if (!ns)
return (free(ptr), NULL)
if (ns == os)
return (ptr);

if (!p)
return (NULL);

os = os < ns ? os : ns;
while (os--)
p[os] = ((char *)ptr)[os];
free(ptr);
return (p);
}

/**
 * _free_str - frees arr of strings
 * @arr: arr of strings
 * Return: Nothing
*/
void _free_str(char **arr)
{
char **op = arr;

if (!arr)
return;
while (*arr)
free(*arr++);
free(op);
}

/**
 * exe_path - searches for executable path of cmd
 * in given path str
 * @ss_info: simpleshell struct param
 * @pstr: string
 * @cmd: command
 * Return: ptr to full path of exe (Success), NULL (Otherwise)
*/
char *exe_path(ss_t *ss_info, char *pstr, char *cmd)
{
char *path;
int a = 0, pos = 0;

if (!pstr)
return (NULL);
if ((_strlen(cmd) > 2) && _starts(cmd, "./"))
{
if (_cmd(ss_info, cmd))
return (cmd);
}
for (; 1; a++)
{
if (!pstr[a] || pstr[a] == ':')
{
path = dup_chars(pstr, pos, a);
if (!*path)
_strcat(path, cmd);
else
{
_strcat(path, "/");
_strcat(path, cmd);
}
if (_cmd(ss_info, path))
return (path);
if (!pstr[a])
break;
pos = a;
}
}
return (NULL);
}

/**
 * list_str - returns arr of str of the list->str
 * @h: ptr to first node
 * Return: str arr
*/
char **list_str(list_t *h)
{
list_t *n = h;
size_t a = _list_len(h), b;
char **strs = malloc(sizeof(char *) * (a + 1)), *str;

if (!h || !a)
return (NULL);
if (!strs)
return (NULL);
for (a = 0; n; n = n->next, a++)
{
str = malloc(_strlen(n->str) + 1);
if (!str)
[
for (b = 0; b < a; b++)
free(strs[b]);
free(strs);
return (NULL);
]

str = _strcpy(str, n->str);
strs[a] = str;
}
strs[a] = NULL;
return (strs);
}

/**
 * load_env - return str arr copy of environ
 * @ss_info: simpleshell struct param
 * Return: ptr to arr of env var
*/
char **load_env(ss_t *ss_info)
{
if (!ss_info->environ || ss_info->env_changed)
{
ss_info->environ = list_str(ss_info->env);
ss_info->env_changed = 0;
}

return (ss_info->environ);
}
