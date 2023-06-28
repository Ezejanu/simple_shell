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

/* Built ins */
int shouldExit(char *command);
void _printEnv();
void isEnvCommand(char *command);

/* Execute Functions */

void executeGenericCommand(char *tokenizedCommand[], char *env[]);
void constructCommandPath(char commandPath[], char *command);
void duplicateArray(char *duplicateArray[], char *originalArray[]);

/* Helper Functions*/
void _write(char *str);
#endif