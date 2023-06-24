#include "main.h"

/**
 * main - a simple shell
 * Return: 0 - success
 */

int main(void)
{
	char *prompt = "our shell $: ";
	char *command = NULL;
	char *commtoken = NULL, *argtoken = NULL, *delim = "\n", *delim2 = " ";
	char *argv[1024], *tmp = NULL, *tmpcmp = NULL, *tmpenv = NULL, *Error = "Error";
	size_t n = 0;
	int status, i = 1;
	pid_t childproc;

	printf("%s", prompt);
	while (1)
	{
		if (getline(&command, &n, stdin) == -1)
			return (-1);

		commtoken = strtok(command, delim);
		tmpcmp = strdup(commtoken);
		if (endprog(tmpcmp))
		{
			return (1);
		}
		tmpenv = strdup(commtoken);
		_env(tmpenv);
		argtoken = strtok(commtoken, delim2);

		tmp = strdup(argtoken);

		argtoken = strtok(NULL, delim2);
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
			else
				wait(&status);
			}
		else
		{
			perror("Error:");
		}
		empty(argv);
		i = 1;
		printf("%s", prompt);
	}
	free(command); free(tmp); free(tmpcmp); free(tmpenv);
	return (0);
}
