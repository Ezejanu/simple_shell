#include "main.h"


typedef struct node{
	char *data;
	struct node *next;
}list;

int main(void)
{
	char *path, *token, *delim = "/";
	list *head, *newNode, *tmp;


/**
	path = getenv("PATH");
	token = strtok(path, delim);
	printf("%s\n", token);
	while (token = strtok(NULL, delim))
	{
			printf("%s\n", token);
	}
			return (0);
*/


	head = (list*)malloc(sizeof(list));
	if (head == NULL)
	{
		printf("error, malloc unsuccessful");
		return (1);
	}
	
	path = getenv("PATH");
	token = strtok(path, delim);
	head->data = token;
	head->next = NULL;
	tmp = head;

	printf("%s\n", tmp->data);

	 while (token = strtok(NULL, delim))
	 {
		 newNode = (list*)malloc(sizeof(list));
		 newNode->data = token;
		 newNode->next = NULL;
		 tmp->next = newNode;
		 tmp = tmp->next;

		 printf("%s\n", tmp->data);
	 }
	return (0);
}
