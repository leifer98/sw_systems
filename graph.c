#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void printGraph_cmd(pnode head)
{
    printf("node_num: %d | edges:", head->node_num);
    pedge e = head->edges;
    while (e != NULL)
    {
        printf(" endpoint = %d, weight = %d,", (e->endpoint)->node_num, e->weight);
        e = e->next;
    }
    printf(" NULL | ");
    if (head->next == NULL)
        printf("next: NULL |\n");
    else
    {
        printf("next: %p \n", head->next);
        printGraph_cmd(head->next);
    }
}
pnode newNode(int num, pedge edges, pnode next)
{
    pnode p = (pnode)malloc(sizeof(node));
    if (p == NULL)
        exit(-1);
    p->node_num = num;
    p->edges = edges;
    p->next = next;
    return p;
}

pedge newEdge(int weight, pnode endpoint, pedge next)
{
    pedge p = (pedge)malloc(sizeof(edge));
    if (p == NULL)
        exit(-1);
    p->weight = weight;
    p->endpoint = endpoint;
    p->next = next;
    return p;
}

void build_graph_cmd(pnode *head)
{
    // char c, ch1; // c the input from the user, ch1 for whitespace chars we will get in adition
    int i;
    int result = scanf(" %d", &i);
    if (result != 1)
    {
        printf("Invalid input\n");
        return;
    }
    printf("13. got digit from input: %d\n", i);

    pnode prev, curr = NULL;
    i--;
    while (i > 0)
    {
        prev = curr;
        curr = newNode(i, NULL, prev);
        i--;
    }
    *head = newNode(0, NULL, curr);
    printGraph_cmd(*head);
}
char insert_node_cmd(pnode *head)
{
    int i;
    int result = scanf(" %d", &i);
    if (result != 1)
    {
        printf("Invalid input\n");
        exit(-1);
    }
    printf("15. got digit from input: %d\n", i);

    pnode pTheOne = *head;
    while (pTheOne->node_num != i)
    {
        pTheOne = pTheOne->next;
    }
    pedge prev = NULL;
    while (1)
    {
        pTheOne->edges = prev;
        
        char s[100];
        result = scanf(" %s", s);
        if (result != 1)
        {
            printf("Invalid input\n");
            return 0;
        }
        printf("16. got string from input: %s\n", s);
        if (s[0] < '0' || s[0] > '9')
            return s[0];

        result = scanf(" %d", &i);
        if (result != 1)
        {
            printf("Invalid input\n");
            exit(-1);
        }
        printf("17. got digit from input: %d\n", i);
        int dest = i, weight = atoi(s);

        pnode p = *head;
        while (p->node_num != dest)
        {
            p = p->next;
        }
        prev = newEdge(weight,p,pTheOne->edges);
    }
    return 'a';
}
void delete_node_cmd(pnode *head, int node_num)
{
    pnode prev = *head;
    pnode p = *head;
    while (p->node_num != node_num)
    {
        prev = p;
        p = p->next;
    }
    prev->next = p->next;
    pedge e_root = p->edges;

    while (e_root->next != NULL)
    {
        pedge e = e_root;
        pedge e_prev = e_root;
        while (e->next != NULL)
        {
            e_prev = e;
            e = e->next;
        }
        e_prev->next = NULL;
        e->endpoint = NULL;
        free(e);
    }
    p->edges = NULL;
    e_root->endpoint = NULL;
    free(e_root);
    free(p);
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
