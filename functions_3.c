#include "simpleshell.h"

/**
* _dprint - prints a decimal (integer) num (base 10)
* to a file descriptor.
* @num: input integer.
* @fd: file descriptor.
* Return: num of chars printed.
*/
int _dprint(int num, int fd)
{
int (*__putchar)(char) = _putchar;
int a, total = 0;
unsigned int abs_val, curr_dig;

if (fd == STDERR_FILENO)
__putchar = _wcstderr;
if (num < 0)
{
abs_val = -num;
__putchar('-');
total++;
}
else
abs_val = num;
curr_dig = abs_val;
for (a = 1000000000; a > 1; a /= 10)
{
if (abs_val / a)
{
__putchar('0' + curr_dig / a);
total++;
}
curr_dig %= a;
}
__putchar('0' + curr_dig);
total++;

return (total);
}

/**
* _nocomments - replaces the 1st instance of ‘#’ with ‘\0’
* @buffer: string address to modify.
* Return: Nothing.
*/
void _nocomments(char *buffer)
{
int a = 0;

for (; buffer[a] != '\0'; a++)
if (buffer[a] == '#' && (!a || buffer[a - 1] == ' '))
{
buffer[a] = '\0';
break;
}
}

/**
 * _eprint - prints error message along with
 * file, line and program information.
 * @ss_info: simpleshell_t struct param.
 * @str: error string.
 * Return: Nothing.
*/
void _eprint(simpleshell_t *ss_info, char *str)
{
_wsstderr(ss_info->filename);
_wsstderr(": ");
_dprint(ss_info->line_num, STDERR_FILENO);
_wsstderr(": ");
_wsstderr(ss_info->av[0]);
_wsstderr(": ");
_wsstderr(str);
}

/**
 * _puts - prints input str.
 * @str: str to print.
 * Return: Nothing.
*/
void _puts(char *str)
{
int a = 0;

if (!str)
return;
while (str[a] != '\0')
{
_putchar(str[a]);
a++;
}
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 * Return: pointer to the duplicated string,
 * or NULL if insufficient memory
 */
char *_strdup(const char *str)
{
int length = 0;
char *dup;

if (str == NULL)
return (NULL);
while (*str++)
length++;
dup = malloc(sizeof(char) * (length + 1));
if (!dup)
return (NULL);
for (length++; length--;)
dup[length] = *--str;
return (dup);
}
