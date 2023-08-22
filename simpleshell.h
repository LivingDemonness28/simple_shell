#ifndef _SIMPLESHELL_H_
#define _SIMPLESHELL_H_

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

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
 * struct shellinfo - contains arguments to pass
 * info into func
 * @av: array of strings generated from arguments.
 * @line_num: error number.
 * @filename: program filename.
 * @rfd: the fd where we read line input from.
*/
typedef struct shellinfo
{
char **av;
unsigned int line_num;
char *filename;
int rfd;
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
char *_strdup(char *str);
/*functions_4.c*/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_starts(const char *h, const char *n);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);

#endif
