#include "main.h"

/**
 * main - a function to print the environment
 * @ac: parameter not used
 * @av: parameter not used
 * @env: environment to be printed
 */

void _env(char *tmpenv)
{
	int i;
	char * Env = "env";

	if (strlen(tmpenv) != 3)
		return;

	for (i = 0; i < 3; i++)
	{
		if (tmpenv[i] != Env[i])
			return;
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return;
}
