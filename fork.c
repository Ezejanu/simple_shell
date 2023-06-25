#include "main.h"

/**
 * _fork - a function to fork a child process and execute the function
 * @argv: string to be forked
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





/**
 * check_command - a function to check what command is typed in/received from the terminal
 * @command: command to be checked
 * Return: a pointer to t
 */

int check_command(char *command)
{
	/**
	char *commtoken = NULL, char *new_line = "\n";
	*tmpcmp = NULL, *tmpenv = NULL */
    char *new_line = "\n";	char *prompt = "our shell $: ";

	if (strcmp(command, new_line) == 0)
	{
		_write(prompt);
			return(2);
	}
	/*
		commtoken = strtok(command, "\n");
        tmpcmp = _strdup(commtoken);
        if (endprog(tmpcmp))
        {
            return (1);
        }
		*/
return (0);
}
