#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

NoArv* abb_cria() {
    return NULL;
}

NoArv* abb_busca(NoArv *node, int valor) {
    if(node == NULL) return NULL;
    if(node->chave == valor) return node;
    //passo recursivo
    if(node->chave < valor) return abb_busca(node->dir, valor);
    else return abb_busca(node->esq, valor);
}

NoArv* abb_insere(NoArv* node, int valor){
    // 1. Criação do nó (Isso você já acertou)
    if (node == NULL){
        NoArv *q = (NoArv*) malloc(sizeof(NoArv));
        q->chave = valor;
        q->dir = NULL;
        q->esq = NULL;
        return q;
    }

    // 2. Se já existe, retorna o próprio nó (nada muda)
    if (node->chave == valor) return node;
    
    // 3. O PULO DO GATO (A Correção)
    // NÃO faça: return abb_insere(...)
    // FAÇA: node->dir = abb_insere(...)
    
    if (valor > node->chave) {
        // "Meu braço direito agora aponta para o resultado da inserção na direita"
        node->dir = abb_insere(node->dir, valor); 
    } else {
        // "Meu braço esquerdo agora aponta para o resultado da inserção na esquerda"
        node->esq = abb_insere(node->esq, valor);
    }
    
    // 4. Retorna o PAI (node), e não o filho novo.
    // Assim a main continua segurando a raiz original.
    return node;
}
//Remoção em pre-ordem
NoArv* abb_free(NoArv *node){
    if(node != NULL){
        //va para a arvore esquerda e remova tudo o que estiver lá, o sistema cria uma pilha que volta removendo
        //o que existe na arvore esquerda  
        node->esq = abb_free(node->esq);
        
        //Mesma coisa para a direita
        node->dir = abb_free(node->dir);
        
        //Libera o nó
        free(node);
    }
}

void mostrar(NoArv *node, const char *heranca) {
    /* se tem filhos, visita primeiro a direita */
    if (node != NULL && (node->esq != NULL || node->dir != NULL)) {
        char next[256];
        snprintf(next, sizeof(next), "%sr", heranca);
        
        // CORREÇÃO AQUI: removido o '_'
        mostrar(node->dir, next); 
    }

    /* imprime os "galhos" */
    int len = strlen(heranca);
    for (int i = 0; i < len - 1; i++) {
        // Lógica visual: decide se imprime barra ou espaço baseado no histórico
        if (heranca[i] != heranca[i + 1])
            printf("│   ");
        else
            printf("    ");
    }

    if (len > 0) {
        if (heranca[len - 1] == 'r')
            printf("┌───");
        else
            printf("└───");
    }

    /* nó nulo */
    if (node == NULL) {
        printf("#\n");
        return;
    }

    printf("%d\n", node->chave);

    /* visita a esquerda */
    if (node->esq != NULL || node->dir != NULL) {
        char next[256];
        snprintf(next, sizeof(next), "%sl", heranca);
        
        mostrar(node->esq, next);
    }
}

//Procurar o menor valor ou seja o valor mais a esquerda diferente de NULL
NoArv* abb_minimo(NoArv* node) {
    // 1. Proteção básica: se a árvore for vazia
    if (node == NULL) return NULL;
    
    // 2. Loop: Enquanto existir um caminho para a esquerda...
    while (node->esq != NULL) {
        // ... atualize o 'node' para ser o filho da esquerda
        node = node->esq;
    }
    
    // 3. Quando o while parar, significa que node->esq é NULL.
    // Logo, 'node' é o menor elemento.
    return node;
}

int arv_altura(NoArv *node){
    if(node == NULL)return 0;
    
    int esq = arv_altura(node->esq);
    int dir = arv_altura(node->dir);
    
    if (esq > dir){
        return esq + 1;
    }else{
        return dir + 1;
    }
}
//Pergunto o que a esquerda e o que tem a direita e retorno
int arv_tamanho(NoArv *node){
    if(node == NULL)return 0;
    
    return 1 + arv_tamanho(node->dir) + arv_tamanho(node->esq);
}