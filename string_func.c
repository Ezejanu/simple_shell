#include "main.h"

/**
 * _strcpy - A function that copies a string pointed to by @src, including
 *           the terminating null byte, to a buffer pointed to by @dest.
 * @dest: A buffer to copy the string to.
 * @src: The source string to copy.
 *
 * Return: A pointer to the destination string @dest.
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - Function that concatenates two strings
 * @dest: String 1
 * @src: String 2
 * Return: concatenated character
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, dest_len = 0;

	while (dest[i++])
		dest_len++;

	for (i = 0; src[i]; i++)
		dest[dest_len++] = src[i];

	return (dest);
}

/**
 * _strdup - Function to duplicate a string
 * @str: String to be duplicated
 *
 * Return: pointer to the duplicated string
 */

char *_strdup (char *str)
{
	int i, length;
	char *duplicate;

	length = strlen(str);
	duplicate = malloc(length + 1);

	for (i = 0; str[i]; i++)
	{
		duplicate[i] = str[i];
	}
	duplicate[i] = '\0';

	return (duplicate);
}

