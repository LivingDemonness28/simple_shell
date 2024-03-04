#include "simpleshell.h"

/**
 * _starts - needles starts with haystack
 * @h: string
 * @n: substring
 * Return: address of next char or NULL
*/
char *_starts(const char *h, const char *n)
{
while (*n)
if (*n++ != *h++)
return (NULL);
return ((char *)h);
}

/**
 * _strcmp - lexicogarphic comparison of two strings
 * @str1: first string
 * @str2: second string
 * Return: str1 < str2 (neg), str1 > str2 (pos), str1 == str2 (zero)
*/
int _strcmp(char *str1, char *str2)
{
while (*str1 && *str2)
{
if (*str1 != *str2)
return (*str1 - *str2);
str1++;
str2++;
}
if (*str1 == *str2)
return (0);
else
return (*str1 < *str2 ? -1 : 1);
}

/**
 * _strcat - concats two strings
 * @dest: destination buffer
 * @src: source buffer
 * Return: ptr to dest buffer
*/
char *_strcat(char *dest, char *src)
{
char *rets = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (rets);
}

/**
 * _strlen - length of string
 * @str: string
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

/**
 * _memset - fill mem with constant byte
 * @s: ptr to the mem area
 * @b: byte
 * @n: byte amount
 * Return: s (ptr to mem area)
*/
char *_memset(char *s, char b, unsigned int n)
{
unsigned int a = 0;

for (; a < n; a++)
s[a] = b;
return (s);
}
