#include "simpleshell.h"

/**
 * set_alias - set alias string
 * @ss_info: simpleshell struct param
 * @str: alias string
 * Return: 0 (Success), 1 (Otherwise)
*/
int set_alias(ss_t *ss_info, char *str)
{
char *a;

a = _strchr(str, '=');
if (!a)
return (1);
if (!*++p)
return (unset_alias(ss_info, str));

unset_alias(ss_info, str);
return (_append_node(&(ss_info->_alias), str, 0) == NULL);
}

/**
 * _alias - alias builtin (copy)
 * @ss_info: simpleshell struct param
 * Return: 0 (Always)
*/
int _alias(ss_t *ss_info)
{
int a = 0;
char *b = NULL;
list_t *n = NULL;

if (ss_info->argc == 1)
{
n = ss_info->_alias;
while (n)
{
print_alias(n);
n = n->next;
}
return (0);
}
for (a = 1; ss_info->argv[a]; a++)
{
b = _strchr(ss_info->argv[a], '=');
if (b)
set_alias(ss_info, ss_info->argv[a]);
else
print_alias(_pre_node(ss_info->_alias, ss_info->argv[a], '='));
}

return (0);
}

/**
 * input_buffer - buffers chained commands
 * @ss_info: simpleshell struct param
 * @buf: buffer
 * @len: var len
 * Return: bytes read
*/
ssize_t input_buffer(ss_t *ss_info, char **buf, size_t *len)
{
ssize_t a = 0;
size_t len_p = 0;

if (!*len)
{
free(*buf);
*buf = NULL;
signal(SIGINT, _blockCtrlC);
#if USE_GETLINE
a = getline(buf, &len_p, stdin);
#else
a = _getline(ss_info, buf, &len_p);
#endif
if (a > 0)
{
if ((*buf)[a - 1] == '\n')
{
(*buf)[a - 1] = '\0';
a--;
}
ss_info->linecount_flag = 1;
_no_comment(*buf);
_hist_list(ss_info, *buf, ss_info->_histline++);
{
*len = a;
ss_info->cmd_buffer = buf;
}
}
}
return (a);
}

/**
 * _cd - change directory
 * @ss_info: simpleshell struct param
 * Return: 0 (Always)
*/
int _cd(ss_t *ss_info)
{
char *dir, buf[1024], *a = getcwd(buf, 1024);
int cd_ret;

if (!a)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!ss_info->argv[1])
{
dir = _getenv(ss_info, "HOME=");
if (!dir)
cd_ret = chdir((dir = _getenv(ss_info, "PWD=")) ? dir : "/");
else
cd_ret = chdir(dir);
}
else if (_strcmp(ss_info->argv[1], "-") == 0)
{
if (!_getenv(ss_info, "OLDPWD="))
{
_puts(a);
_putchar('\n');
return (1);
}
_puts(_getenv(ss_info, "OLDPWD=")), _putchar('\n');
cd_ret = chdir((dir = _getenv(ss_info, "OLDPWD=")) ? dir : "/");
}
else
cd_ret = chdir(ss_info->argv[1]);
if (cd_ret == -1)
{
_eprint(ss_info, "can't cd to");
_eputs(ss_info->argv[1]), _eputchar('\n');
}
else
{
_setenv(ss_info, "OLDPWD", _getenv(ss_info, "PWD="));
_setenv(ss_info, "PWD", getcwd(buf, 1024));
}
return (0);
}

/**
 * get_input - get a line
 * @ss_info: simpleshell struct param
 * Return: bytes read
*/
ssize_t get_input(ss_t *ss_info)
{
static char *buffer;
static size_t a, b, len;
ssize_t c = 0;
char **buf_p = &(ss_info->arg), *p;

_putchar(-1);
c = input_buffer(ss_info, &buffer, &len);
if (c == -1)
return (-1);
if (len)
{
b = a;
p = buffer + a;

_chain(ss_info, buffer, &b, a, len);
while (b < len)
{
if (chain_del(ss_info, buffer, &b))
break;
b++;
}

a = b + 1;
if (a >= len)
{
a = len = 0;
ss_info->cmd_b_type = 0;
}

*buf_p = p;
return (_strlen(p));
}

*buf_p = buffer;
return (c);
}
