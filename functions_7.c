#include "simpleshell.h"

/**
 * _chain_del - 
 * @ss_info: simpleshell_t struct param.
 * @buffer: char buffer.
 * @pos: position in the buffer.
 * Return: 1 (Success), 0 (Otherwise)
*/
int _chain_del(simpleshell_t *ss_info, char *buffer, size_t *pos)
{
size_t a = *pos;

if (buffer[a] == '|' && buffer[a + 1] == '|')
{
buffer[a] = 0;
a++;
ss_info->cmd_type = 1;
}
else if (buffer[a] == '&' && buffer[a + 1] == '&')
{
buffer[a] = 0;
a++;
ss_info->cmd_type = 2;
}
else if (buffer[a] == ';')
{
buffer[a] = 0;
ss_info->cmd_type = 3;
}
else
return (0);

*pos = a;
return (1);
}
