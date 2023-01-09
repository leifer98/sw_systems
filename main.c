#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


int main()
{
	pnode p1 = newNode(5,NULL,NULL);
	pedge e21 = newEdge(2,p1,NULL);
	pnode p2 = newNode(1,e21,p1);

	printf("p1 - \n");
	printf("node_num: %d\n", p1->node_num);
	if (p1->edges == NULL)
		printf("edges: NULL\n");
	else
		printf("edges: %p\n", p1->edges);
	if (p1->next == NULL)
		printf("next: NULL\n");
	else
		printf("next: %p\n", p1->next);


	printf("p2 - \n");
	printf("node_num: %d\n", p2->node_num);
	if (p2->edges == NULL)
		printf("edges: NULL\n");
	else
		printf("edges: endpoint = %d, weight = %d\n", ((p2->edges)->endpoint)->node_num, (p2->edges)->weight);
	if (p2->next == NULL)
		printf("next: NULL\n");
	else
		printf("next: %d\n", (p2->next)->node_num);

	free(p1);
	free(p2);
	free(e21);
	return 0;
}