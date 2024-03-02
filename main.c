#include "simpleshell.h"

/**
 * main - entry point
 * @ac: arguement count
 * @av: arguement vector
 * Return: 0 (Success), 1 (Error)
*/
int main(int ac, char **av)
{
ss_t info[] = { II };
int fd = 2;

asm = ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (fd)
: "r" (fd));

if (ac == 2)
{
fd = open(av[1], O_RDONLY);
if (fd == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_eputs(av[0]);
_eputs(": 0: Can't open ");
_eputs(av[1]);
_eputchar('\n');
_eputchar(-1);
exit(127);
}
return (EXIT_FAILURE);
}
ss_info->rfd = fd;
}
_fill_env_list(ss_info);
_rhist(ss_info);
hsh(ss_info, av);
return (EXIT_SUCCESS);
}
