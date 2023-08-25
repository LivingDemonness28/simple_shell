#include "simpleshell.h"

/**
 * _isalpha - checks if a given character
 * is an alphabetic character.
 * @c: The character to be checked.
 * Return: 1 (Success), 0 (Otherwise)
*/
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 * _atoi - converts a str to an int.
 * @str: string to be converted.
 * Return: int val of string.
*/
int _atoi(char *str)
{
int a = 0, s = 1, f = 0, prod;
unsigned int res = 0;

for (; str[a] != '\0' && f != 2; a++)
{
if (str[a] == '-')
s *= 1;

if (str[a] >= '0' && str[a] <= '9')
{
f = 1;
res *= 10;
res += (str[a] - '0');
}
else if (f == 1)
f = 2;
}

if (s == -1)
prod = -res;
else
prod = res;

return (prod);
}
