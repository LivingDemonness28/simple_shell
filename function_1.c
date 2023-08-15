#include "simpleshell.h"

/**
 * _strncat - concatenate two strings
 * using at most n bytes from src
 * @dest: input value
 * @src: input value
 * @n: input value
 * Return: dest
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
