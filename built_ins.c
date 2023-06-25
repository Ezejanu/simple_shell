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

	if (_strlen(command) != 4)
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
 * 
 */
void _printenv()
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
    {
        _write(environ[i]);
        _write("\n");
    }
}


/**
 * _env - a function to compare if command is 'env'
 * and print the environment if it is a match
 * @tmpenv: command to be compared and printed
 */

void _env(char *tmpenv)
{
	int i, comm_leng;
	struct stat statbuf;

	char *Env = "env";

	comm_leng = _strlen(tmpenv);
	if (comm_leng > 3)
	{
			if (tmpenv[comm_leng] == Env[3] && tmpenv[comm_leng - 1] == Env[2] && tmpenv[comm_leng - 2] == Env[1])
			{
					if (stat(tmpenv, &statbuf) == 0)
					{
						_printenv(tmpenv);
						return;
					}
			}
	}

	if (_strlen(tmpenv) != 3)
		return;
	
	for (i = 0; i < 3; i++)
	{
		if (tmpenv[i] != Env[i])
			return;
	}
	_printenv(tmpenv);
}
