#include "main.h"

/**
 * main - a simple shell
 * Return: 0 - success
 */

int main(void)
{
	char *command = NULL, *prompt = "our shell $: ", *Error = "Error";
	char *commtoken = NULL, *argtoken = NULL, *tmp = NULL, *argv[1024];
	size_t n = 0, i = 1;

	_write(prompt);
	while (1)
	{
		if (getline(&command, &n, stdin) == -1)
			return (-1);
		
		if (check_command(command) == 2)
			continue;
		
		commtoken = strtok(command, "\n");
		
		if (check_command(commtoken) == 3)
			exit(EXIT_SUCCESS);
		_env(commtoken);
		argtoken = strtok(commtoken, " ");
		tmp = _strdup(argtoken);
		argtoken = strtok(NULL, " ");
		
		if (argtoken != NULL)
		{
			do {
				argv[i++] = argtoken;
			} while
			((argtoken = strtok(NULL, " ")));
		}
		argv[i] = NULL;
		
		if (findpath(tmp) != Error)
		{
			argv[0] = findpath(tmp);
			_fork(argv);
		}
		
		else
			perror("Error:");
		empty(argv);
		i = 1;
		_write(prompt);
	}
	free(command);
	free(tmp);
	return (0);
}
