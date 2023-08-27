#include "simpleshell.h"

/**
 * _strchr - finds a character in a string.
 * @str: string to be searched.
 * @c: character to locate.
 * Return: a pointer to the first character of
 * c in str (Success), NULL (Otherwise)
*/
char *_strchr(char *str, char c)
{
while (*str++ != '\0')
{
if (*str == c)
return (str);
}
return (NULL);
}

/**
* _wcstderr - writes the char c to standard error.
* @c: The character
* Return: 1 (Success), -1 (Otherwise).
*/
int _wcstderr(char c)
{
static int a;
static char buffer[WBS];

if (c == BF || a >= WBS)
{
write(2, buffer, a);
a = 0;
}
if (c != BF)
buffer[a++] = c;
return (1);
}

/**
* _wsstderr - writes the string to standard error.
* @str: the string.
* Return: Nothing.
*/
void _wsstderr(char *str)
{
int a = 0;

if (!str)
return;
while (str[a] != '\0')
{
_wcstderr(str[a]);
a++;
}
}

/**
* _wcfd - writes the c to given fd.
* @c: the char.
* @fd: file descriptor.
* Return: 1 (Success), 0 (Otherwise).
*/
int _wcfd(char c, int fd)
{
static int a;
static char buffer[WBS];

if (c == BF || a >= WBS)
{
write(fd, buffer, a);
a = 0;
}
if (c != BF)
buffer[a++] = c;
return (1);
}

/**
* _wsfd - writes str to given fd.
* @str: the string.
* @fd: file descriptor.
* Return: num of chars written to fd.
*/
int _wsfd(char *str, int fd)
{
int a = 0;

if (!str)
return (0);
while (*str)
{
a += _wcfd(*str++, fd);
}
return (a);
}
