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
while(*n)
if (*n++ != *h++)
return (NULL);

return ((char *)h);
}

/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 * Return: s1 < s2 (Neg), s1 > s2 (Pos), s1 == s2 (0)
*/
int _strcmp(char *s1, char *s2)
{
int i = 0;

while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] != s2[i])
{
return (s1[i] - s2[i]);
}
i++;
}
return (0);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *str)
{
int a = 0;

if (!str)
return (0);

while (*str++)
a++;
return (a);
}
