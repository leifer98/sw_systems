#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
    pnode source;
    struct edge_ *nextB;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    int distance;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

pedge newEdge(int weight, pnode endpoint, pedge next);
pnode newNode(int num,pedge edges,pnode next);
void build_graph_cmd(pnode *head);
char insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head, int node_num);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

#endif
