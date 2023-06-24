#include "shell.h"
#include "printf.h"

/**
 * empty - A function to free argv
 * @argv: pointer to the array of strings containing the path needed to execute
 * return: void
 */

void empty(char *argv[])
{
	size_t i;

	for (i = 0; argv[i]; i++)
	{
		argv[i] = NULL;
	}
}
