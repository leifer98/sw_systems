#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
    printf("distance: %d |", head->distance);
    if (head->next == NULL)
        printf("next: NULL | \n");
    else
    {
        printf("next: %p | \n", head->next);
        printGraph_cmd(head->next);
    }
}
pnode newNode(int num, pedge edges, pnode next)
{
    pnode p = (pnode)malloc(sizeof(node));
    if (p == NULL)
        return NULL;
    p->node_num = num;
    p->edges = edges;
    p->next = next;
    return p;
}

pedge newEdge(int weight, pnode endpoint, pedge next)
{
    pedge p = (pedge)malloc(sizeof(edge));
    if (p == NULL)
        return NULL;
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
    // printGraph_cmd(*head);
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
    // printf("15. got digit from input: %d\n", i);
    pnode pTheOne = *head;
    while (pTheOne->node_num != i && pTheOne->next != NULL)
    {
        pTheOne = pTheOne->next;
    }

    if (pTheOne->node_num != i)
    {
        pnode new = newNode(i, NULL, NULL);
        pTheOne->next = new;
        pTheOne = new;
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
        // printf("16. got string from input: %s\n", s);
        if (s[0] < '0' || s[0] > '9')
            return s[0];

        result = scanf(" %d", &i);
        if (result != 1)
        {
            printf("Invalid input\n");
            exit(-1);
        }
        // printf("17. got digit from input: %d\n", i);
        int weight = i, dest = atoi(s);

        pnode p = *head;
        while (p->node_num != dest)
        {
            p = p->next;
        }
        prev = newEdge(weight, p, pTheOne->edges);
    }
    return 'a';
}
void shortsPath_cmd(pnode head)
{
    int i;
    int result = scanf(" %d", &i);
    if (result != 1)
    {
        printf("Invalid input\n");
        exit(-1);
    }
    printf("18. got digit from input: %d\n", i);
    int sourceP = i;
    result = scanf(" %d", &i);
    if (result != 1)
    {
        printf("Invalid input\n");
        exit(-1);
    }
    printf("19. got digit from input: %d\n", i);
    int destP = i;

    // Initialize distances and edges for nodes
    pnode p = head;
    pedge eList = NULL;
    pedge prev = NULL;
    while (p != NULL)
    {
        if (p->node_num == sourceP)
        {
            p->distance = 0;
        }
        else
        {
            p->distance = INT_MAX;
        }
        if (p->edges != NULL)
        {
            pedge e = p->edges;
            while (e != NULL)
            {
                if (eList == NULL)
                    eList = e;
                else
                {
                    prev->nextB = e;
                }
                prev = e;
                e->source = p;
                e = e->next;
            }
        }
        p = p->next;
    }
    // printf("finished initiation 45 \n");

    // // Relax edges repeatedly
    p = head;
    while (p != NULL)
    {
        pedge e = eList;
        while (e != NULL)
        {
            pnode u = e->source;
            pnode v = e->endpoint;
            int uDist = u->distance;
            int vDist = v->distance;
            int weight = e->weight;
            if ((uDist != INT_MAX) && (uDist + weight < vDist))
                v->distance = uDist + weight;
            e = e->nextB;
        }
        p = p->next;
    }

    pnode pTheOne = head;
    // printGraph_cmd(head);
    while (pTheOne->node_num != destP)
    {
        pTheOne = pTheOne->next;
    }

    if (pTheOne->distance == INT_MAX)
    {
        printf("%d to %d is : %d\n", sourceP, destP, -1);
    }
    else
    {
        printf("%d to %d is : %d\n", sourceP, destP, pTheOne->distance);
    }
}

void TSP_cmd(pnode head)
{
    int i;
    int result = scanf(" %d", &i);
    if (result != 1)
    {
        printf("Invalid input\n");
        exit(-1);
    }
    printf("21. got digit from input: %d\n", i);
    int length = i-1;
    int *arr = (int*)malloc((sizeof(int)*length));
    while (length > -1)
    {
        result = scanf(" %d", &i);
        if (result != 1)
        {
            printf("Invalid input\n");
            exit(-1);
        }
        printf("22. got digit from input: %d\n", i);
        arr[length] = i;
        length--;
    }

    free(arr);
}
// // for self debug
// void deleteGraph_cmd(pnode *head)
// {
// }
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
