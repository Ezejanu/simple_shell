#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

extern char **environ;
/* char *prompt = "our shell $: "; */

/*Functions*/
/* Parse Function */
void parseUserInput(char *tokenizedCommand[], char *userInput);
int executeCommand(char *tokenizedCommand[], char *env[]);

/* Helper Functions*/
void _write(char *str);
#endif