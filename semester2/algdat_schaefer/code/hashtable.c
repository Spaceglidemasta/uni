#include <stdlib.h>
#include <stdio.h>

#define TABLE_SIZE 31

typedef struct _Item{

    int x;
    struct _Item* next;

}Item;

Item* item_add_front(Item* current, int x) {
    Item* new_node = malloc(sizeof(Item));

    new_node -> x = x;
    new_node -> next = current;

    return new_node;
}

Item* item_tail(Item* current){
    if(current != NULL){
        return current -> next;
    }
    else{
        printf("Das Item ist leer!");
    }
}

int item_head(Item* current){
    if(current != NULL){
        return current -> x;
    }
    else{
        printf("Das Item ist leer!");
    }
}

void item_delete(Item* current){
    if(current == NULL){
        printf("Item ist bereits deleted!");
        return;
    }
    
    Item* next;
    while(current != NULL){
        next = current -> next;
        free(current);
        current = next;
    }
}




int hash(int value){
    return value % TABLE_SIZE;
};
/* Sucht das Element Item mit dem Wert value in der Hashtabelle.
Liefert 0 zurück falls der Wert existiert ansonsten -1 ("Fehlerfall"). */
int hash_search(Item* table[], int value){
    int key = hash(value);


    Item* current = table[key];
    while (current != NULL) {
        if (current -> x == value) {
            return 0; 
        }
        current = current -> next;

    }

    return -1;
}
/* Fügt den Wert value der Hashtabelle hinzu. Rückgabewert 0 im Erfolgs-,
-1 im Fehlerfall (falls der Wert bereits existiert). */
int hash_insert(Item* table[], int value) {
    int key = hash(value);

    if(hash_search(table, value) != -1){
        return -1;
    }

    table[key] = item_add_front(table[key], value);
    return 0;
}

/* Löscht das Element Item mit dem Wert value aus der Hashtabelle.
Rückgabewert 0 im Erfolgs-, -1 im Fehlerfall. */
int hash_delete(Item* table[], int value){
    int key = hash(value);
    
    Item* current = table[key];
    Item* prev = NULL;

    while (current != NULL) {
        if (current->x == value) {
            if (prev == NULL) {
                
                table[key] = current->next;
            } else {
                
                prev->next = current->next;
            }
            free(current);
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return -1;
}


int main(){

    Item *statetab[TABLE_SIZE];

    for(int i = 0; i < 100; i++){
        if(hash_insert(statetab, i) == -1){
            return 1;
        }
    }
    return 0;
    
}
