#include "simpleshell.h"

/**
* _strncat – concatenate two strings
* using at most n bytes from src
* @dest: destination string where the result will be stored
* @src: the source string to be appended to the destination string.
* @n: the maximum number of bytes from src to concatenate.
* Return: A pointer to the resulting concatenated string (dest).
*/
char *_strncat(char *dest, char *src, int n)
{
int i = 0, j = 0;

while (dest[i] != '\0')
i++;

for (; j < n && src[j] != '\0'; i++, j++)
{
dest[i] = src[j];
}
dest[i] = '\0';
return (dest);
}

/**
* _check_del – checks if a char is delimiter.
* ch: character check.
* del_str: delimiter string.
* Return: 1 (Success), 0 (Otherwise)
*/
int _check_del(char ch, char *del_str)
{
for (; *del_str != '\0'; del_str++)
{
if (*del_str == ch)
{
return (1);
}
}
return (0);
}
