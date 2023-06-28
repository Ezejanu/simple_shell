#include "shell.h"

/**
 * constructCommandPath - A function to construct the command path
 * when the command is provided without its path.
 * 
 * @commandPath: where the constructed command path is stored.
 * @command: the command whose path is to be generated.
 *
 * Return: void
 */

void constructCommandPath(char *commandPath, char *command)
{
    char *envPaths = NULL;
    char *path = NULL;
    char *duplicate = NULL;
    struct stat statbuf;

    envPaths = getenv("PATH");
    duplicate = strdup(envPaths);
    path = strtok(duplicate, ":");

    while (path != NULL)
    {
        strcpy(commandPath, path);
        strcat(commandPath, "/");
        strcat(commandPath, command);

        if (stat(commandPath, &statbuf) == 0)
        {
            break;
        }

        memset(commandPath, 0, 1024);
        path = strtok(NULL, ":");
    }

    free(duplicate);

    if (commandPath[0] != '\0')
    {
        return;
    }

    perror("Did not find a valid path for command!");
    return;
}
=======
/**
 * constructCommandPath - A function to construct the command path
 * when the command is provided without its path.
 * 
 * @commandPath: where the constructed command path is stored.
 * @command: the command whose path is to be generated.
 *
 * Return: void
 */

