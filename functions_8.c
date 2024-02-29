#include "simpleshell.h"

/**
 * _putfd - wwrite char c to fd
 * @c: char
 * @fd: file descriptor
 * Return: 1 (Success), -1 (Error, erno set appropriately)
*/
int _putfd(char c, int fd)
{
static int a;
static char buffer[1024];

if (c == -1 || a >= 1024)
{
write(fd, buffer, a);
a = 0;
}
if (c != -1)
buffer[a++] = c;
return (a);
}

/**
 * _putsfd - prints input str
 * @str: string
 * @fd: file descriptor
 * Return: number of char put
*/
int _putsfd(char *str, int fd)
{
int a = 0;

if (!str)
return (0);
while (*str)
{
a += _putfd
}
}

/**
 * _getenv - value of env var
 * @ss_info: simpleshell struct param
 * @env_var: env var name
 * Return: env var value
*/
char *_getenv(ss_t *ss_info, const char *env_var)
{
list_t *n = ss_info->env;
char *p;

for (; n; n = n->next)
{
p = _starts(n->str, env_var);
if (p && *p)
return (p);
}
return (NULL);
}

/**
 * _print_env - print current env
 * @ss_info: simpleshell struct param
 * Return: 0 (Always)
*/
int _print_env(ss_t *ss_info)
{
plist_str(ss_info->env);
return (0);
}

/**
 * print_dec - print decimal number
 * @inp: the input
 * @fd: file descriptor
 * Return: num of chars
*/
int print_dec(int inp, int fd)
{
int (*__putchar)(char) = _putchar;
int a = 1000000000, count = 0;
unsigned int _abs_, curr;

if (fd == STDERR_FILENO)
__putchar = _eputchar;
if (inp < 0)
{
_abs_ = -inp;
_putchar('-');
count++;
}
else
_abs_ = inp;
curr = _abs_;
while (a > 1)
{
if (_abs_ / a)
{
__putchar('0' + curr / a);
count++;
}
curr %= a;
}
__putchar('0' + curr);
count++;

return (count);
}
