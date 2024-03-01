#include "simpleshell.h"

/**
 * _shellExit - exit the shell
 * @ss_info: simpleshell struct param
 * Return: exit with exit status
*/
int _shellExit(ss_t *ss_info)
{
int _echeck;

if (ss_info->argv[1])
{
_echeck = _eatoi(ss_info->argv[1]);
if (_echeck == -1)
{
ss_info->status = 2;
_eprint(ss_info, "Illegal number: ");
_eputs(ss_info->argv[1]);
_eputchar('\n');
return (1);
}
ss_info->errnum = _eatoi(ss_info->argv[1]);
return (-2);
}
ss_info->errnum = -1;
return (-2);
}

/**
 * _repalias - replaces alias in tokenised string
 * @ss_info: simpleshell struct param
 * Return: 1 (Success), 0 (Otherwise)
*/
int _repalias(ss_t *ss_info)
{
int a = 0;
list_t *n;
char *p;

while (a < 10)
{
n = _pre_node(ss_info->_alias, ss_info->argv[0], '=');
if (!n)
return (0);
free(ss_info->argv[0]);
p = _strchr(n->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
ss_info->argv[0] = p;
a++;
}
return (1);
}

/**
 * _repvars - replaces var in tokenised string
 * @ss_info: simpleshell struct param
 * Return: 1 (Success), 0 (Otherwise)
*/
int _repvars(ss_t *ss_info)
{
int a = 0;
list_t *n;

while (ss_info->argv[a])
{
if (ss_info->argv[a][0] != '$' || !ss_info->argv[a][1])
continue;

if (!_strcmp(ss_info->argv[a], "$?"))
{
_repstr(&(ss_info->argv[a]),
_strdup(_itoa(ss_info->status, 10, 0)));
continue;
}
if (!_strcmp(ss_info->argv[a], "$$"))
{
_repstr(&(ss_info->argv[a]),
_strdup(_itoa(getpid(), 10, 0)));
continue;
}
n = _pre_node(ss_info->env, &ss_info->argv[a][1], '=');
if (n)
{
_repstr(&(ss_info->argv[a]),
_strdup(_strchr(n->str, '=') + 1));
continue;
}
_repstr(&ss_info->argv[a], _strdup(""));
a++;
}
return (0);
}

/**
 * _free_ptr - frees a pointer
 * @ptr: pointer
 * Return: 1 (Success), 0 (Otherwise)
*/
int _free_ptr(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}

/**
 * _strncat - concats two strings.
 * @dest: the first string.
 * @src: the second string.
 * @max_num: max num of chars to be used from source string.
 * Return: concat string.
*/
char *_strncat(char *dest, char *src, int max_num)
{
int a = 0, b = 0;
char *res = dest;

while (dest[a] != '\0')
a++;
while (src[a] != '\0' && b < max_num)
{
dest[a] = src[b];
a++;
b++;
}
if (b < max_num)
dest[a] = '\0';
return (res);
}
