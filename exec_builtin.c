#include "shell.h"

void exec_builtin(char **argv)
{
	int builtin_result = builtin_comp(argv);
	if (builtin_result == 0) 
	{
		fprintf(stderr, "%s: not found\n", argv[0]);
	}
}