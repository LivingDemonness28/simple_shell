#include <stddef.h>

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
