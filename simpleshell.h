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
 * @rfd: the fd from which to read line, input.
*/
typedef struct shellinfo
{
int rfd;
} simpleshell_t;

/*Function prototypes*/
char *_strncat(char *dest, char *src, int n);
int _check_del(char ch, char *del_str);
int _interact(simpleshell_t *ss_info);
int _repstr(char **ostr, char *nstr);
int _putchar(char c);
char *_strchr(char *str, char c);
int _w_stderr(char c);
void _w_str_stderr(char *str);
int _wc_to_fd(char c, int fd);
int _wsfd(char *str, int fd);
int _decimalfd(int num, int fd);
void _nocomments(char *buffer);

#endif
