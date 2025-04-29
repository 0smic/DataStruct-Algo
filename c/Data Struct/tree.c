#include<stdio.h>
#include<stdlib.h>

typedef struct treenode {
   int value;
   struct treenode *left;
   struct treenode *right;
} treenode_t;

treenode_t* createnode(int);
void printtree(treenode_t*);
void main(){
    treenode_t *n1 = createnode(10);
    treenode_t *n2 = createnode(11);
    treenode_t *n3 = createnode(12);
    n1->left = n2;
    n2->right = n3;
    printtree(n1);
}

treenode_t* createnode(int value){
    treenode_t *node = malloc(sizeof(treenode_t));
    if (node == NULL){
        printf("allocation error!!");
        return NULL;
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool insertNode(int value,treenode_t **root){
    if(*root == NULL){
        *root = createnode(value);
        return true;
    }
    if ((*root)->value == value){
        return false;
    }
    else if ((*root)->value < value){
        return insertNode(value,&((*root)->right));
    }

    else if ((*root)->value > value){
            return insertNode(value,&((*root)->left))
    }


    
}

void printtree(treenode_t *root){
    if (root == NULL){
        printf("---NULL---\n");
        return;
    }
    printf("value %d\n",root->value);
    printf("LEFT: \n");
    printtree(root->left);
    printf("RIGHT: \n");
    printtree(root->right);
    
    
}
