#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
	pnode *head = (pnode *)malloc(sizeof(node));

	char c; // c the input from the user, ch1 for whitespace chars we will get in adition
	scanf(" %c", &c);

	while (c != 'E' && c != EOF)
	{
		if (getchar() == EOF) break;
		if (c == 'A')
		{
			deleteGraph_cmd(head);
			build_graph_cmd(head);
			scanf(" %c", &c);
			while (c == 'n')
			{
				c = insert_node_cmd(head);
			}
		}
		else if (c == 'B')
		{
			c = insert_node_cmd(head);
		}
		else if (c == 'D')
		{
			int i;
			scanf(" %d", &i);
			delete_node_cmd(head,i);
			scanf(" %c", &c);
		}
		else if (c == 'T')
		{
			TSP_cmd(*head);
			scanf(" %c", &c);
		}
		else if (c == 'S')
		{
			shortsPath_cmd(*head);
			scanf(" %c", &c);
		}
	}
	deleteGraph_cmd(head);
	return 0;
}
	// if (c == 'A')
	// {
	// 	build_graph_cmd(head);
	// 	scanf(" %c", &c);
	// 	// printf("14. got char from input: %c\n", c);
	// 	while (c == 'n')
	// 	{
	// 		c = insert_node_cmd(head);
	// 	}
	// 	// printGraph_cmd(*head);
	// }
	// if (c == 'B')
	// {
	// 	c = insert_node_cmd(head);
	// 	// printGraph_cmd(*head);
	// }
	// if (c == 'T')
	// {
	// 	TSP_cmd(*head);
	// 	scanf(" %c", &c);
	// }
	// if (c == 'S')
	// {
	// 	shortsPath_cmd(*head);
	// 	scanf(" %c", &c);

	// 	// printf("20. got char from input: %c\n", c);
	// }
	// printGraph_cmd(*head);
	// delete_node_cmd(head, 2);
	// printGraph_cmd(*head);

	// // freeing all nodes
	// deleteGraph_cmd(head);
	// printGraph_cmd(*head);