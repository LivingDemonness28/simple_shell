#ifndef _SIMPLESHELL_H_
#define _SIMPLESHELL_H_

#include <stdlib>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>

extern char **environ;

/**
 * struct liststr - singly linked list
 * @number: number field
 * @str: string
 * @next: points to next node
*/
typedef struct liststr
{
char *str;
int number;
struct liststr *next;
} list_t;

/**
 * struct ss_info - psuedo args to pass info function.
 * @arg: a str generated from _getline containing args
 * @argv: arr of strs generated from arg
 * @cmd_path: a str path for current cmd
 * @argc: arg count
 * @linecount: error count
 * @errnum: error code for exit function
 * @linecount_flag: if on count this line of input
 * @filename: filename
 * @env: local copy of environ
 * @environ: modified copy of environ
 * @hist: history node
 * @_alias: alias node
 * @env_changed: environ was changed
 * @status: return status of last executed cmd
 * @cmd_buffer: ptr to cmd_buffer
 * @cmd_b_type: cmd_type ||, &&, ;
 * @rfd: fd which to read line input
 * @_histline: hist line number count.
*/
typedef struct ss_info
{
char *arg;
char **argv;
char *path;
int argc;
unsigned int linecount;
int errnum;
int linecount_flag;
char *filename;
list_t *env;
list_t *hist;
list_t *_alias;
char **environ;
int env_changed;
int status;
char **cmd_buffer;
int cmd_b_type;
int rfd;
int _histline;
} ss_t;

#define II \
{NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
0, 0, 0}

/**
 * struct builtin - builtin str and func
 * @cmd_type: cmd flag
 * @func: function
*/
typedef struct builtin
{
char *cmd_type;
int (*func)(ss_t);
} bi_table;

/*functions_1.c*/
int _del(char c, char *_del);
int _interact(ss_t *ss_info);
int _isalpha(int c);
void _chain(ss_t *ss_info, char *buf, size_t *pos, size_t a, size_t len);
int _repstr(char **o, char *n);

/*functions_2.c*/
int chain_del(ss_t *ss_info, char *buf, size_t *pos);
int _putchar(char c);
void _puts(char *str);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);

/*functions_3.c*/
char *_starts(const char *h, const char *n);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
char *_memset(char *s, char b, unsigned int n);

/*functions_4.c*/
char *dup_chars(char *pstr, int start, int stop);
int _cmd(ss_t *ss_info, char *fp);
ssize_t node_index(list_t *h, list_t *n);
list_t _pre_node(list_t *n, char *pre, char c);
size_t _list_len(const list_t *h);

/*functions_5.c*/
void free_list(list_t **hp);
size_t plist_str(const list_t *h);
int recount_hist(ss_t *ss_info);
char *_strncpy(char *dest, char *src, int n);
char *_strchr(char *str, char c);

/*functions_6.c*/
void *_realloc(void *ptr, unsigned int os, unsigned int ns);
void _free_str(char *arr);
char *exe_path(ss_t *ss_info, char *pstr, char *cmd);
char **list_str(list_t *h);
char **load_env(ss_t *ss_info);

/*function_7*/
void _blockCtrlC(__attribute__((unused))int num);
void _no_comment(char *buffer);
char *_itoa(long int num, int b, int f);
int _eputchar(char c);
void _eputs(char *str);

#endif
