#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// void redirect_function(char ch, pnode *head)
// {
//     if (ch == 'A')
//     {
//         build_graph_cmd(head);
//     }
//     else if (ch == 'B')
//     {
//         build_graph_cmd(head);
//     }
//     else if (ch == 'C')
//     {
//         build_graph_cmd(head);
//     }
//     else if (ch == 'D')
//     {
//         build_graph_cmd(head);
//     }
//     return;
// }

pnode newNode(int num, pedge edges, pnode next)
{
    pnode p = (pnode)malloc(sizeof(node));
    if (p == NULL) exit(-1);
    p->node_num = num;
    p->edges = edges;
    p->next = next;
    return p;
}

pedge newEdge(int weight, pnode endpoint, pedge next)
{
	pedge p = (pedge)malloc(sizeof(edge));
    if (p == NULL) exit(-1);
    p->weight = weight;
    p->endpoint = endpoint;
    p->next = next;
    return p;
}

// void build_graph_cmd(pnode *head)
// {
//     char ch;
//     int amount;
//     scanf("%d", amount);
//     pnode *prev = NULL;
//     for (int i = amount; i > 0; i--)
//     {
//         *prev = newNode(i, NULL, prev);
//     }
//     *head = newNode(0, NULL, prev);

//     scanf("%c", ch);
//     while (ch == 'n')
//     {
//         int node_num;
//         char dest, weight;
//         scanf("%d", node_num);
//         pedge *prev = NULL;
//         while (1)
//         {
//             scanf("%c", ch);
//             if (ch - '0' < 0 || ch - '0' > 9)
//                 break;
//             scanf("%c", weight);
//             pedge *prev = newEdge(weight - '0', getNodeById(ch - '0', head), prev);
//         }
//         pnode *temp = getNodeById(ch - '0', head);
//         *temp->edges = prev;
//     }
//     redirect_function(dest);
// }
// void insert_node_cmd(pnode *head)
// {
// }
// void delete_node_cmd(pnode *head)
// {
// }
void printGraph_cmd(pnode head)
{

}
void printNode_cmd(pnode head)
{
    printf("head - ");
	printf("node_num: %d |", head->node_num);
	if (head->edges == NULL)
		printf("edges: NULL |");
	else {
		printf("edges: %p |", head->edges);
    }
	if (head->next == NULL)
		printf("next: NULL |");
	else
		printf("next: %p \n", head->next);
}
// // for self debug
// void deleteGraph_cmd(pnode *head)
// {
// }

// void shortsPath_cmd(pnode head)
// {
// }

// void TSP_cmd(pnode head)
// {
// }
