#include "simpleshell.h"

/**
 * _r_line - reads a line from the input and
 * appends it to the provided buffer.
 * @ss_info: simpleshell_t struct param.
 * @pointer: pointer to buffer.
 * @curr_len: current length of buffer.
 * Return: num of chars read and new line (Success), -1 (Otherwise)
*/
int _r_line(simpleshell_t *ss_info, char **pointer, size_t *curr_len)
{
static char buffer[1024];
static size_t a, length;
size_t b;
ssize_t d = _r_buffer(ss_info, buffer, &length), e = 0;
char *f = f = *pointer, *np = NULL, *c;

if (f && curr_len)
e = *curr_len;
if (a == length)
a = length = 0;

if (d == -1 || (d == 0 && length == 0))
return (-1);

c = _strchr(buffer + a, '\n');
b = c ? 1 + (unsigned int)(c - buffer) : length;
np = _realloc(f, e, e ? e + b : b + 1);
if (!np)
return (f ? free(f), -1 : -1);

if (e)
_strncat(np, buffer + a, b - a);
else
_strncpy(np, buffer + a, b - a + 1);

e += b - a;
a = b;
f = np;

if (curr_len)
*curr_len = e;
*pointer = f;
return (e);
}

/**
 * _updt_cd = changes current directory
 * @ss_info: simpleshell_t struct param.
 * Return: 0 (Always)
*/
int _updt_cd(simpleshell_t *ss_info)
int _mycd(simpleshell_t *ss_info)
{
char *path = getcwd(buffer, 1024), *tar_dir, buffer[1024];
int res;

if (!path)
_puts("Error: Unable to retrieve current directory.\n");

if (!ss_info->av[1])
{
tar_dir = _envval(ss_info, "SS_HOME=");
if (!tar_dir)
res = chdir((tar_dir = _envval(ss_info, "SS_PWD=")) ? tar_dir : "/");
else
res = chdir(tar_dir);
}
else if (_strcmp(ss_info->av[1], "-") == 0)
{
if (!_envval(ss_info, "SS_OLDPWD="))
{
_puts(path);
_putchar('\n');
return (1);
}
_puts(_envval(ss_info, "SS_OLDPWD="));
_putchar('\n');
res = chdir((tar_dir = _envval(ss_info, "SS_OLDPWD=")) ? tar_dir : "/");
}
else
res = chdir(ss_info->av[1]);

if (res == -1)
{
_eprint(ss_info, "can't cd to ");
_w_str_stderr(ss_info->av[1]);
_w_stderr('\n');
}
else
{
_updt_env(ss_info, "SS_OLDPWD", _envval(ss_info, "SS_PWD="));
_updt_env(ss_info, "SS_PWD", getcwd(buffer, 1024));
}
return (0);
}
