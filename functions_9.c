#include "simpleshell.h"

/**
 * _eprint - print error message
 * @ss_info: simpleshell struct param
 * @estr: string
 * Return: 0 (no numbers),
 * converted number (Otherwise), -1 (error)
*/
void _eprint(ss_t *ss_info, char *estr)
{
_eputs(ss_info->filename);
_eputs(": ");
print_dec(ss_info->linecount, STDERR_FILENO);
_eputs(": ");
_eputs(ss_info->argv[0]);
_eputs(": ");
_eputs(estr);
}

/**
 * print_alias - print alias string
 * @n: alias node
 * Return: 0 (Success), 1 (Error)
*/
int print_alias(list_t *n)
{
char *p = NULL, *a = NULL;

if (n)
{
p = _strchr(n->str, '=');
for (a = n->str; a <= p; a++)
_putchar(*a);
_putchar('\'');
_puts(p + 1);
_puts("\n");
return (0);
}
return (1);
}

/**
 * _eatoi - convert string to an int
 * @s: string
 * Return: 0 (no num in str),
 * converted num (Otherwise), -1 (Error)
*/
int _eatoi(char *s)
{
int a = 0;
unsigned long int res = 0;

if (*s == '+')
s++;
for (; s[a] != '\0'; a++)
{
if (s[a] >= '0' && s[a] <= 9)
{
res *= 10;
res += (s[a] - '0');
if (res > INT_MAX)
return (-1);
}
else
return (-1);
}
return (res);
}

/**
 * clear_info - initiliazes ss_t struct
 * @ss_info: simpleshell struct param
 * Return: Nothing
*/
void clear_info(ss_t *ss_info)
{
ss_info->arg = NULL;
ss_info->argv = NULL;
ss_info->cmd_path = NULL;
ss_info->argc = 0;
}

/**
 * _rbuffer - reads a buffer
 * @ss_info: simpleshell struct param
 * @buf: buffer
 * @a: size
 * Return: r
*/
ssize_t _rbuffer(ss_t *ss_info, char *buf, size_t *a)
{
ssize_t r = 0;

if (*a)
return (0);
r = read(ss_info->rfd, buf, 1024);
if (r >= 0)
*a = r;
return (r);
}
