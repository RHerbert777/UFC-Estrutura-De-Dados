#include <stdio.h>
#include "ABB.h"

int main(){
    NoArv *arvore = abb_cria();

    for (size_t i = 0; i < 10; i++){
        arvore = abb_insere(arvore, (int)i);
    }
    printf("Minha Arvore:\n");
    mostrar(arvore,"");
 
    int alt = arv_altura(arvore);
    printf("Altura: %d\n", alt);

    int tamanho = arv_tamanho(arvore);
    printf("Tamanho: %d\n", tamanho);

    abb_free(arvore);
    return 0;
}