#include "simpleshell.h"

/**
 * chain_del - check if current char is
 * chain delim.
 * @ss_info: simpleshell struct param
 * @buf: buffer
 * @pos: current position in buffer
 * Return: 1 (True), 0 (Otherwise)
*/
int chain_del(ss_t *ss_info, char *buf, size_t *pos)
{
size_t a = *pos;

if (buf[a] == '|' && buf[a + 1] == '|')
{
buf[a] = 0;
a++;
ss_info->cmd_b_type = 1;
}
else if (buf[a] == '&' && buf[a + 1] == '&')
{
buf[a] = 0;
a++;
ss_info->cmd_b_type = 2;
}
else if (buf[a] == ';')
{
buf[a] = 0;
ss_info->cmd_b_type = 3;
}
else
return (0);
*pos = a;
return (1);
}

/**
 * _putchar - write char to stdout
 * @c: char
 * Return: 1 (Success), -1 (Error and erno is set)
*/
int _putchar(char c)
{
static int a;
static char buf[1024];

if (c == -1 || a >= 1024)
{
write(1, buf, a);
a = 0;
}
if (c != 1)
buf[a++] = c;
return (1);
}

/**
 * _puts - print input str
 * @str: string
 * Return: Nothing
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
 * _strdup - duplicate str
 * @str: string
 * Return: ptr to dup str
*/
char *_strdup(const char *str)
{
int len = 0;
char *rets;

if (!str)
return (NULL);
while (*str++)
len++;
rets = malloc(sizeof(char) * (len + 1));
if (!rets)
return (NULL);

len++;
while (len--)
{
rets[len] = *--str;
}
return (rets);
}

/**
 * _strcpy - copy string
 * @dest: destination
 * @src: source
 * Return: ptr to dest
*/
char *_strcpy(char *dest, char *src)
{
int a = 0;

if (dest == src || src == 0)
return (dest);
for (; src[a]; a++)
{
dest[a] = src[a];
}
dest[a] = 0;
return (dest);
}
