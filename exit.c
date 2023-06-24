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
