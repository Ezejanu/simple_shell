#include "main.h"

/**
 * main - a simple shell
 * Return: 0 - success
 */

int main(void)
{
	char *prompt = "our shell $: ";
	char *command = NULL;
	char *commtoken = NULL, *argtoken = NULL;
	char *argv[1024], *tmp = NULL, *tmpcmp = NULL, *tmpenv = NULL, *Error = "Error";
	size_t n = 0, i = 1;

	_write(prompt);
	while (1)
	{
		if (getline(&command, &n, stdin) == -1)
			return (-1);

		commtoken = strtok(command, "\n");
		tmpcmp = strdup(commtoken);
		if (endprog(tmpcmp))
		{
			return (1);
		}
		tmpenv = strdup(commtoken);
		_env(tmpenv);
		argtoken = strtok(commtoken, " ");

		tmp = strdup(argtoken);

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
		{
			perror("Error:");
		}
		empty(argv);
		i = 1;
		_write(prompt);
	}
	free(command); free(tmp); free(tmpcmp); free(tmpenv);
	return (0);
}
