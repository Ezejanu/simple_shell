#include "main.h"

/**
 *
 */

void _fork(char *argv[])
{
	pid_t childproc;
	int status;

	childproc = fork();
	if (childproc == -1)
	{
		perror("Error");
		exit(0);
	}
	else if (childproc == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error");
	}
	else
		wait(&status);
}
