#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

struct node {
    int value;
    struct node *next;
};

struct queue {
    Node *first; // ponteiro para o primeiro elemento
    Node *last;  // ponteiro para o último elemento
    size_t size; // número de elementos
};

// cria fila vazia
Queue* queue_create(void) {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    if(q == NULL) {
        printf("falha: erro de alocação.\n");
        return NULL;
    }
    q->first = NULL;
    q->last = NULL;
    q->size = 0;
    return q;
}

// retorna o tamanho da fila
size_t queue_size(Queue *q) {
    if(q == NULL) {
        printf("falha: ponteiro nulo.\n");
        exit(1);
    }
    return q->size;
}

// retorna true se e somente se a fila estiver vazia
bool queue_empty(Queue *q) {
    if(q == NULL) {
        printf("falha: ponteiro nulo.\n");
        exit(1);
    }
    return q->size == 0;
}

// inserir na fila
void queue_push(Queue *q, int value) {
    if(q == NULL) {
        printf("falha: ponteiro nulo.\n");
        return;
    }
    Node *novo = (Node*) malloc(sizeof(Node));
    novo->value = value;
    novo->next = NULL;
    // Caso 1: lista vazia
    if(queue_empty(q)) { 
        q->first = q->last = novo;
        q->size++;
    } 
    // Caso 2: lista não vazia
    else { 
        q->last->next = novo;
        q->last = novo;
        q->size++;
    }
}

// remover da fila
void queue_pop(Queue *q) {
    if(q == NULL) {
        printf("falha: ponteiro nulo.\n");
        return;
    }
    if(queue_empty(q)) {
        return;
    }
    Node *aux = q->first;
    q->first = aux->next;
    free(aux);
    q->size--;
    if(q->first == NULL) {
        q->last = NULL;
    }
}

// retorna o valor do elemento no início da fila
int queue_front(Queue *q) {
    if(q == NULL) {
        printf("falha: ponteiro nulo.\n");
        exit(1);
    }
    if(queue_empty(q)) {
        printf("falha: fila vazia.\n");
        exit(1);
    }
    return q->first->value;
}

// retorna o valor do elemento no final da fila
int queue_back(Queue *q) {
    if(q == NULL) {
        printf("falha: ponteiro nulo.\n");
        exit(1);
    }
    if(queue_empty(q)) {
        printf("falha: fila vazia.\n");
        exit(1);
    }
    return q->last->value;
}

// libera toda a memória que foi alocada para a fila
void queue_free(Queue *q) {
    if(q == NULL){
        return;
    }
    Node *ptr = q->first;
    while(ptr != NULL){
        Node *aux = ptr;
        printf("liberado: %d\n", aux->value);
        ptr = ptr->next;
        free(aux);
    }
    printf("liberado o struct node\n");
    free(q);
}

// troca o conteúdo das duas filas
void queue_swap(Queue *q1, Queue *q2) {
    // 1. Correção da verificação de segurança
    if (q1 == NULL || q2 == NULL) {
        exit(1); // Encerra o programa se receber ponteiros inválidos
    }
    
    // 2. A Troca Real (Deep Swap de metadados)
    // Criamos uma cópia temporária do CONTEÚDO da struct q1
    Queue aux = *q1; 
    
    // O conteúdo apontado por q1 recebe o conteúdo apontado por q2
    *q1 = *q2;       
    
    // O conteúdo apontado por q2 recebe o conteúdo que estava em aux
    *q2 = aux;       
}