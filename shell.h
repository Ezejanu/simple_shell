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
#define MAX_TOKENS 1024
/* char *prompt = "our shell $: "; */

/*Functions*/

/* Parse Function */
void parseUserInput(char *userInput, char *tokenizedCommand[]);
int executeCommand(char *tokenizedCommand[], char *env[]);

/* Built ins */
int shouldExit(char *command);
void _printEnv(void);
int isEnvCommand(char *command);

/* Execute Functions */
void executeGenericCommand(char *tokenizedCommand[], char *env[]);
void constructCommandPath(char *commandPath, char *command);
void duplicateArray(char *duplicateArray[], char *originalArray[]);
void _fork(char *tokenizedCommand[], char *env[]);

/* Helper Functions*/
void _write(char *str);
void freeTokenizedCommand(char **tokenizedCommand);

#endif
