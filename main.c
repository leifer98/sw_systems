#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
	pnode *head = (pnode *)malloc(sizeof(node));

	char c; // c the input from the user, ch1 for whitespace chars we will get in adition
	scanf(" %c", &c);
	printf("12. got char from input: %c\n", c);
	if (c == 'A')
	{
		build_graph_cmd(head);
		scanf(" %c", &c);
		printf("14. got char from input: %c\n", c);
		while (c == 'n')
		{
			c = insert_node_cmd(head);
		}
		printGraph_cmd(*head);
	}
	if (c == 'B')
	{
		c = insert_node_cmd(head);
		printGraph_cmd(*head);
	}
	if (c == 'S')
	{
		shortsPath_cmd(*head);
		scanf(" %c", &c);
		printf("20. got char from input: %c\n", c);
	}
	if (c == 'T')
	{
		TSP_cmd(*head);
	}

	// freeing all nodes
	free(*head);
	return 0;
}