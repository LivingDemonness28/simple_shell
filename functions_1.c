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
int _interact(ss_t *ss_info)
{
return (isatty(STDIN_FILENO) && ss_info->rfd <= 2);
}

/**
 * _isalpha - checks for alpha character
 * @c: char
 * Return: 1 (Alphabetic char), 0 (Otherwise)
*/
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 * _repstr - replace str
 * @o: old str
 * @n: new str
 * Return: 1 (Replaced)
*/
int _repstr(char **o, char *n)
{
free(*o);
*o = n;
return (1);
}

/**
 * _chain - check if continue chaining
 * based on last status
 * @ss_info: simpleshell struct param
 * @buf: buffer
 * @pos: current buffer position
 * @a: starting pos
 * @len: buffer length
 * Return: Nothing
*/
void _chain(ss_t *ss_info, char *buf, size_t *pos, size_t a, size_t len)
{
size_t b = *pos;

if (ss_info->cmd_b_type == 2)
{
if (ss_info->status)
{
buf[a] = 0;
b = len;
}
}
if (ss_info->cmd_b_type == 1)
{
if (!ss_info->status)
{
buf[a] = 0;
b = len;
}
}
*pos = b;
}
