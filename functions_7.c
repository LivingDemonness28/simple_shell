#include "simpleshell.h"

/**
 * _chain_del - checks if the current char in the buffer
 * is a chain delimiter
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

/**
 * _reset_info - initializes simpleshell_t struct by
 * clearing its members.
 * @ss_info: simpleshell_t struct param.
 * Return: Nothing.
*/
void _reset_info(simpleshell_t *ss_info)
{
ss_info->input_args = NULL;
ss_info->av = NULL;
ss_info->cmd_path = NULL;
ss_info->ac = 0;
}

/**
 * _updt_hist - updates the hist index in a
 * linked list.
 * @ss_info: simpleshell_t struct param.
 * Return: the new hist count.
*/
int _updt_hist(simpleshell_t *ss_info)
{
list_t *n = ss_info->cmd_hist;
int a = 0;

for (; n; n = n->next)
{
n->number = a++;
}
return (ss_info->history_count = a);
}
