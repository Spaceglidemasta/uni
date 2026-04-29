#include "list.h"
#include <stdlib.h>


struct Item{
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
    }
}

int list_head(struct Item* current){
    if(current != NULL){
        return current -> x;
    }
    else{
        printf("Die Liste ist leer!");
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