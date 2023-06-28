#include "main.h"

/**
 * _write - a function to print a string to the std out.
 * @str: string to be printed
 */

void _write(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		write(1, &str[i], 1);
}
