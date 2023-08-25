#include "simpleshell.h"

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
int a = 0;

if (dest == src || src == 0)
return (dest);
while (src[a])
{
dest[a] = src[a];
a++;
}
dest[i] = 0;
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
char *res = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (res);
}

/**
 * _starts - check if string starts with substring.
 * @h: search string.
 * @n: substring.
 * Return: Address of next char (Success), NULL (Otherwise).
*/
char *_starts(const char *h, const char *n)
{
while (*n)
if (*n++ != *h++)
return (NULL);
return ((char *)h);
}

/**
 * _strcmp - compare string values
 * @str1: input value
 * @str2: input value
 * Return: str1 < str2 (Neg), str1 > str2 (Pos),
 * str1 == str2 (0)
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
return (0)
else
return (*str1 < *str2 ? -1 : 1);
}

/**
 * _strlen - returns the length of a string
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
