#include "shell.h"

void parseUserInput(char *userInput, char *tokenizedCommand[])
{

    int i = 0;

    char *token = strtok(userInput, " ");
    while (token != NULL && i < MAX_TOKENS)

    {
        tokenizedCommand[i] = strdup(token);
        i++;

        token = strtok(NULL, " ");
    }

    /* Add a NULL pointer at the end of the tokenized command*/
    tokenizedCommand[i] = NULL;

}
