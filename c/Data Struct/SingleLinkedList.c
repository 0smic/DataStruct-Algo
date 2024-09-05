/*
    CODE BY OSMIC: 0smic.github.io (website)
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

typedef struct node node_t;
node_t *createNewNode(int value); // create a new node
void print_node(node_t *head); // print all the node from head to tail
void free_mem(node_t *head); // free memory of all the nodes
node_t *node_mid(node_t *after_node, node_t *new_node); // creates nodes in the middle of other nodes
void insert_at_head(node_t **head, node_t *node_to_insert); // insert node in the head
node_t *find_node(node_t *head, int value); // help to find a node

int main(){
    node_t *tmp;
    node_t *head = NULL;
    for (int i =0; i<10; i++){
        tmp = createNewNode(i);
        tmp->next = head;
        head = tmp;
    }
    print_node(head);
    tmp = find_node(head, 5);

    printf("\n found the node : %d\n", tmp->value);

    free_mem(head);
    head = NULL;
    return 0;
}

node_t *createNewNode(int value){
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

void print_node(node_t *head){
    node_t *tmp = head;
    printf("\n");
    while (tmp != NULL){
        printf("%d -", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void insert_at_head(node_t **head, node_t *node_to_insert){
    node_to_insert->next = *head;
    *head = node_to_insert;
}

node_t *find_node(node_t *head, int value){
    node_t *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == value) return tmp;
        tmp = tmp->next;
    }
    return NULL;  
}

void free_mem(node_t *head){
    node_t *tmp;
    while(head != NULL){
        printf("\nFree the node: %d ", head->value);
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

node_t *node_mid(node_t *after_node, node_t *new_node){
    new_node->next =  after_node->next;
    after_node->next = new_node;
}