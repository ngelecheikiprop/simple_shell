#ifndef SHELL_H
#define SHELL_H
/*standard libraries*/
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
/*function protypes*/
size_t count_words(char *str, char *delim);
char **list_of_words(char *str, char *delim);
void exec(char **argv);

ssize_t read_from_stream(char **linepointer, size_t *bufsize, FILE *stream);

extern char **environ;

#define STDIN_BUFFSIZE 1024;

char *my_getenv(const char *desiredkey, const char *appendValue);

char *env(void);

#endif
