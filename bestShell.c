#include "shell.h"
/**
 *  main - a simple shell
 * Return: 0 - success
 */

int main(int argc, char *argv[], char *env[])
{
    char *userInput = NULL;
    char *prompt = "shell $: ";
    char *tokenizedCommand[1024];
    size_t userInputLen = 0;
    int interrupted = 0;

    (void)argc;
    (void)argv;

    do
    {
        /*Prompt user*/
        _write(prompt);

        /*Read user input*/
        if (getline(&userInput, &userInputLen, stdin) == -1)
        {
            /*Catch EOF.*/
            interrupted = 1;
            continue;
        }

        /* We made a change here, to take care of the local variable issue*/
        parseUserInput(tokenizedCommand, userInput);
        interrupted = executeCommand(tokenizedCommand, env)
    } while (!interrupted)

        free(userInput);

    return (0);
}