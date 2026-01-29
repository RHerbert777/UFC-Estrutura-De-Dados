#include <stdio.h>
#include "Tree.h"

int main() {
    /*
    NoArv *v3 = arv_cria(3, NULL, NULL);
    NoArv *v8 = arv_cria(8, NULL, NULL);
    NoArv *v9 = arv_cria(9, NULL, NULL);
    NoArv *v5 = arv_cria(5, v8, v9);
    NoArv *v7 = arv_cria(7, v3, v5);
    */

    NoArv *v7 = arv_cria(7, 
        arv_cria(3,NULL,NULL), 
        arv_cria(5, 
            arv_cria(8,NULL,NULL), 
            arv_cria(9,NULL,NULL)
        )
    );

    arv_imprime(v7);
    printf("\n");

    v7 = arv_libera(v7);
    return 0;
}