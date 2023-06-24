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

char * findpath(char * command);
int endprog(char *command);
void _env(char *tmpenv);
void empty(char *argv[]);
void _fork(char *argv[]);

#endif
