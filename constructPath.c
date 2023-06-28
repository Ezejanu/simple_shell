#include "shell.h"

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
