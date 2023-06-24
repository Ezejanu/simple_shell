#include "main.h"

/**
 * tokcommand - a function to
 * @command: the string to be tokenised
 * @delim: the delimeter to be used
 * Return: a pointer to the tokenised array
 */

char ** tokcommand(char *command, char *delim)
{
	char *commtoken, *argtoken;
	char *argv[1024];
	int i;

	commtoken = strtok(command, delim);
	argtoken = strtok(commtoken, " ");
	for (i = 0; argtoken; i++)
	{
		argv[i] = argtoken;
		argtoken = strtok(NULL, " ");
	}
	argv[i] = NULL;
	return (argv);
}
