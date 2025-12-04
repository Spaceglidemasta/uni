#include "stack.h"
#include "list.h"
#include <stdlib.h>

//List part
//-------------------------------------------------------------------

struct Item
{
    int x;
    struct Item* next;
};

struct Item* list_add_front(struct Item* current, int x) {
    struct Item* new_node = malloc(sizeof(struct Item));

    new_node -> x = x;
    new_node -> next = current;

    return new_node;
}

struct Item* list_tail(struct Item* current){
    if(current != NULL){
        return current -> next;
    }
    else{
        printf("Die Liste ist leer!");
        return NULL;
    }
}

int list_head(struct Item* current){
    if(current != NULL){
        return current -> x;
    }
    else{
        printf("Die Liste ist leer!");
        return -1;
    }
}

void list_delete(struct Item* current){
    if(current == NULL){
        printf("Liste ist bereits deleted!");
        return;
    }
    
    struct Item* next;
    while(current != NULL){
        next = current -> next;
        free(current);
        current = next;
    }
}

//-------------------------------------------------------------------

struct Stack{

    struct Item* data;
    int top;

};

struct Stack* stack_init() {
    struct Stack* s = malloc(sizeof(struct Stack));
    s->top = STACK_TOP;
    return s;
}

void stack_push(struct Stack* current_stack, int x){

    if(current_stack -> top == STACK_SIZE){
        printf("Stack Overflow");
        return;
    }

    current_stack -> data = list_add_front(current_stack -> data, x);
    
    current_stack -> top++;
}

int stack_pop(struct Stack* current){
    
    if(current -> top == STACK_TOP){
        printf("Emtpy Stack");
        return -1;
    }


    int top = current -> data -> x;

    current -> data = (current -> data -> next);

    return top;
}

void stack_delete(struct Stack** current_stack){

    if(*current_stack != NULL){

        struct Item* current_list = &((*current_stack) -> data);
        
        list_delete(current_list);

        free(*current_stack);
        *current_stack = NULL;
    }

}


//----------------Queue


struct Queue{
    
    struct Stack* out_stack;
    struct Stack* entry_stack;

};

void enqueue(struct Queue* q, int x){
    stack_push(q -> entry_stack, x);
}

int dequeue(struct Queue* q){
    if(q -> out_stack -> data == NULL){

        while(q -> entry_stack -> data != NULL){

            stack_push(q -> out_stack, stack_pop(q -> entry_stack));
            
        }
    }

    return stack_pop(q -> out_stack);
}

int is_empty(struct Queue* q){
    return (q -> entry_stack -> data == NULL && q -> out_stack -> data == NULL);
}