#include "simpleshell.h"

/**
 * main - entry point
 * @argc: argument count.
 * @argv: argument vector.
 * Return: 0 (Success), 1 (Otherwise)
*/
int main(int argc, char **argv)
{
simpleshell_t ss_info[] = { EMPTY_INFO_INIT };
int fd = 2;

asm ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (fd)
: "r" (fd));

if (argc == 2)
{
fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_wsstderr(argv[0]);
_wsstderr(": 0: Can't open ");
_wsstderr(argv[1]);
_wcstderr('\n');
_wcstderr(-1);
exit(127);
}
return (EXIT_FAILURE);
}
ss_info->rfd = fd;
}
_init_env_list(ss_info);
_r_hist(ss_info);
_exe_shell(ss_info, argv);
return (EXIT_SUCCESS);
}
