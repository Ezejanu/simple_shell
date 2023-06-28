#include "shell.h"

int main(int ac, char **av, char *env[])
{
    char userInput[1024];
    char *tokenizedCommand[MAX_TOKENS];
    int interrupted = 0;
    (void)ac;
    (void)av;
    

    do
    {
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
