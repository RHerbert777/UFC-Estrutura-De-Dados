#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next; 
};

typedef struct node Node;

void list_print(Node *p) {
    Node *q = p;
    printf("[ ");
    while(q != NULL) {
        printf("%d ", q->data);
        q = q->next;
    }
    printf("]\n");
}

// Cria uma lista vazia, ou seja, nula
Node* list_create(void) {
    return NULL;
}

// Função que recebe um ponteiro para o primeiro nó de uma lista, 
// recebe também um valor inteiro chamado 'val'.
// E insere um nó com esse valor no início da lista.
// Retorna um ponteiro para a lista modificada.
Node* list_push_front(Node *p, int val) {
    Node *novo = (Node*) malloc(sizeof(Node));
    novo->data = val;
    novo->next = p;
    p = novo;
    return p;
}

// Recebe como entrada um ponteiro para o primeiro
// nó da lista e libera todos os nós 
// alocados dinamicamente.
void list_free(Node *p) {
    while(p != NULL) {
        Node *aux = p->next;
        printf("nó liberado = %d\n", p->data);
        free(p);
        p = aux;
    }
}

// Função recursiva
// Recebe como entrada um ponteiro para o primeiro
// nó da lista e libera todos os nós 
// alocados dinamicamente.
void list_free_rec(Node *p) {
    if(p == NULL) {
        return;
    } else {
        list_free_rec(p->next);
        printf("nó liberado = %d\n", p->data);
        free(p);
    }
}

// Função iterativa que insere um 
// valor ao final da lista e retorna a lista modificada
Node* list_push_back(Node *p, int val) {
    // Cria o novo nó
    Node *novo = (Node*) malloc(sizeof(Node));
    novo->data = val;
    novo->next = NULL;
    if(p == NULL) {
        p = novo;
        return p;
    }
    else {
        Node *atual = p;
        while(atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = novo;
        return p;
    }
}

// Função iterativa que remove o elemento no 
// final da lista e retorna a lista modificada
Node* list_pop_back(Node *p) {
    if(p == NULL) return NULL;
    else{
        Node *a = NULL;
        Node *b = p;
        while(b->next != NULL){
            a = b;
            b = b->next;
        }
        free(b);
        if(a != NULL){
            a->next = NULL;
        } else {
            p = NULL;
        }
        return p;
    }

}




#endif