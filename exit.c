#include "main.h"

int endprog(char *command)
{
	int i;
	char *Exit = "exit";
	
	if (strlen(command) != 4)
		return(0);
	
	for(i = 0; i < 4; i++)
	{
		if(command[i] != Exit[i])
			return (0);
	}
	
	printf("exit\n\n[Disconnected...]\n");	
	return (1);
}
