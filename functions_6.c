#include "simpleshell.h"

/**
 * _free_strarr - frees string array
 * @strarr: string array
 * Return: Nothing
*/
void _free_strarr(char **strarr)
{
char **curr_ptr = strarr;

if (!strarr)
return;

for (; *strarr; strarr++)
{
free(*strarr);
}
free(curr_ptr);
}
