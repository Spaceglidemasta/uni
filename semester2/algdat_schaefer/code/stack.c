#include "stack.h"
#include <stdlib.h>

struct Stack{

    int data[STACK_SIZE];
    int top;

};

struct Stack* stack_init() {
    struct Stack* s = malloc(sizeof(struct Stack));
    s->top = STACK_TOP;
    return s;
}

void stack_push(struct Stack* current, int x){

    if(current -> top == STACK_SIZE){
        printf("Stack Overflow");
        return;
    }


    for(int i = STACK_SIZE - 1; i > 0; i--){
        current -> data[i] = current -> data[i - 1];
    }
    
    current -> data[0] = x;
    current -> top++;
}

int stack_pop(struct Stack* current){
    
    if(current -> top == STACK_TOP){
        printf("Emtpy Stack");
        return;
    }


    int top = current -> data[0];

    for(int i = 0; i < STACK_SIZE - 1; i++){
        current -> data[i] = current -> data[i + 1];
    }

    return top;
}

void stack_delete(struct Stack** current){

    if(*current != NULL){
        for(int i = 0; i < STACK_SIZE; i++){
            (*current) -> data[i] = 0;
        }

        free(*current);
        *current = NULL;
    }

}