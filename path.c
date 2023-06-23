#include "main.h"

/**
 *
 */

char * findpath(char * command)
{
        char *pathname, *duplicate, *filepath, *token, *delim = ":";
        int length;
	struct stat statbuf;


	length = strlen(command);
        pathname = getenv("PATH");
        duplicate = strdup(pathname);

        token = strtok(duplicate, delim);
        do
        {
                filepath = malloc(strlen(token) + length + 2);
                if (filepath == NULL)
                {
                        perror("Error:");
                 	free(duplicate); 
			free(filepath);
		 	return(NULL); /*OR exit() to leave the program completely since malloc failed*/
                }
                strcpy(filepath, token);
                strcat(filepath, "/");
                strcat(filepath, command);
                strcat(filepath, "\0");

		
		if(stat(filepath, &statbuf) == 0)
                {
			free(duplicate);
                       return (filepath);
                }

        }
        while((token = strtok(NULL, delim)));

	free(duplicate);
        return (command);
}
