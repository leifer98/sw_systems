#include <stdio.h>

pnode getNodeById(int id, pnode *head) {
    while (*head->node_num != id) {
        head = *head->next;
    }
    return head;
}