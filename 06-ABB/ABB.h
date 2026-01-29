#ifndef ABB_H
#define ABB_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no_arv{
    int chave;
    struct no_arv *esq;
    struct no_arv *dir;
};

typedef struct no_arv NoArv;

//cria àrvore vazia
NoArv* abb_cria();

//busca um valor na ABB
//se o valor existir, retorna ponteiro para o nó.
//se não existir, retorna nulo
//Complexidade: O(h), onde h é a altura da sua arvore.
NoArv* abb_busca(NoArv *node,int valor);

NoArv* abb_insere(NoArv* node,int valor);

NoArv* abb_free(NoArv *node);

void mostrar(NoArv *node,const char *heranca);

NoArv* abb_minimo(NoArv* node);

//remover um nó especifico

int arv_altura(NoArv *node);

int arv_tamanho(NoArv *node);


#endif