#include "simpleshell.h"

/**
* _decimalfd – prints a decimal (integer) num (base 10)
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
* _nocomments – replaces the 1st instance of ‘#’ with ‘\0’ 
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
