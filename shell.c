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
	char *userInput = NULL;
	char *tokenizedCommand[MAX_TOKENS];
	int interrupted = 0, exitStatus = 0;
	size_t n;

	(void)ac;
	(void)av;

	/*if (!isatty(STDIN_FILENO))
	{
		if (getline(&userInput, &n, stdin) == -1)
		{
			perror("Error reading input");
			return (1);
		}
		userInput[strcspn(userInput, "\n")] = '\0';
		parseUserInput(userInput, tokenizedCommand);
		free(userInput);

		interrupted = executeCommand(userInput, tokenizedCommand, env);
		freeTokenizedCommand(tokenizedCommand);
		return (0);
	}*/
	do {
		if (isatty(STDIN_FILENO))
			printf("shell $: ");

		if (getline(&userInput, &n, stdin) == -1)
		{
			interrupted = 1;
			free(userInput);
			exit(exitStatus);
		}
		/*userInput[strcspn(userInput, "\n")] = '\0';*/

		if (userInput[0] == '\0')
			continue;
		parseUserInput(userInput, tokenizedCommand);
		exitStatus = executeCommand(userInput, tokenizedCommand, env);
		freeTokenizedCommand(tokenizedCommand);

	} while (!interrupted);
	free(userInput);
	exit(exitStatus);
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

/**
 * trimWhiteSpace - A fuction to remove trailing and leading white spaces
 *
 * @str: the string to be parsed
 *
 * Return: void.
 */

void trimWhiteSpace(char *str)
{
	int len = strlen(str);
	int i = len - 1, j = 0;


	while (isspace(str[j]))
	{
		j++;
	}
	if (j > 0)
	{
		memmove(str, str + j, len - j + 1);
		len -= j;
	}

	while (i >= 0 && isspace(str[i]))
	{
		str[i] = '\0';
		i--;
	}
}
