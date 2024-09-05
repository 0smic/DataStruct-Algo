/* Note: It's a linked list which also have backward capabillity (doubly linked list).
            which means you can not only find the next node of the node but also the previous node of it
            It helps to simpifly things when deleting the node and other stuff
            
    CODE BY OSMIC: 0smic.github.io (website)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value;
    struct node *next;
    struct node *prev;
};

typedef struct node node_t;

bool freenode(node_t *nodeToFree);
node_t *createNewnode(int value);
void insertNodeatHead(node_t **head, node_t *nodetoinsert);
void delete_node(node_t **head, node_t *nodeToremove);
void printnodes(node_t *head);
node_t *find_node(node_t *head, int value);


int main(void){
    node_t *head = NULL;
    node_t *tmp;
    for (int i = 0; i<20; i++){
        tmp = createNewnode(i);
        insertNodeatHead(&head, tmp);
    }

    printnodes(head);
    tmp = find_node(head, 16);
    if (tmp) printf("\nwe Found %d", tmp->value);
    delete_node(&head, tmp);
    delete_node(&head, head);

    printf("\n");
    printnodes(head);
    return 0;
}

// free the memory of the specific node
bool freenode(node_t *nodeToFree){
    if (nodeToFree != NULL){
        free(nodeToFree);
        return true;
    }
    return false;
}

// allocate space for a new node and return the pointer of it
node_t *createNewnode(int value){
    node_t *newNode = malloc(sizeof(node_t));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// insert a node at the head of the linked list
void insertNodeatHead(node_t **head, node_t *nodetoinsert){
    nodetoinsert->next = *head;
    if (*head != NULL){
        (*head)->prev = nodetoinsert;
    }
    *head = nodetoinsert;
}

// Delete specific node 
void delete_node(node_t **head, node_t *nodeToremove){
    bool check;
    if (*head == nodeToremove && nodeToremove != NULL){
        *head = nodeToremove->next;
        if (*head != NULL){
            (*head)->prev = NULL;
        }

    }else {
        nodeToremove->prev->next = nodeToremove->next;
        if (nodeToremove->next != NULL){
            nodeToremove->next->prev = nodeToremove->prev;
        }
    }
    nodeToremove->next = NULL;
    nodeToremove->prev = NULL;
    
    if(freenode(nodeToremove)){
        printf("\nWe free the node");
    }else {
        printf("\n smtg wroung");
    }
    return;
       
}

// print the linked list
void printnodes(node_t *head){
    node_t *tmp = head;
    printf("\n START__\n");
    while (tmp != NULL){
        if (tmp->next == NULL ){
            printf("\ncurrent --> %d | next-pointer-value ---> NULL | previous- pointer --> %d",tmp->value, tmp->prev->value);
        }else if(tmp->prev == NULL){
            printf("\ncurrent --> %d | next-pointer-value ---> %d |  previous-pointer --> NULL",tmp->value, tmp->next->value);
        }
        else{
            printf("\ncurrent --> %d | next-pointer-value ---> %d | previous-pointer-value --> %d", tmp->value, tmp->next->value, tmp->prev->value);
        }
        
        tmp = tmp->next;
    }
    printf("\n END__\n");

}

// find node in the linked list and return it
node_t *find_node(node_t *head, int value){
    node_t *tmp = head;
    while (tmp !=NULL && tmp->value != value){
        tmp = tmp->next;   
    }
    if (tmp == NULL) return NULL;
    return tmp;
}