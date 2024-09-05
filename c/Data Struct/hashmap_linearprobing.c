/* HASH MAP WITH LINEAR PROBING 
   If a collision is detected
    loop:
        increament index by 1
        find for Null pointers in the hashtable
            if find:
                add the data in it
            else
                repeat process until find a null pointer 

    CODE BY OSMIC: 0smic.github.io (website)
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define NAME_BUFFER 20
#define TABLE_SIZE 10
#define DELETE_NODE (person*)0xFFFFFFFFFFFUL

typedef struct {
    char name[NAME_BUFFER];
    int age;
    // other data can be added
} person;

person * hash_table[TABLE_SIZE];

// ALL THE FUNCTION
person *hash_table_lookup(char *name);
void init_hash_table();
void print_table();
bool hash_map_insert(person *p);
person *hash_table_lookup(char *name);
person *delete_a_hash(char *name);


int main(void){
    init_hash_table();
    print_table();

    person gokul = {.name="Osmic", .age=19};
    person osmic = {.name="clang", .age=22};
    person trader = {.name="trader", .age=13};
    person dev = {.name="developer", .age=12};
    hash_map_insert(&gokul);
    hash_map_insert(&osmic);
    hash_map_insert(&trader);
    hash_map_insert(&dev);
    print_table();
    

    printf("\n");
    delete_a_hash("trader");
    print_table();
    delete_a_hash("dev");
    print_table();

    person *tmp = hash_table_lookup("dev");
    if (tmp !=NULL){
        printf("WE found it");
    }else{
        printf("Not here mahnn");
    }
    return 0;
}

// create a hash value for indexing in the hash table
unsigned int hash(char *name){
    int length = strnlen(name, NAME_BUFFER);
    unsigned int hash_value = 0;
    for (int i = 0; i<length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;  
}

// initialize all the struct in the table to NULL
void init_hash_table(){
    for(int i =0; i<TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
}

// Print the hashtable
void print_table(){
    printf("\nSTART\n");
    for (int i = 0; i<TABLE_SIZE; i++){
        if (hash_table[i] == NULL){
            printf("\t%i \t\n", i);
        }else if (hash_table[i] == DELETE_NODE){
            printf("\t%i  DELELTED NODE\n", i);
        }
        else {
            printf("\t%i --> %s\n",i, hash_table[i]->name);
        }
    }
    printf("\nEND\n");
}

// insert a new struct in table and also deal the collision with linear probing.
bool hash_map_insert(person *p){
    if (p == NULL) return false;
    int index = hash(p->name);
    printf("\n %d ----> %s", index, p->name);
    for (int i = 0; i<TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL){
            hash_table[try] = p;
            return true;
        }
    }
    return false;  
}

// Checks if a struct in the table or not
person *hash_table_lookup(char *name){
    int index = hash(name);
    for (int i =0; i<TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == DELETE_NODE) return NULL;
        if (hash_table[try] != NULL && strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0){
            return hash_table[index];
        }
    }
    return NULL;
}

// remove a struct from the hashtable and set it NULL
person *delete_a_hash(char *name){
    int index = hash(name);
    for (int i = 0; i< TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if(hash_table[try] == NULL) return NULL;
        if (hash_table[try] == DELETE_NODE) continue;
        if(hash_table[try] != NULL && strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0){
            person *tmp = hash_table[try];
            hash_table[index] = DELETE_NODE;
            return tmp;
        }
    
    }

}
