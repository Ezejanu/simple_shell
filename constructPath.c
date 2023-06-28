#include "shell.h"

/**
 * constructCommandPath - A function to construct the command path
 * when the command is provided without its path.
 * 
 * @commandPath: where the constructed command path is stored.
 * @command: the command whose path is to be generated.
 *
 * Return: void
 * /
 
 
 /* We made a change here - resolved local variable issue for 'commandPath' */
 
void constructCommandPath(char commandPath[], char *command)
 {
     char *envPaths = NULL;
     char *path = NULL;
     struct stat statbuf;

     envPaths = strdup(getenv("PATH"));
     path = strtok(envPaths, ":");

     while (path != NULL)
     {
         strcpy(commandPath, path);
         strcat(commandPath, "/");
         strcat(commandPath, command);
         strcat(commandPath, "\0");

         if (stat(commandPath, &statbuf) == 0)
         {
             break;
         }
        /* Possible memory leak is NULL enough to free commandPath? where did the previous assignments go? */
         commandPath = NULL;
         path = strtok(NULL, ":");
     }

     free(envPaths);

     if (commandPath != NULL)
     {
         return;
     }

     perror("Did not find a valid path for command!");
     return;
 }