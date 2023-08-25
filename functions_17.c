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
