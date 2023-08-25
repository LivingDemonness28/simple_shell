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
int a = 0, b;
char  *s = dest;

while (src[a] != '\0' && a < n - 1)
{
dest[a] = src[a];
a++;
}
if (a < n)
{
b = a;
while (b < n)
{
dest[b] = '\0';
b++;
}
}
return (s);
}

/**
 * _dis_alias - displays an alias string.
 * @an: alias node
 * Return: 0 (Success), 1 (Otherwise)
*/
int _dis_alias(list_t *an)
{
char *es = NULL, *astr = NULL;

if (an)
{
es = _strchr(an->string, '=');
for (astr = an->string; astr <= es; astr++)
_putchar(*astr);
_putchar('\'');
_puts(es + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
 * _eatoi - convert string to int.
 * @str: string input.
 * Return: int (Success), -1 (Otherwise)
*/
int _eatoi(char *str)
{
int a = 0;
unsigned long int res = 0;

if (*str == '+')
str++;
for (; str[a] != '\0'; a++)
{
if (str[a] >= '0' && str[a] <= '9')
{
res *= 10;
res += (str[a] - '0');
if (res > INT_MAX)
return (-1);
}
else
return (-1);
}
return (res);
}

/**
 * _memset - fill a block of memory with a specific value
 * @s: starting address of memory to be filled
 * @b: the desired value
 * @n: number of bytes to be changed
 * Return: changed array with new value for n bytes
*/
char *_memset(char *s, char b, unsigned int n)
{
unsigned int a = 0;

for (; a < n; a++)
s[a] = b;
return (s);
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previsouly allocated by malloc
 * @old_size: size of the allocated memory for ptr
 * @new_size: new size of the new memory block
 * Return: pointer to the newly allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *a = malloc(new_size);

if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);

if (!a)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
a[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (a);
}
