#include "main.h"



int main(void)
{
	char prompt[] = "$: ";
	char *lineptr = NULL;
	char *lp_cpy = NULL;
	char *tokVal = NULL;
	size_t gline_out = 0;
	size_t n = 0;
	char *delim = " \n";

	while(1)
	{
		printf("%s", prompt);

		gline_out = getline(&lineptr, &n, stdin);
			if (gline_out == -1)
				return (-1);
		printf("Input is %s and its size is: %lu\n", lineptr, gline_out);

		lp_cpy = strdup(lineptr);
		if (lp_cpy == NULL)
		{
			perror("error");
			return (-1);
		}

	}
		free(lineptr);

	return (0);
}
