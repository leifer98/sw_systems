#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

void redirect_function(char ch, pnode *head);
pnode getNodeById(int id, pnode head);
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
