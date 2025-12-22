#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdbool.h>

// declaração dos tipos opacos
typedef struct node Node;
typedef struct stack Stack;

// cria uma pilha vazia
Stack* stack_create(void);

// devolve o tamanho da pilha
size_t stack_size(Stack *p);

// retorna true se a pilha estiver vazia; ou false caso contrário
bool stack_empty(Stack *p);

// Empilha um elemento no topo da pilha
void stack_push(Stack *p, int value);

// Desempilha um elemento da pilha
void stack_pop(Stack *p);

// Retorna o valor do elemento no topo da pilha
int stack_top(Stack *p);

// Libera toda a memória que foi alocada
void stack_free(Stack *p);

#endif