/* EXTERNAL CHAINING FOR COLLISION
    we will use linked list to store the collision data
    so it will be more easy to deal with (but not efficient)

    CODE BY OSMIC: 0smic.github.io (website)
    
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include  <stdbool.h>

#define TABLE_SIZE 30
#define NAME_BUFFER 20

struct person 
{
    char name[NAME_BUFFER];
    int age;
    struct person *next;
    // other data can be added
};
typedef struct person person_t;

person_t * hash_table[TABLE_SIZE];

 // ALL THE FUNC
unsigned int hash(char *name);
void printTable();
void init();
bool hash_map_insert(person_t *p);
person_t *find_person(char *name);
person_t *delete_node(char *name);

int main(void){
    init();
    // DATA ADDED FOR TESTING PURPOSE
    person_t Osmic = {.name="Osmic", .age=19};
    person_t osmic = {.name="osmic", .age=29};
    person_t trader = {.name="trader", .age=13};
    person_t dev = {.name="dev", .age=12};
    person_t clang = {.name="clang", .age=19};
    person_t linux = {.name="linux", .age=29};
    person_t kali = {.name="kali", .age=13};
    person_t mini = {.name="mini", .age=12};
    person_t skill = {.name="skill", .age=19};
    person_t prob = {.name="prob", .age=29};
    person_t listen = {.name="listen", .age=13};
    person_t mark = {.name="mark", .age=12};
    person_t spell = {.name="spell", .age=19};
    person_t seg = {.name="seg", .age=29};
    person_t bliss = {.name="bliss", .age=13};
    person_t info = {.name="info", .age=12};

    hash_map_insert(&Osmic);
    hash_map_insert(&osmic);
    hash_map_insert(&trader);
    hash_map_insert(&dev);
    hash_map_insert(&clang);
    hash_map_insert(&linux);
    hash_map_insert(&kali);
    hash_map_insert(&mini);
    hash_map_insert(&skill);
    hash_map_insert(&prob);
    hash_map_insert(&listen);
    hash_map_insert(&mark);
    hash_map_insert(&spell);
    hash_map_insert(&seg);
    hash_map_insert(&bliss);
    hash_map_insert(&info);
    printf("\n");
    find_person("Gokul");

    person_t *tmp = find_person("dev");
    if (tmp !=NULL){
        printf("WE found it");
    }else{
        printf("Not here mahnn");
    }

    printTable();
    delete_node("mark");
    printTable();
    return 0;
}

// create a unique(collision also happen ) hash value for the name(in parameter)
unsigned int hash(char *name){
    int length = strnlen(name, NAME_BUFFER);
    long int hash_value = 0;
    for (int i = 0; i<length;i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

// print the hash table and linked list in order of increasing index
void printTable(){
    person_t *tmp;
    int count;
    printf("\n");
    printf("\n START___\n");
    printf("\n");
    for(int i=0; i<TABLE_SIZE; i++){
        if(hash_table[i] == NULL){ 
            printf("\n%d ", i);
        }else {
            count =0;
            if (hash_table[i]->next == NULL){ 
                printf("\n%d --> %s", i, hash_table[i]->name);
            }else{ 
                printf("\nCOLLISON [%d]",i);
                tmp = hash_table[i];
                while(tmp!=NULL){
                    printf("\n \t %d ---> %s",count ,tmp->name);
                    tmp = tmp->next;
                    count++;
                }
            }
        }
    }
    printf("\n");
    printf("\n____END\n");
    printf("\n");
    printf("\n");
}

// initialize every node in the table to NULL
void init(){
    for(int i = 0; i< TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
}

// adds the node into to the hash table .if there is collision it will add in the linked list.
bool hash_map_insert(person_t *p){
    person_t *tmp;
    if (p==NULL) return false;
    int index = hash(p->name);
    printf("\n\t %d  ---> %s", index, p->name);
    p->next = hash_table[index];
    hash_table[index] = p;   
    return true;

}

// checks if the node is in hashtable for in the linked list
person_t *find_person(char *name){
    person_t *tmp;
    int index = hash(name);
    tmp = hash_table[index];
    while (tmp != NULL && strncmp(tmp->name,name,NAME_BUFFER) !=0){
        tmp = tmp->next;
    }
    return tmp;
}

// It will delete the node contain the name(given in parameter) even if is it in linked list 
person_t *delete_node(char *name){
    int index = hash(name);
    person_t *tmp = hash_table[index];
    person_t *prev = NULL;
    while(tmp != NULL && strncmp(tmp->name, name, NAME_BUFFER) != 0){
        prev = tmp;
        tmp = tmp->next;  
    }
    if (tmp == NULL) return NULL;
    if (prev== NULL){
        // node we are looking is head itself
        hash_table[index] = hash_table[index]->next;
        return tmp;
    }else {
        // node is somewhere in the middle
        prev->next = tmp->next;
        return tmp;
    }
    printf("\nwe got %s", prev->name);
    
}