#include "simpleshell.h"

/**
* _strchr – finds a character in a string.
* @str: string to be searched.
* @c: character to locate.
* Return: a pointer to the first occurrence of c in str (Success). NULL (Otherwise)
*/
char *_strchr(char *str, char c)
{
for (; *s != '\0'; s++)
{
if (*s == c)
return (s);
}
return (NULL);
}

/**
* _w_stderr – writes the char c to standard error.
* @c: The character
* Return: 1 (Success), -1 (Otherwise).
*/
int _w_stderr(char c)
{
static int a;
static char buffer[1024];

if (c == -1 || a >= 1024)
{
write(2, buffer, a);
a = 0;
}
if (c != -1)
buffer[a++] = c;

return (1);
}

/**
* _w_str_stdder – writes the string to standard error.
* @str: the string.
* Return: Nothing.
*/
void _w_str_stderr(char *str)
{
int a = 0;

if (!str)
return;

for (; str[a] != '\0'; a++)
{
_w_stderr(str[a]);
}
}
