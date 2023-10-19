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
#include <ctype.h>
/*function protypes*/
size_t count_words(char *str, char *delim);
char **list_of_words(char *str, char *delim);
void free_words(char **argv);
void exec_external(char **argv);

void exec_builtin(char **argv);
ssize_t read_from_stream(char **linepointer, size_t *bufsize, FILE *stream);

extern char **environ;

#define STDIN_BUFFSIZE 1024;
#define DELIMITERS " \t"

char *my_getenv(const char *desiredkey);

char *env();

char *file_exists(char **args);

/**
 * struct BuiltinCommand - groups functions and their program names
 * @name: name of program
 * @function: corresponding function
*/
typedef struct BuiltinCommand
{
    char *name;
    int (*function)(char **);
} BuiltinCommand;

typedef struct env_list
{
	char *envar;
	struct env_list *next_node;
} env_list;

int hsh_exit(char **args);
int hsh_cd(char **args);
int hsh_env(char **args);
/*int hsh_setenv(char **args);*/

int builtin_comp(char **args);
int (*_getfunc(char *command))(char **args);

env_list *create_list(char **env);
void free_list(env_list *head);
env_list *add_node_end(env_list **head, char *str);

void trim_whitespace(char *str);
char **substring_creation(char *str);
#endif
