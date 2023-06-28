#include "shell.h"

/**
 *  main - a simple shell
 *
 *  @ac: no of strings in @av
 *  @av: A vector pointer containing the arguments used to execute the shell
 *  @env: the environment variable
 *
 * Return: 0 - success
 */

int main(int ac, char **av, char *env[])
{
	char userInput[1024];
	char *tokenizedCommand[MAX_TOKENS];
	int interrupted = 0;

	(void)ac;
	(void)av;

	if (!isatty(STDIN_FILENO))
	{
		if (fgets(userInput, sizeof(userInput), stdin) == NULL)
		{
			perror("Error reading input");
			return (1);
		}
		userInput[strcspn(userInput, "\n")] = '\0';
		parseUserInput(userInput, tokenizedCommand);
		interrupted = executeCommand(tokenizedCommand, env);
		freeTokenizedCommand(tokenizedCommand);
		return (0);
	}

	do {
		printf("shell $: ");

		if (fgets(userInput, sizeof(userInput), stdin) == NULL)
		{
			interrupted = 1;
			continue;
		}
		userInput[strcspn(userInput, "\n")] = '\0';

		if (userInput[0] == '\0')
			continue;
		parseUserInput(userInput, tokenizedCommand);
		interrupted = executeCommand(tokenizedCommand, env);
		freeTokenizedCommand(tokenizedCommand);

	} while (!interrupted);

	exit(EXIT_FAILURE);
}

/**
 * freeTokenizedCommand - A function to free a 2D array
 *
 * @tokenizedCommand: Array to be freed
 */

void freeTokenizedCommand(char *tokenizedCommand[])
{
	int i = 0;

	while (tokenizedCommand[i] != NULL)
	{
		free(tokenizedCommand[i]);
		i++;
	}
}
