#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Stack.h"

struct node {
    char value;
    struct node *next;
};

struct stack {
    Node *top;
    size_t size;
};

//alocar espaço para pilha
Stack* stack_create(void){
    Stack *p = (Stack*) malloc(sizeof(Stack));
    if (p == NULL)return NULL;
    p->size = 0;
    p->top = NULL;
    return p;
}


size_t stack_size(Stack *p){
    if (p == NULL)exit(EXIT_FAILURE); 
    return p->size;
}

bool stack_empty(Stack *p){
    if (p == NULL)exit(EXIT_FAILURE);
    return (p->size == 0); //comparação melhor que if else
}

void stack_push(Stack *p, int value){
    if (p == NULL)exit(EXIT_FAILURE);
    Node* novo = (Node*) malloc(sizeof(Node));
    if (novo == NULL)exit(EXIT_FAILURE);
    novo->value = value;
    novo->next = p->top; //pois inicialmente o top esta apntando para NULL logo para 
    //para economizar faz isso 
    p->top=novo; //fazendo a antiga cabeça apontar para o novo topo
    p->size++; //incrementa o tamanho
}

//interesa pilhas não vazias
// Desempilha um elemento da pilha
//remover o ultimo elemento adicionado
void stack_pop(Stack *p){
    if (p == NULL)exit(EXIT_FAILURE);
    if (!stack_empty(p)){
        Node *aux = p->top;
        p->top = p->top->next;
        free(aux);
        p->size--;
    }
}

int stack_top(Stack *p){
    if (p == NULL)exit(EXIT_FAILURE);
    if (stack_empty(p))exit(EXIT_FAILURE); //verifica se é vazia 
    return p->top->value;
}

void stack_free(Stack *p){
    if (p == NULL)exit(EXIT_FAILURE);

    while (!stack_empty(p)){ //enquanto diferente de vazio libera
        stack_pop(p); //usando a propria função
    }
    
}