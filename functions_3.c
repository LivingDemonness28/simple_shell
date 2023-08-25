#include "simpleshell.h"

/**
* _decimalfd - prints a decimal (integer) num (base 10)
* to a file descriptor.
* @num: input integer.
* @fd: file descriptor.
* Return: num of chars printed.
*/
int _decimalfd(int num, int fd)
{
int (*__putchar)(char) = _putchar;
int a, total = 0;
unsigned int abs_val, curr_dig;

if (fd == STDERR_FILENO)
{
__putchar = _w_stderr;
}

if (num < 0)
{
abs_val = -num;
__putchar('-');
total++;
}
else
{
abs_val = num;
}

curr_dig = abs_val;
a = 1000000000;
while (a > 1)
{
if (abs_val / a)
{
__putchar('0' + curr_dig / a);
total++;
}

curr_dig %= a;
a /= 10;
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

while (buffer[a] != '\0')
{
if (buffer[a] == '#' && (!a || buffer[a - 1] == ' '))
{
buffer[a] = '\0';
break;
}
a++;
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
_w_str_stderr(ss_info->filename);
_w_str_stderr(": ");
_decimalfd(ss_info->line_num, STDERR_FILENO);
_w_str_stderr(": ");
_w_str_stderr(ss_info->av[0]);
_w_str_stderr(": ");
_w_str_stderr(str);
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
char *dup;
int length = 0, i;

if (str == NULL)
{
return (NULL);
}

while (str[length] != '\0')
{
length++;
}

dup = malloc(sizeof(char) * (length + 1));

if (dup == NULL)
{
return (NULL);
}

for (i = 0; i <= length; i++)
{
dup[i] = str[i];
}
return (dup);
}
