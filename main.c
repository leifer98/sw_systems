#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
	pnode *head;
	char c; // c the input from the user, ch1 for whitespace chars we will get in adition
	int result = scanf(" %c", &c);
	if (result != 1)
	{
		printf("Invalid input\n");
		return 0;
	}
	printf("12. got char from input: %c\n", c);
	if (c == 'A')
	{
		build_graph_cmd(head);
		result = scanf(" %c", &c);
		if (result != 1)
		{
			printf("Invalid input\n");
			return 0;
		}
		printf("14. got char from input: %c\n", c);
		while (c == 'n')
		{
			c = insert_node_cmd(head);
			printGraph_cmd(*head);
		}
	}

	// freeing all nodes
	free(*head);
	// pnode p = *head;
	// int length = 0;
	// while (p->next != NULL)
	// {
	// 	p = p->next;
	// 	length++;
	// }
	// for (int i = length; i >= 0; i--)
	// {
	// 	printf("i m freeing node number - %d\n", i);
	// 	delete_node_cmd(head, i);
	// 	printGraph_cmd(*head);
	// }
	return 0;
}

// // int i, j;
// while (c != 'D')
// {

// 		while (!scanf("%c", &c));
// 		printf("char = %d\n");
// 		while (c == 'n')
// 		{
// 			printf("hello i m in a loop\n");
// 			while (!scanf("%c", &c));
// 			printf("char = %c\n");
// 		}
// 	}
// 	else if (c == 'B')
// 	{
// 	}
// 	else if (c == 'S')
// 	{
// 	}
// 	else if (c == 'T')
// 	{
// 	}
// 	else
// 	{
// 		printf("\nnot correct input\n");
// 	}
// 	return 0;
// 	// scanf("%c%c", &ch1, &c);
// }

// pnode p1 = newNode(1,NULL,NULL);
// pedge e21 = newEdge(2,p1,NULL);
// pnode p2 = newNode(0,e21,NULL);
// insert_node_cmd(&p2,p1);
// printGraph_cmd(p2);
// delete_node_cmd(&p2,1);
// printGraph_cmd(p2);
// free(p2);
// free(e21);
// what dont i need to free it?