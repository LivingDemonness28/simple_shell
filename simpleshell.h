#ifndef _SIMPLESHELL_H_
#define _SIMPLESHELL_H_

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

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

#endif
