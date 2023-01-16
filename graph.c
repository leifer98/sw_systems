#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

void printGraph_cmd(pnode head)
{
    if (head == NULL)
    {
        printf("the graph is empty!\n");
        return;
    }
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
    // printf("13. got digit from input: %d\n", i);

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
void belman_ford(pnode head, int sourceP)
{
    // initialization of added arrtibutes
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
    // Relax edges repeatedly
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
    // printf("18. got digit from input: %d\n", i);
    int sourceP = i;
    result = scanf(" %d", &i);
    if (result != 1)
    {
        printf("Invalid input\n");
        exit(-1);
    }
    // printf("19. got digit from input: %d\n", i);
    int destP = i;

    belman_ford(head, sourceP);

    pnode pTheOne = head;
    while (pTheOne->node_num != destP)
    {
        pTheOne = pTheOne->next;
    }

    // printGraph_cmd(head);
    if (pTheOne->distance == INT_MAX)
    {
        printf("Dijsktra shortest path: %d\n", -1);
    }
    else
    {
        printf("Dijsktra shortest path: %d\n", pTheOne->distance);
    }
}
int permute(pnode *arr, int start, int end, int *distances, pnode *arrOriginal)
{
    int i;
    if (start == end)
    {
        // print the permutation
        for (i = 0; i <= end; i++)
        {
            // printf("%d ", arr[i]->node_num);
        }
        // printf(" | ");
        // sums the permutation
        int sum = 0;
        for (i = 0; i < end; i++)
        {
            int k = 0, j = 0;
            while (arr[i]->node_num != arrOriginal[j]->node_num)
            {
                j++;
            }
            while (arr[i + 1]->node_num != arrOriginal[k]->node_num)
            {
                k++;
            }
            // printf("(%d,%d)", arrOriginal[j]->node_num, arrOriginal[k]->node_num);
            if (*(distances + j * (end + 1) + k) != INT_MAX)
            {
                // printf(" %d -> ", *(distances + j * (end + 1) + k));
                sum += *(distances + j * (end + 1) + k);
            }
            else
            {
                // printf(" INFINITY | ");
                sum = *(distances + j * (end + 1) + k);
                break;
            }
        }
        // printf("| sum  = %d\n", sum);
        return sum;
    }
    int sum = INT_MAX;
    for (i = start; i <= end; i++)
    {
        // swap the current element with the start element
        pnode temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;

        // recursively permute the remaining elements
        int num = permute(arr, start + 1, end, distances, arrOriginal);
        if (num < sum)
            sum = num;
        // swap the elements back
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
    }
    return sum;
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
    // printf("21. got digit from input: %d\n", i);
    pnode *arr = (pnode *)malloc((sizeof(pnode) * i));
    pnode *arrOriginal = (pnode *)malloc((sizeof(pnode) * i));
    int countdown = i - 1;
    int length = i;
    while (countdown > -1)
    {
        result = scanf(" %d", &i);
        if (result != 1)
        {
            printf("Invalid input\n");
            exit(-1);
        }
        // printf("22. got digit from input: %d\n", i);

        pnode pTheOne = head;
        while (pTheOne->node_num != i)
        {
            pTheOne = pTheOne->next;
        }
        arr[countdown] = (pnode)(pTheOne);
        arrOriginal[countdown] = (pnode)(pTheOne);
        countdown--;
    }
    int *distances = (int *)malloc(length * length * sizeof(int));
    for (int j = 0; j < length; j++)
    {
        belman_ford(head, arr[j]->node_num);
        for (int k = 0; k < length; k++)
        {
            *(distances + j * length + k) = arr[k]->distance;
        }
    }

    // for (int i = 0; i < length; i++)
    // {
    //     for (int j = 0; j < length; j++)
    //     {
    //         printf("%d ", *(distances + i * length + j));
    //     }
    //     printf("\n");
    // }

    int min = permute(arr, 0, length - 1, distances, arrOriginal);
    if (min == INT_MAX) printf("TSP shortest path: %d\n", -1);
    else printf("TSP shortest path: %d\n", min);
    free(distances);
    free(arrOriginal);
    free(arr);
}
void delete_edge(pnode head, int node_num)
{
    // TODO need to verify there isn't an edge such that edge->nextB = e
    pedge e = head->edges;
    pedge prev = NULL;
    while (e != NULL && e->endpoint->node_num != node_num)
    {
        prev = e;
        e = e->next;
    }
    if (e != NULL)
    {
        if (prev != NULL)
        {
            prev->next = e->next;
        }
        else
        {
            head->edges = e->next;
        }
        e->nextB = NULL;
        e->endpoint = NULL;
        free(e);
    }
}

void delete_node_cmd(pnode *head, int node_num)
{
    // deleting all nextB arrtibutes so it wont interupt the free function
    pnode prev = *head;
    pnode p = *head;

    while (p != NULL)
    {
        pedge e = p->edges;

        while (e != NULL)
        {
            e->nextB = NULL;
            e = e->next;
        }
        // deleting all edges of p pointing onto requested node
        delete_edge(p, node_num);
        p = p->next;
    }
    // finding the requested node
    prev = *head;
    p = *head;

    while (p->node_num != node_num)
    {
        prev = p;
        p = p->next;
    }
    if (p->node_num == (*head)->node_num)
        *head = p->next;
    else
        prev->next = p->next;
    pedge e_root = p->edges;
    while (e_root != NULL && e_root->next != NULL)
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
        e->source = NULL;
        e->nextB = NULL;
        free(e);
    }
    p->edges = NULL;
    p->next = NULL;
    if (e_root != NULL)
        e_root->endpoint = NULL;

    free(e_root);
    free(p);
}
void deleteGraph_cmd(pnode *head)
{
    while ((*head) != NULL)
    {
        delete_node_cmd(head, (*head)->node_num);
    }
}
