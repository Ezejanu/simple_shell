#include "shell.h"

/**
 * executeCommand - A function to execute the tokenised command-
 * which is the output of the parseUserInput function
 *
 * @tokenizedCommand: the tokenized command to be executed
 * @env: passing the environment
 *
 * Return: 1 to indicate main should interrupted
 * and 0 when the main loop can continue.
 */

int executeCommand(char *userInput, char *tokenizedCommand[], char *env[])
{
	char *filePath = tokenizedCommand[0];
	char *command = tokenizedCommand[0];

	(void) env;

	if (command == NULL || command[0] == '\0')
	{
		return (0);
	}

	if (shouldExit(filePath))
	{
		if (tokenizedCommand[1] != NULL)
		{
			int exitStatus = atoi(tokenizedCommand[1]);

			free(userInput);
			freeTokenizedCommand(tokenizedCommand);
			exit(exitStatus);
		}
		else
		{
			free(userInput);
			freeTokenizedCommand(tokenizedCommand);
			exit(EXIT_SUCCESS);
		}
	}

	if (strlen(tokenizedCommand[0]) == 1 && filePath == NULL)
	{
		return (0);
	}

	if (isEnvCommand(filePath))
	{
		_printEnv();
		return (0);
	}

	return (executeGenericCommand(tokenizedCommand));
}

/**
 * executeGenericCommand - A function to execute generic commands
 * i.e commands that do not need special conditions to execute
 *
 * @tokenizedCommand: a pointer to the tokenized command to be executed
 * @env: passing the environment
 *
 * Return: void
 */

int executeGenericCommand(char *tokenizedCommand[])
{
	/**
	 * user enters a full path
	 *	use statbuf to verify if it is a valid path and execute
	 *		what if valid but not executable?
	 *		fork would raise an error that we can look at?
	 */

	struct stat statbuf;
	char commandPath[1024];
	char *revisedTokenizedCommand[1024];
	int exitStatus = 0;

	if (stat(tokenizedCommand[0], &statbuf) == 0)
	{
		exitStatus = _fork(tokenizedCommand);
		return (exitStatus);
	}

	/**
	* user enters the command name
	* we need to construct the path ourselves
	* verify if valid and execute
	*/

	exitStatus = constructCommandPath(commandPath, tokenizedCommand[0]);
	if (commandPath == NULL)
	{
		return (exitStatus);
	}

	/**
	* Alternative for handling local variable issues
	* char *commandPath[1024];
	* constructCommandPath(tokenizedCommand[0], &commandPath);
	*/

	duplicateArray(revisedTokenizedCommand, tokenizedCommand);
	revisedTokenizedCommand[0] = commandPath;
	exitStatus = _fork(revisedTokenizedCommand);

	if (exitStatus == 127)
		fprintf(stderr, "./hsh: 1: %s: not found\n", tokenizedCommand[0]);
	return (exitStatus);
}

/**
 * duplicateArray - A function to duplicate a 2-dimensional array
 * It is a helper function for the executeGenericCommand function
 *
 * @duplicateArray: the destination array
 * @originalArray: the source array
 *
 * Return: void
 */

void duplicateArray(char *duplicateArray[], char *originalArray[])
{
	int i;

	for (i = 0; originalArray[i]; i++)
	{
		duplicateArray[i] = originalArray[i];
	}
	duplicateArray[i] = NULL;

}


/**
 * _fork - a function to fork a child process and execute the function
 * @tokenizedCommand: string to be forked
 * @env: passing the environment
 * Return: void
 */

int _fork(char *tokenizedCommand[])
{
	pid_t childproc;
	int status;

	childproc = fork();
	if (childproc == -1)
	{
		perror("Error");
		exit(0); /* do we need to exit here or just return? */
	}
	else if (childproc == 0)
	{
		if
		(execve(tokenizedCommand[0], tokenizedCommand, environ) == -1)
			return (127);
	}
	else
		wait(&status);

	return (0);
}
