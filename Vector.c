#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h> // para SIZE_MAX
#include "Vector.h"

// Definição do struct
struct vector {
    int *data; //ponteiro para vetor
    size_t size; //numero de elementos
    size_t capacity; //capacidade do vetor
};

// Definição de uma macro para verificar se 
// o tamanho do array não ultrapassou o máximo permitido.
#define size_check(n,type) ((n) <= (SIZE_MAX / sizeof(type)))

// Aloca memória para um vetor vazio com capacidade para 1 elemento.
// Caso não seja possível alocar, retorna NULL.
Vector* vector_create(void) {
    Vector *ptr = (Vector*) malloc(sizeof(Vector)); //alocando memoria
    
    if(ptr == NULL)return NULL; //verificação
    
    ptr->data = (int*) malloc(sizeof(int)); // aloca memoria para inteiro em data 
    
    if(ptr->data == NULL){ //verifica se foi posivel, senão libera memoria
    free(ptr);
    return NULL;
    }
    ptr->size = 0;//tamanho inicial 0

    ptr->capacity = 1;//capacidade inicial 1 
    
    return ptr;
}

// Libera toda a memória que foi alocada dinamicamente:
// libera a memória do array 'data' e do próprio struct vector.
// Depois de liberar tudo, retorna NULL
Vector* vector_free(Vector *v) {
    if(v != NULL) {
        free(v->data); // libera o array de inteiros
        free(v);
    }
    return NULL;
}

// Ajusta a capacidade do vetor para que seja igual a new_capacity.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se new_capacity == 0, então ele não faz nada 
// e retorna ERROR_INVALID_ARGUMENT.
// Se não for possível alocar por qualquer outro motivo, 
// deixa o vetor como está e 
// retorna ERROR_ALLOCATION.
// Caso tudo dê certo, retorna ERROR_OK.
ErrorType vector_resize(Vector *v, size_t new_capacity) {
    if(v == NULL) return ERROR_NULL_POINTER;
    if(new_capacity == 0) return ERROR_INVALID_ARGUMENT;
    //if(new_capacity > SIZE_MAX / sizeof(int)) {
    //    return ERROR_ALLOCATION;
    //}
    
    int *ptr = realloc(v->data, new_capacity * sizeof(int)); 
    //funçaõ realoc voce passa o bloco de memoria a a nova capacidade, e essa função ajusta o tamanho
    //e lhe passa o endereço do novo bloco. e necesario usar * sizeof(int) para informar ao computador o 
    //tipo de dado que sera alocado um inteiro um float etc. eu crio ptr que seria basicamente um auxiliar para que
    //realoc possa fazer seu trabalho de alocar, copiar os dados e limpar o antigo

    if(ptr == NULL)return ERROR_ALLOCATION;//verifica se foi posivel

    v->data = ptr; //data recebe a nova memoria alocada

    v->capacity = new_capacity; //atualizo a variavel capacity para o usuario

    if(v->size > new_capacity) v->size = new_capacity; //ajusto size
    
    return ERROR_OK;
}

bool vector_empty(const Vector *v){
    /*
    if (v->size == 0){
        return true;
    }else{
        return false;
    }
    */
    return v->size == 0; //se verdadeiro true senão falso
}

size_t vector_size(const Vector *v){
    if (v == NULL)return 0; //asumimos 0 para evitar que ERRO_TYPE seja 
    //uma constante como -1, para que eu não possa retornar um valor negativo;
    
    return v->size;
}

size_t vector_capacity(const Vector *v){ //mesma coisa do size 
    if (v == NULL)return 0;

    return v->capacity;
}

ErrorType vector_push_back(Vector *v, int value){
    if (v == NULL)return ERROR_NULL_POINTER;
        
    //veficar se o vetor esta cheio
    if (v->capacity >= v->size){
        if (size_check(2*v->capacity,int) == false){
            return ERROR_ALLOCATION;
        }
        //dobrei a capacidade
        ErrorType err = vector_resize(v,v->capacity * 2);
        if (err != ERROR_OK){
            return err;
        }
    }
    v->data[v->size] = value;
    v->size++;
    return ERROR_OK;    
}

ErrorType vector_get(const Vector *v, size_t index, int *out_value){
    if(v == NULL || out_value == NULL)return ERROR_NULL_POINTER;
    
    if (index >= v->size) return ERROR_EMPTY;
    
    *out_value = v->data[index];
    
    return ERROR_OK;
}

ErrorType vector_pop_back(Vector *v){
    if (v == NULL){
        return ERROR_NULL_POINTER;
    }
    if (vector_size(v) == 0){
        return ERROR_EMPTY;
    }
    v->size--;
    if (v->size < v->capacity / 2){
        ErrorType err = vector_resize(v,v->capacity / 2);
        if (err != ERROR_OK){
            return err;
        }
    }
    return ERROR_OK;
}

ErrorType vector_front(const Vector *v, int *out_value){
    if (v == NULL){
        ERROR_NULL_POINTER;
    }if (vector_size == 0){
        return ERROR_EMPTY;
    }
    *out_value = v->data[0];
    return ERROR_OK;
}

ErrorType vector_back(const Vector *v, int *out_value){
    if (v == NULL){
        ERROR_NULL_POINTER;
    }if (vector_size == 0){
        return ERROR_EMPTY;
    }
    *out_value = v->data[v->size-1];
    return ERROR_OK;
}

ErrorType vector_set(Vector *v, size_t index, int value){
    if (v == NULL){
        return ERROR_NULL_POINTER;
    }
    if (index >= v->size){
        return ERROR_OUT_OF_BOUNDS;
    }
    
    v->data[index] = value;

    return ERROR_OK;
}

ErrorType vector_swap(Vector *v1, Vector *v2){
    if(v1 == NULL || v2 == NULL){
        return ERROR_NULL_POINTER;
    }
    Vector* aux = v1;

    aux = v1;
    v1 = v2;
    v2 = aux;
    return ERROR_OK;
}

ErrorType vector_insert(Vector *v, size_t index, int value){
    if (v == NULL)return ERROR_ALLOCATION;
    if (index > v->size) return ERROR_OUT_OF_BOUNDS;
    if (v->size == v->capacity){
        if(size_check(1*v->capacity,int)){
            return ERROR_ALLOCATION;
        }
        ErrorType err = vector_resize(v,v->capacity * 2);
        if (err != ERROR_OK){
            return err;
        }
    }
    for (size_t i = v->size; i > index; i--){
        v->data[i] = v->data[i-1];
    }
    v->data[index] = value;
    v->size++;
    return ERROR_OK;
}

ErrorType vector_erase(Vector *v, size_t index){
    if (v == NULL)return ERROR_ALLOCATION;
    if (index >= v->size) return ERROR_OUT_OF_BOUNDS ;
    if (v -> size == 0) return ERROR_EMPTY;
    
    for (size_t i = index; i < v->size - 1; i++){
        v->data[i] = v->data[i+1];
    }
    v->size--;
}
