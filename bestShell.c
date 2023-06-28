#include "shell.h"

int main()
{
    char userInput[1024];
    char *tokenizedCommand[MAX_TOKENS];
    int interrupted = 0;
    char *env[10];
    

    do
    {
        printf("shell $: ");
        if (fgets(userInput, sizeof(userInput), stdin) == NULL)
        {
            interrupted = 1;
            continue;
        }

        /* Remove the trailing newline character from userInput */
        userInput[strcspn(userInput, "\n")] = '\0';

	/* Empty Line */
	if (userInput[0] == '\0')
		continue;

        parseUserInput(userInput, tokenizedCommand);

	printf("[0] -> %s\n[1] -> %s\n", tokenizedCommand[0], tokenizedCommand[1]);
        /** Use the tokenized command
        * ...
	*/
	interrupted = executeCommand(tokenizedCommand, env);
        /* Free the dynamically allocated memory*/
        freeTokenizedCommand(tokenizedCommand);

    } while (!interrupted);

    return 0;
}

/**
 *
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
