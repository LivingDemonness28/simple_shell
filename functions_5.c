#include "simpleshell.h"

/**
 * _strncpy - copy a string
 * @dest: input value
 * @src: input value
 * @n: input value
 * Return: dest
*/
char *_strncpy(char *dest, char *src, int n)
{
int j = 0;
while (j < n && src[j] != '\0')
{
dest[j] = src[j];
j++;
}

while (j < n)
{
dest[j] = '\0';
j++;
}
return (dest);
}

/**
 * _alias - displays an alias string.
 * @an: alias node
 * Return: 0 (Success), 1 (Otherwise)
*/
int _alias(list_t *an)
{
char *equal_sign = NULL, *astr = NULL;

if (an)
{
equal_sign = _strchr(an->string, '=');
while (astr <= equal_sign)
{
_putchar(*astr);
astr++;
}
_putchar('\'');
_puts(equal_sign + 1);
_puts("'\n");
return (0);
}
return (1);
}
