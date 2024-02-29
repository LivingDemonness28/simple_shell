#include "simpleshell.h"

/**
 * _blockCtrlC - block ctrl-c
 * @num: signal num
 * Return: Nothing
*/
void _blockCtrlC(__attribute__((unused))int num)
{
_puts("\n");
_puts("$ ")
_putchar(-1);
}

/**
 * _no_comment - first instance '#' replaced with'\0'
 * @buffer: address of string
 * Return: Nothing
*/
void _no_comment(char *buffer)
{
int a = 0;

while (buffer[a] != '\0')
{
if (buffer[a] == '#' && (!a || buffer[a - 1] == ''))
{
buffer[a] = '\0';
break;
}
a++;
}
}

/**
 * _itoa - num to string
 * @num: number
 * @b: base
 * @f: arg flags
 * Return: string
*/
char *_itoa(long int num, int b, int f)
{
static char *arr, buffer[50];
char sign = 0, *ptr;
unsigned long n = num;

if (!(f & 2) && num < 0)
{
n = -num;
sign = '-';
}
arr = f & 1 ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

while (n != 0)
{
*--ptr = arr[n % b];
n /= b;
}

if (sign)
*--ptr = sign;
return (ptr);
}

/**
 * _eputchar - writes the char c to stderr
 * @c: char
 * Return: 1 (Success), -1 (Error and erno is set appropriately)
*/
int _eputchar(char c)
{
static int a;
static char buffer[1024];

if (c == -1 || a >= 1024)
{
write(2, buffer, a);
a = 0;
}
if (c != -1)
buffer[a++] = c;
return (1);
}

/**
 * _eputs - prints input string to stderr
 * @str: string
 * Return: Nothing
*/
void _eputs(char *str)
{
int a = 0;

if (!str)
return;
for (; str[a] != '\0'; a++)
{
_eputchar(str[a]);
}
}
