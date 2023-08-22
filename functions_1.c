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
