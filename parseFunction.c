#include "shell.h"

/**
 * parseUserInput - A function to provide a cleaned and analysed version
 * of the user input as a list of command tokens.
 *
 * @userInput: A pointer to the user's input.
 *
 * @tokenizedCommand: A pointer to the tokenized command.
 * This is the output of this parseUserInput function.
 *
 * Return: A pointer to the tokenized command.
 */

void parseUserInput(char *userInput, char *tokenizedCommand[])
{
	int i = 0;
	char *token = strtok(userInput, " ");

	/* Check for comments */
	if (token != NULL && token[0] == '#')
	{
		tokenizedCommand[0] = NULL;
		return;
	}

	while (token != NULL && i < MAX_TOKENS)
	{
		if (token[0] == '#')
		{
			break;
		}

		tokenizedCommand[i] = strdup(token);
		i++;
		token = strtok(NULL, " ");
	}

	if (i > 0)
		trimWhiteSpace(tokenizedCommand[0]);

	/* Add a NULL pointer at the end of the tokenized command*/
	tokenizedCommand[i] = NULL;
}
