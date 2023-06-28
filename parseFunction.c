#include "shell.h"

/**
 * parseUserInput - A function to provide a cleaned and analysed version
 * of the user input as a list of command tokens.
 *
 * @userInput: A pointer to the user's input.
 *
 * Return: A pointer to the tokenized command.
 */

/* We made a change here to the function header, to take care of the local variable issue*/
void parseUserInput(char *tokenizedCommand[1024], char *userInput)
{
    char token[1024];
    int i = 0;

    /* Replace new line character with NULL. */
    userInput[strlen(UserInput) - 1] = NULL;

    token = strtok(userInput, " ");
    do
    {
        strcpy(tokenizedCommand[i], token);
        i++;
    } while (token = strtok(NULL, " "));

    return;
}