#ifndef _SIMPLESHELL_H_
#define _SIMPLESHELL_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>

extern char **environ;

#define EMPTY_INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct liststring - singly linked list.
 * @number: the number field.
 * @string: string.
 * @next: points to next node.
*/
typedef struct liststring
{
char *string;
int number;
struct liststring *next;
} list_t;

/**
 * struct shellinfo - contains false args to
 * pass into a function.
 * @input_args: a string generated from getline contain arguments.
 * @av: array of strings generated from arguments.
 * @cmd_path: string path for current command.
 * @ac: argument count.
 * @line_num: error number.
 * @exit_error: the error number for exit function.
 * @line_count_tracker: on count this line of input.
 * @filename: program filename.
 * @local_env_list: linked list local copy of environ.
 * @custom_env: custom modified environment.
 * @cmd_hist: history node.
 * @alias_node: aliad node.
 * @env_mod: modified custom environment.
 * @last_cmd_status: return status of the last executed command.
 * @command_buf: pointer address to command_buf, on if chaining.
 * @cmd_type:  CMD_type ||, &&, :
 * @rfd: the fd where we read line input from.
 * @history_count: hist line number count.
*/
typedef struct shellinfo
{
char *input_args;
char **av;
char *cmd_path;
int ac;
unsigned int line_num;
int exit_error;
int line_count_tracker;
char *filename;
list_t *local_env_list;
list_t *cmd_hist;
list_t *alias_node;
char **custom_env;
int env_mod;
int last_cmd_status;

char **command_buf;
int cmd_type;
int rfd;
int history_count;
} simpleshell_t;

/*Function prototypes*/
/*functions_1.c*/
char *_strncat(char *dest, char *src, int n);
int _check_del(char ch, char *del_str);
int _interact(simpleshell_t *ss_info);
int _repstr(char **ostr, char *nstr);
int _putchar(char c);
/*functions_2.c*/
char *_strchr(char *str, char c);
int _w_stderr(char c);
void _w_str_stderr(char *str);
int _wc_to_fd(char c, int fd);
int _wsfd(char *str, int fd);
/*functions_3.c*/
int _decimalfd(int num, int fd);
void _nocomments(char *buffer);
void _eprint(simpleshell_t *ss_info, char *str);
void _puts(char *str);
char *_strdup(const char *str);
/*functions_4.c*/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_starts(const char *h, const char *n);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);
/*functions_5.c*/
char *_strncpy(char *dest, char *src, int n);
int _dis_alias(list_t *n);
int _eatoi(char *str);
char *_memset(char *s, char b, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/*functions_6.c*/
void _free_strarr(char **strstr);
ssize_t _r_buffer(simpleshell_t *ss_info, char *buffer, size_t *size);
char *_envval(simpleshell_t *ss_info, const char *envvar);
int _exit_shell(simpleshell_t *ss_info);
void _eval_chain(simpleshell_t *ss_info, char *buffer, size_t *pos,
size_t start, size_t length);
/*functions_7.c*/
int _chain_del(simpleshell_t *ss_info, char *buffer, size_t *pos);
void _reset_info(simpleshell_t *ss_info);
int _updt_hist(simpleshell_t *ss_info);
size_t _print_str_ele(const list_t *head);
int _del_node_at_ind(list_t **h, unsigned int ind);
/*functions_8.c*/
void _clear_list(list_t **hp);
list_t *_append_node(list_t **h, const char *str, int num);
list_t *_unshift_node(list_t **h, const char *str, int num);
size_t _listlen(const list_t *head);
list_t *_prefix_node(list_t *h, char *start, char c);
/*functions_9.c*/
ssize_t _node_ind(list_t *h, list_t *n);
char **_strarr(list_t *h);
int _apnd_hist_list(simpleshell_t *ss_info, char *buffer, int histcount);
char *_histfile(simpleshell_t *ss_info);
int _w_hist(simpleshell_t *ss_info);
/*functions_10.c*/
int _r_hist(simpleshell_t *ss_info);
char **_strtow_1(char *str, char *del);
char **_strtow_2(char *str, char del);
int _currenv(simpleshell_t *ss_info);
int _init_env_list(simpleshell_t *ss_info);
/*functions_11.c*/
void _block_ctrlc(__attribute__((unused))int signal_number);
int _updt_env(simpleshell_t *ss_info, char *envvar, char *envval);
int _del_alias(simpleshell_t *ss_info, char *str);
int _add_alias(simpleshell_t *ss_info, char *str);
int _alias(simpleshell_t *ss_info);

#endif
