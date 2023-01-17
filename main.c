#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
	pnode *head = (pnode *)malloc(sizeof(node));
	int check;
	char c; // c the input from the user, ch1 for whitespace chars we will get in adition
	check = scanf(" %c", &c);

	while (c != 'E' && c != EOF && check == 1)
	{
		if (getchar() == EOF)
			break;
		if (c == 'A')
		{
			deleteGraph_cmd(head);
			build_graph_cmd(head);
			scanf(" %c", &c);
			while (c == 'n')
			{
				c = insert_node_cmd(head);
				if (c == '0')
					break;
			}
		}
		else if (c == 'B')
		{
			c = insert_node_cmd(head);
			if (c == '0')
				break;
		}
		else if (c == 'D')
		{
			int i;
			scanf(" %d", &i);
			delete_node_cmd(head, i);
			check = scanf(" %c", &c);
			if (check != 1) break;
		}
		else if (c == 'T')
		{
			TSP_cmd(*head);
			check = scanf(" %c", &c);
			if (check != 1) break;
		}
		else if (c == 'S')
		{
			shortsPath_cmd(*head);
			check = scanf(" %c", &c);
			if (check != 1) break;
		}
	}
	deleteGraph_cmd(head);
	free(head);
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