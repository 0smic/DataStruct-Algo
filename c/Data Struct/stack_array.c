#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

int stack[STACK_LENGTH];
int top = EMPTY;

bool push(int value){
    if (top >= STACK_LENGTH-1) return false;
    top++;
    stack[top] = value;
    return true;

}

int pop(){
    if (top == EMPTY) return STACK_EMPTY;
    int result = stack[top];
    top--;
    return result;
}
int main(){
    push(343);
    push(234);
    printf("stack2: %d", stack[4]);
    pop();
}