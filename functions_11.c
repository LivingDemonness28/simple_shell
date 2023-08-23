#include "simpleshell.h"

/**
 * _block_ctrlc - blocks ctrl-c
 * @sn: signal number
 * Return: Nothing 
*/
_block_ctrlc(__attribute__((unused))int sn)
{
_puts("\n");
_puts("ss$ ");
_putchar(-1);
}
