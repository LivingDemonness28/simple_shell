#include "simpleshell.h"

/**
 * _del - check if char is a delim
 * @c: char
 * @_del: delim string
 * Return: 1 (True), 0 (Otherwise)
*/
int _del(char c, char *_del)
{
while (*_del)
if (*_del++ == c)
return (1);
return (0);
}

/**
 * _interact - returns true if shell is interactive mode
 * @ss_info: simpleshell struct param
 * Return: 1 (True), 0 (Otherwise)
 */
int _intect(ss_t *ss_info)
{
return (isatty(STDIN_FILENO) && ss_info->rfd <= 2);
}

/**
 * _isalpha - checks for alpha character
 * @c: char
 * Return: 1 (Alphabetic char), 0 (Otherwise)
*/
int _isalpha(int c) {
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}
