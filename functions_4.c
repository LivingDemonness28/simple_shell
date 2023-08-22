#include “simpleshell.h”

/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
int len = 0, i = 0;

while (src[len] != '\0')
{
len++;
}

for (; i < len; i++)
{
dest[i] = src[i];
}
dest[i] = '\0';

return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
*/
char *_strcat(char *dest, char *src)
{
int i = 0, j = 0;

while (dest[i] != '\0')
{
i++;
}

while (src[j] != '\0')
{
dest[i] = src[j];
i++;
j++;
}
dest[i] = '\0';
return (dest);
}

/**
 * _starts - check if string starts with substring.
 * @h: search string.
 * @n: substring.
 * Return: Address of next char (Success), NULL (Otherwise).
*/
char *_starts(const char *h, const char *n)
{
for (; *n != '\0'; n++, h++)
{
if (*n != *h)
{
return (NULL);
}
}
return ((char *)h);
}
