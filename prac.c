#include "main.h"
extern char **environ;

int main(int ac, char **av, char **env)
{
	unsigned int i;
	struct stat st;
	char *name;
/*
	if (ac < 2)
		printf("Too few arguments\n");

	for (i = 1; av[i] != NULL; i++)
		{
			printf("%s\n", av[i]);
			if (stat(av[i], &st) == 0)
				printf("File \"%s\" found\n", av[i]);
			else
				printf("File \"%s\" not here\n", av[i]);
		}


	name = getenv("PATH");
	printf("%s\n", name);

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	putchar('\n');
	return (0);
*/


	printf("address of environ is: %p\n", environ);
	printf("address of env is: %p\n", env);
}
