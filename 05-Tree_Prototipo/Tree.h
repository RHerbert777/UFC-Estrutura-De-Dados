#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct no_arv {
    int chave;
    struct no_arv *esq;
    struct no_arv *dir;
};

typedef struct no_arv NoArv;

// Cria uma arvore vazia
NoArv *arv_cria_vazia(void);

// Cria uma arvore a partir de duas sub-arvores distintas
// A função da o valor novo a arvore esquerda e arvore direita
NoArv *arv_cria(int valor, NoArv *sae, NoArv *sad);

// Retorna true se e somente a arvore for vazia
bool arv_vazia(NoArv *r);

// Imprime as chaves de todos os nos da arvore
void arv_imprime(NoArv *r);

// Libera todos os nos da arvore
NoArv* arv_libera(NoArv *r);

// Verifica se um valor esta contido na arvore
bool arv_pertence(NoArv *r, int valor);

// Percurso em pre-ordem
void arv_preordem(NoArv *r);

// Percurso em-ordem
void arv_emordem(NoArv *r);

// Percurso pos-ordem
void arv_posordem(NoArv *r);

// Cria uma string serial da arvore binaria
void arv_serializar(NoArv *r, char *str);

// Cria uma arvore binaria a partir duma string serial valida
NoArv* arv_deserializar(char *str, int *idx);

// retorna o número de nós na árvore
int arv_size(NoArv *r);

// retorna a soma dos nós ímpares
int arv_soma_impares(NoArv *r);

#endif