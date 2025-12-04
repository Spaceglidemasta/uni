#ifndef __STACK_H__
#define __STACK_H__

#define STACK_SIZE 16
#define STACK_TOP 0

struct Stack; //forward declaration
struct Stack* stack_init(); //Legt einen neuen Stack an
void stack_push(struct Stack*,int); //Legt ein Element auf den Stack
int stack_pop(struct Stack*); //Entnimmt ein Element vom Stack
void stack_delete(struct Stack**); //Löscht den Stack

#endif //__STACK_H__