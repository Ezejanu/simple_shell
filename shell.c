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
	
	
	/**
	* check if it is non interactive
	* copy from av[1] to the pipe into a string and pass into parse to parse
	* *clean results from parse by removing " - quototion */

	/* Check if running in non-interactive mode */
	
	if (!isatty(STDIN_FILENO)) 
	{
	/* Read input from standard input (e.g., using fgets) */
		if (fgets(userInput, sizeof(userInput), stdin) == NULL) 
		{
			perror("Error reading input");
			return 1;
		}
		/* Remove the trailing newline character */
		userInput[strcspn(userInput, "\n")] = '\0';

		/* Process the input */
		parseUserInput(userInput, tokenizedCommand);
		interrupted = executeCommand(tokenizedCommand, env);
		freeTokenizedCommand(tokenizedCommand);

		return 0;
	}

	do {
		printf("shell $: ");

		if (fgets(userInput, sizeof(userInput), stdin) == NULL)
		{
			/* Handle EOF */
			interrupted = 1;
			continue;
		}

		/* Remove the trailing newline character from userInput */
		userInput[strcspn(userInput, "\n")] = '\0';

		/* Handle empty Line */
		if (userInput[0] == '\0')
			continue;

		parseUserInput(userInput, tokenizedCommand);

		/* Use the tokenized command */
		interrupted = executeCommand(tokenizedCommand, env);

		/* Free the dynamically allocated memory*/
		freeTokenizedCommand(tokenizedCommand);

	} while (!interrupted);

	return (0);
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
