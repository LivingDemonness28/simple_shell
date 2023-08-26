#include "simpleshell.h"

/**
 * _copy_env - str copy of env.
 * @ss_info: simpleshell_t struct param.
 * Return: 0 (Always)
*/
char **_copy_env(simpleshell_t *ss_info)
{
if (ss_info->custom_env || ss_info->env_mod)
{
ss_info->custom_env = _strarr(ss_info->local_env_list);
ss_info->env_mod = 0;
}
return (ss_info->custom_env);
}

/**
 * _del_env - unset an env var in the local
 * env list.
 * @ss_info: simpleshell_t struct param
 * @envvar: environment variable/
 * Return: 1 (Success), 0 (Otherwise)
*/
int _del_env(simpleshell_t *ss_info, char *envvar)
{
list_t *n = ss_info->local_env_list;
size_t a = 0;
char *es;

if (!n || !envvar)
return (0);

while (n)
{
es = _starts(n->string, envvar);
if (es && *es == '=')
{
ss_info->env_mod = _del_node_at_ind(&(ss_info->local_env_list), a);
a = 0;
n = ss_info->local_env_list;
continue;
}
n = n->next;
a++;
}
return (ss_info->env_mod);
}

/**
 * _free_ptr - NULL a pointer address
 * @pointer: pointer address.
 * Return: 1 (Success), 0 (Otherwise)
*/
int _free_ptr(void **pointer)
{
if (pointer && *pointer)
{
free(*pointer);
*pointer = NULL;
return (1);
}
return (0);
}

/**
 * _check_cmd - check if file is exe cmd.
 * @ss_info: simpleshell_t struct param.
 * @cmd_path: file path.
 * Return: 1 (Success), 0 (Otherwise)
*/
int _check_cmd(simpleshell_t *ss_info, char *cmd_path)
{
struct  stat st;

(void)ss_info;
if (!cmd_path || stat(cmd_path, &st))
return (0);

if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
 * _itoa - convert long int to str
 * @n: number.
 * @b: base for conversion.
 * @f: flag.
 * Return: ptr to converted str.
*/
char *_itoa(long int n, int b, int f)
{
static char *arr, buffer[50];
char s = 0, *pointer = &buffer[49];
unsigned long a = n;

if (!(f & 2) && n < 0)
{
a = -n;
s = '-';
}

arr = f & 1 ? "0123456789abcdef" : "0123456789ABCDEF";
*pointer = '\0';

while (a != 0)
{
*--pointer = arr[a % b];
a /= b;
}

if (s)
*--pointer = s;
return (pointer);
}
