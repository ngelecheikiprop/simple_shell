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
void exec(char **argv, char **env, char **av);

#endif
