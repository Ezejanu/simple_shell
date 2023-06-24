#include "main.h"

/**
 * endprog - a function to end and exit our simple shell
 * @command: command to compare if exit
 * Return: 0 if it isn't a match, 1 it is a match
 */

int endprog(char *command)
{
	int i;
	char *Exit = "exit";
	char *msg = "exit\n\n[Disconnected...]\n";

	if (strlen(command) != 4)
		return (0);

	for (i = 0; i < 4; i++)
	{
		if (command[i] != Exit[i])
			return (0);
	}
	_write(msg);
	return (1);
}

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
