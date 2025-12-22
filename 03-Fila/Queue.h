#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdbool.h>

// declaração dos tipos opacos
typedef struct node Node;
typedef struct queue Queue;

// cria fila vazia
Queue* queue_create(void);

// retorna o tamanho da fila
size_t queue_size(Queue *q);

// retorna true se e somente se a fila estiver vazia
bool queue_empty(Queue *q);

// inserir na fila
void queue_push(Queue *q, int value);

// remover da fila
void queue_pop(Queue *q);

// retorna o valor do elemento no início da fila
int queue_front(Queue *q);

// retorna o valor do elemento no final da fila
int queue_back(Queue *q);

// troca o conteúdo das duas filas
void queue_swap(Queue *q1, Queue *q2);

// libera toda a memória que foi alocada para a fila
void queue_free(Queue *q);

#endif