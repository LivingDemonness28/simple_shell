#include "simpleshell.h"

/**
 * _r_line - reads a line from the input and
 * appends it to the provided buffer.
 * @ss_info: simpleshell_t struct param.
 * @pointer: pointer to buffer.
 * @curr_len: current length of buffer.
 * Return: num of chars read and new line (Success), -1 (Otherwise)
*/
int _r_line(simpleshell_t *ss_info, char **pointer, size_t *curr_len)
{
static char buffer[1024];
static size_t a, length;
size_t b;
ssize_t d, e = 0;
char *f = NULL, *np = NULL, *c;

f = *pointer;
if (f && curr_len)
e = *curr_len;
if (a == length)
a = length = 0;

d = _r_buffer(ss_info, buffer, &length);
if (d == -1 || (d == 0 && length == 0))
return (-1);

c = _strchr(buffer + a, '\n');
b = c ? 1 + (unsigned int)(c - buffer) : length;
np = _realloc(f, e, e ? e + b : b + 1);
if (!np)
return (f ? free(f), -1 : -1);

if (e)
_strncat(np, buffer + a, b - a);
else
_strncpy(np, buffer + a, b - a + 1);

e += b - a;
a = b;
f = np;

if (curr_len)
*curr_len = e;
*pointer = f;
return (e);
}

/**
 * _updt_cd - changes current directory
 * @ss_info: simpleshell_t struct param.
 * Return: 0 (Always)
*/
int _updt_cd(simpleshell_t *ss_info)
{
char *tar_dir, buffer[1024], *path;
int res;

path = getcwd(buffer, 1024);
if (!path)
_puts("Error: Unable to retrieve current directory.\n");
if (!ss_info->av[1])
{
tar_dir = _envval(ss_info, "SS_HOME=");
if (!tar_dir)
res = chdir((tar_dir = _envval(ss_info, "SS_PWD=")) ? tar_dir : "/");
else
res = chdir(tar_dir);
}
else if (_strcmp(ss_info->av[1], "-") == 0)
{
if (!_envval(ss_info, "SS_OLDPWD="))
{
_puts(path);
_putchar('\n');
return (1);
}
_puts(_envval(ss_info, "SS_OLDPWD=")), _putchar('\n');
res = chdir((tar_dir = _envval(ss_info, "SS_OLDPWD=")) ? tar_dir : "/");
}
else
res = chdir(ss_info->av[1]);
if (res == -1)
{
_eprint(ss_info, "can't cd to ");
_wsstderr(ss_info->av[1]), _wcstderr('\n');
}
else
{
_updt_env(ss_info, "SS_OLDPWD", _envval(ss_info, "SS_PWD="));
_updt_env(ss_info, "SS_PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
 * _input_buffer - read input from user and appends
 * it to the buffer.
 * @ss_info: simpleshell_t struct param.
 * @buffer: the buffer.
 * @length: current buffer length.
 * Return: num of chars (Success), 0 (empty input),
 * -2 (Ends with backslash), -1 (Otherwise)
*/
ssize_t _input_buffer(simpleshell_t *ss_info, char **buffer, size_t *length)
{
ssize_t read_chars = 0;
size_t temp_len = 0;

if (!*length)
{
free(*buffer);
*buffer = NULL;
signal(SIGINT, _block_ctrlc);
#if _GETLINE
read_chars = getline(buffer, &temp_len, stdin);
#else
read_chars = _r_line(ss_info, buffer, &temp_len);
#endif
if (read_chars > 0)
{
if ((*buffer)[read_chars - 1] == '\n')
{
(*buffer)[read_chars - 1] = '\0';
read_chars--;
}
ss_info->line_count_tracker = 1;
_nocomments(*buffer);
_apnd_hist_list(ss_info, *buffer, ss_info->history_count++);
{
*length = read_chars;
ss_info->command_buf = buffer;
}
}
}
return (read_chars);
}

/**
 * _exe_input - executes input retrieval and processing,
 * including command chains and memory handling.
 * @ss_info: simpleshell_t struct param.
 * Return: number of bytes read.
*/
ssize_t _exe_input(simpleshell_t *ss_info)
{
static char *buffer;
static size_t a, b, clen;
ssize_t cread = 0;
char **input_ptr = &(ss_info->input_args), *res;

_putchar(-1);
cread = _input_buffer(ss_info, &buffer, &clen);
if (cread == -1)
return (-1);
if (clen)
{
b = a;
res = buffer + a;

_eval_chain(ss_info, buffer, &a, b, clen);
while (a < clen)
{
if (_chain_del(ss_info, buffer, &a))
break;
a++;
}

b = a + 1;
if (b >= clen)
{
b = clen = 0;
ss_info->cmd_type = 0;
}

*input_ptr = res;
return (_strlen(res));
}

*input_ptr = buffer;
return (cread);
}

/**
 * _shell_help - displays help information for
 * simpleshell.
 * @ss_info: simpleshell_t struct param.
 * Return: 0 (Always)
*/
int _shell_help(simpleshell_t *ss_info)
{
char **arg_arr;

arg_arr = ss_info->av;
_puts("function works. Not implemented yet \n");
if (0)
_puts(*arg_arr);
return (0);
}
