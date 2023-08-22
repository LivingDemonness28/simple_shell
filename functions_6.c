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

/**
 * _r_buffer - reads data into a buffer
 * from a specified fd
 * @ss_info: simpleshell_t struct param.
 * @buffer: The buffer.
 * @size: size of buffer.
 * Retrn: num of bytes read (Success), -1 (Otherwise)
*/
ssize_t _r_buffer(simpleshell_t *ss_info, char *buffer, size_t *size)
{
ssize_t rbytes = read(ss_info->rfd, buffer, 1024);

if (*size)
return (0);

if (rbytes >= 0)
*size = (size_t)rbytes;

return (rbytes);
}

/**
 * _getenv - gets the value of an environ variable
 * @ss_info: simpleshell_t struct param.
 * @envvar: pointer to env var name
 * Return: the env var val (Success), NULL (Otherwise)
 */
char *_envval(simpleshell_t *ss_info, const char *envvar)
{
list_t *n = ss_info->local_env_list;
char *val_ptr;

for (; n; n = n->next)
{
val_ptr = _starts(n->string, envvar);
if (val_ptr && *val_ptr)
return (val_ptr);
}
return (NULL);
}

/**
 * _exit - exits shell.
 * @ss_info - simpleshell_t struct param.
 * Return: exit with exit code.
*/
int _exit(simpleshell_t *ss_info)
{
int exit_code;
if (ss_info->av[1])
{
exit_code = _eatoi(ss_info->av[1]);
if (exit_code == -1)
{
ss_info->last_cmd_status = 2;
_eprint(ss_info, "Invalid numeric argument: ");
_w_str_stdder(ss_info->av[1]);
_w_stdder('\n');
return (1);
}
ss_info->exit_error = exit_code;
return (-2);
}
ss_info->exit_error = -1;
return (-2);
}
