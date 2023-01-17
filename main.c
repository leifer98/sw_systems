#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
	// pnode *head = (pnode *)malloc(sizeof(node));
	pnode *head = (pnode *)calloc(1, sizeof(node));

	int check;
	char c; // c the input from the user, ch1 for whitespace chars we will get in adition
	check = scanf(" %c", &c);

	while (c != 'E' && c != EOF && check == 1)
	{
		if (getchar() == EOF)
			break;
		if (c == 'A')
		{
			if (*(head) != NULL)
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
			if (check != 1)
				break;
		}
		else if (c == 'T')
		{
			if (*(head) != NULL)
				break;
			TSP_cmd(*head);
			check = scanf(" %c", &c);
			if (check != 1)
				break;
		}
		else if (c == 'S')
		{
			if (*(head) != NULL)
				break;
			shortsPath_cmd(*head);
			check = scanf(" %c", &c);
			if (check != 1)
				break;
		}
	}
	deleteGraph_cmd(head);
	free(head);
	return 0;
}