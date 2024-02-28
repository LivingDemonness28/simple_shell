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

/*function_1.c*/
int _del(char c, char *_del);
int _interact(ss_t *ss_info);
int _isalpha(int c);
void _chain(ss_t *ss_info, char *buf, size_t *pos, size_t a, size_t len);
int _repstr(char **o, char *n);

#endif
