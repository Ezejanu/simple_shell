#include "main.c"

/**
 *
 */

int _fork()
{
	childproc = fork();
            if (childproc == -1)
            {
                perror("Error");
                return (1);
            }
        if (childproc == 0)
        {
            if (execve(argv[0], argv, NULL) == -1)
                perror("Error");
        }
