#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

/*String Functions*/
int _strlen(char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);

char *findpath(char *command);
int endprog(char *command);
void _env(char *tmpenv);
void empty(char *argv[]);
void _fork(char *argv[]);
void _write(char *str);


#endif
