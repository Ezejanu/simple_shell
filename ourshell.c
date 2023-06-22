#include "main.h"


/**
 *
 */

int main(void)
{
	char *prompt = "our shell $: ";
	char *command = NULL;
	char *commtoken, *argtoken, *delim = "\n";
	char *argv[1024];
	size_t n = 0;
	int status, i;
	pid_t childproc;
	
	printf("%s", prompt);
	while (1)
	{
		if (getline(&command, &n, stdin) == -1)
			return (-1);
		commtoken = strtok(command, delim);

		argtoken = strtok(commtoken, " ");
		for (i = 0; argtoken; i++)
		{
			argv[i] = argtoken;
			argtoken = strtok(NULL, " ");
		}
		argv[i] = NULL;

		childproc = fork();
		if (childproc == -1)
		{
			perror("Error:");
			return (1);
		}
		if (childproc == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error:");
		}
		else
			wait(&status);
	 printf("%s", prompt); 
	}
	free (command);
	return (0);
}
	
