#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

NoArv *arv_cria_vazia(void){
    return NULL;
}

NoArv *arv_cria(int valor, NoArv *sae, NoArv *sad){
    NoArv *novo = (NoArv*) malloc(sizeof(NoArv));
    novo->chave = valor;
    novo->esq = sae;
    novo->dir = sad;
    return novo;
}

bool arv_vazia(NoArv *r){
    return (r == NULL);//se verdade retorna
}

void arv_imprime(NoArv *r){
    if(r==NULL) return;
    else{
        printf(" %d",&r->chave);
        arv_imprime(r->esq);
        arv_imprime(r->dir);
    }
}

NoArv* arv_libera(NoArv *r){
    if(r != NULL){
        arv_libera(r->esq);
        
        arv_libera(r->dir);
        
        free(r);
    }
    return NULL;
}

// Verifica se um valor esta contido na arvore
bool arv_pertence(NoArv *r, int valor) {
    if(r == NULL) {
        return false;
    } else {
        return valor == r->chave || 
               arv_pertence(r->esq, valor) || 
               arv_pertence(r->dir, valor);
    }
}

int arv_soma_impares(NoArv *r) {
    if (arv_vazia(r)) {
        return 0;
    } else {
        int soma = 0;
        if(r->chave % 2 == 1)
            soma += r->chave + arv_soma_impares(r->esq) + arv_soma_impares(r->dir);
        else
            soma += arv_soma_impares(r->esq) + arv_soma_impares(r->dir);
        return soma;
    }
}

