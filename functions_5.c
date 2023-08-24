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
 * _dis_alias - displays an alias string.
 * @an: alias node
 * Return: 0 (Success), 1 (Otherwise)
*/
int _dis_alias(list_t *an)
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
{
str++;
}

while (str[a] != '\0')
{
if (str[a] >= '0' && str[a] <= '9')
{
res *= 10;
res += (str[a] - '0');
if (res > INT_MAX)
{
return (-1);
}
}
else
{
return (-1);
}
a++;
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

while (a < n)
{
s[a] = b;
a++;
}

return (s);
}

/**
 * *_realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previsouly allocated by malloc
 * @old_size: size of the allocated memory for ptr
 * @new_size: new size of the new memory block
 * Return: pointer to the newly allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p1, *op;
unsigned int i;

if (new_size == old_size)
return (ptr);

if (new_size == 0 && ptr)
{
free(ptr);
return (NULL);
}

if (!ptr)
return (malloc(new_size));

p1 = malloc(new_size);
if (!p1)
return (NULL);

op = ptr;

if (new_size < old_size)
{
for (i = 0; i < new_size; i++)
p1[i] = op[i];
}
if (new_size > old_size)
{
for (i = 0; i < old_size; i++)
p1[i] = op[i];
}
free(ptr);
return (p1);
}
