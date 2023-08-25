#include "simpleshell.h"

/**
* _strncat - concatenate two strings
* using at most n bytes from src
* @dest: destination string where the result will be stored
* @src: the source string to be appended to the destination string.
* @n: the maximum number of bytes from src to concatenate.
* Return: A pointer to the resulting concatenated string (dest).
*/
char *_strncat(char *dest, char *src, int n)
{
int i = 0, j = 0;
char *a = dest;

while (dest[i] != '\0')
i++;
while (src[i] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (a);
}

/**
* _check_del - checks if a char is delimiter.
* @ch: character check.
* @del_str: delimiter string.
* Return: 1 (Success), 0 (Otherwise)
*/
int _del(char ch, char *del_str)
{
while (*del_str++)
{
if (*del_str == ch)
return (1);
}
return (0);
}

/**
*  _interact - true if shell is interactive mode,
* @ss_info: simpleshell_t struct param.
* Return: convert number (Success), 0 (Otherwise)
*/
int _interact(simpleshell_t *ss_info)
{
if (isatty(STDIN_FILENO))
return (isatty(STDIN_FILENO) && ss_info->rfd <= 2);
}

/**
* _repstr - replaces a string.
* @ostr: old str address.
* @nstr: new str.
* Return: 1 (Success), 0 (Otherwise)
*/
int _repstr(char **ostr, char *nstr)
{
free(*ostr);
*ostr = nstr;
return (1);
}

/**
* _putchar - writes char c to standard output.
* @c: The char.
* Return: 1 (Success), -1 (Otherwise)
*/
int _putchar(char c)
{
static int a;
static char buffer[1024];

if (c == -1 || a >= 1024)
{
write(1, buffer, a);
}
if (c != -1)
buffer[a++] = c;

return (1);
}
