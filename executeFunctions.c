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

int executeCommand(char *tokenizedCommand[], char *env[])
{
    char *msg = "exit\n\n[Disconnected...]\n";
    char *filePath = tokenizedCommand[0];
	(void)env;
    printf("File path -> %s", filePath);

	if (shouldExit(filePath))
    {
        _write(msg);
        return (1);
    }

    if (isEnvCommand(filePath))
    {
        _printEnv();
        return (0);
    }

    /*executeGenericCommand(tokenizedCommand, env);*/

    return (0);
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

void executeGenericCommand(char *tokenizedCommand[], char *env[])
{
    /** user enters a full path
     * use statbuf to verify if it is a valid path and execute
     * what if valid but not executable? fork would raise an error that we can look at?
     */

    struct stat statbuf;
    char commandPath[1024];
    char *revisedTokenizedCommand[1024];

    if (stat(tokenizedCommand[0], &statbuf) == 0)
    {
        _fork(tokenizedCommand, env);
        return;
    }

    /** user enters the command name
     * we need to construct the path ourselves
     * verify if valid and execute
     */

    constructCommandPath(commandPath, tokenizedCommand[0]);
    if (commandPath == NULL)
    {
        return;
    }
    /**
     * Alternative for handling local variable issues
     * char *commandPath[1024];
     * constructCommandPath(tokenizedCommand[0], &commandPath);
     */

    duplicateArray(revisedTokenizedCommand, tokenizedCommand);
    revisedTokenizedCommand[0] = commandPath;
    _fork(revisedTokenizedCommand, env);
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

    return;
}
/* changes were made to the duplicateArray function - resolving the local variable issue */

/**
 * _fork - a function to fork a child process and execute the function
 * @argv: string to be forked
 * @env: passing the environment
 * Return: void
 */

void _fork(char *tokenizedCommand[], char *env[])
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
        if (execve(tokenizedCommand[0], tokenizedCommand, env) == -1)
            perror("Unable to execute command");
    }
    else
        wait(&status);
}
