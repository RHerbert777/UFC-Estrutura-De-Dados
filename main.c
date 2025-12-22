#include <stdio.h>
#include "Queue.h"

int main() {
    // cria filas vazias
    Queue *q1 = queue_create(); 
    Queue *q2 = queue_create();

    // insere elementos nas filas
    for(int i = 11; i <= 19; i++) {
        queue_push(q1, i);
    }
    for(int i = 77; i <= 83; i++) {
        queue_push(q2, i);
    }

    while(!queue_empty(q1)) {
        int frente = queue_front(q1);
        printf("%d ", frente);
        queue_pop(q1);
    }
    printf("\n");

    queue_free(q1);
    queue_free(q2);

    return 0;
}