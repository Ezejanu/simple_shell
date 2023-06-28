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

    if (shouldExit(filePath))
    {
        _write(msg);
        return (1);
    }

    if (strlen(tokenizedCommand) == 1 && filePath == NULL)
    {
        return (0);
    }

    if (isEnvCommand(filePath))
    {
        _printEnv();
        return (0);
    }

    executeGenericCommand(tokenizedCommand, env);

    return (0);
}