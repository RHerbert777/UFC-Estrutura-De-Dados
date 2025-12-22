#include <stdio.h>
#include "LinkedList.h"

int main() {
    Node *cabeca = list_create();

    for(int i = 1; i <= 9; i++) {
        cabeca = list_push_back(cabeca, i);
    }

    list_print(cabeca);

    cabeca = list_pop_back(cabeca);

    list_print(cabeca);

    list_free_rec(cabeca);
    
    return 0;
}