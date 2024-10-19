#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

typedef struct node node_t;

node_t *head = NULL;

node_t* createNewNode(int value){
    node_t *newnode = malloc(sizeof(node_t));
    newnode->value = value;
    newnode->next = NULL;
    return newnode;
}
void printnode(node_t *head){
    node_t *tmp = head;
    int count = 0;
    printf("\nSTART\n");
    while (tmp != NULL){
        printf("\nnode -> %d",tmp->value);
        count++;
        tmp = tmp->next;
    }
    printf("\nEnd\n");

}

bool push(int value){
    node_t *newnode = createNewNode(value);
    if (newnode == NULL) return false;
    newnode->next = head;
    head = newnode;
    return true;
    
}

int pop(){
    if (head == NULL) return INT_MIN;
    int result = head->value;
    node_t *remove_node = head;
    head = remove_node->next;
    free(remove_node);
    return result;
}

int main(void){
    node_t *tmp;
    for (int i = 0; i<4; i++){
        tmp = createNewNode(i);
        tmp->next = head;
        head = tmp;
    }
    push(234);
    printnode(head);
    pop();
    printnode(head);
    return 0;
}