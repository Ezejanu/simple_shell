#include "main.h"

/**
 * _env - a function to compare if command is 'env'
 * and print the environment if it is a match
 * @tmpenv: command to be compared and printed
 */

void _env(char *tmpenv)
{
	int i;
	char *Env = "env";

	if (strlen(tmpenv) != 3)
		return;

	for (i = 0; i < 3; i++)
	{
		if (tmpenv[i] != Env[i])
			return;
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		_write(environ[i]);
		_write("\n");
	}
}
