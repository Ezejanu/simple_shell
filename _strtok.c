#include "main.h"

/**
 * _strtok - a function to extract tokens from a string
 * @delim: delimeter to be searched for
 *
 * Return: a pointer to a null-terminated string containing the next token
 * or NULL if no more tokens are found
 */

char *_strtok(char *str, char *delim)
{
	static char *remainder;
	char *token;
	int count;

	/* str = ourshell, by Ezejanu, and Aishah. */




