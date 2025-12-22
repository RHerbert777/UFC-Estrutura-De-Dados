#include <stdio.h>
#include "Stack.h"

//função que recebe uma string e inverte as letras de cada palavra da string
//entrada: AMU MEGASNEM ATERCES
void inverte_palavras(char palavra[]){
    Stack *p = stack_create();

    for (size_t i = 0; palavra[i] != '\0'; i++){
        if (palavra[i] == ' '){
            while (!stack_empty(p)){
                printf("%c", stack_top(p));
                stack_pop(p);
            }
            printf(" ");
        }else{
            stack_push(p, palavra[i]);
        }
    }
    whhile (!stack_empty(p)){
        printf("%c", stack_top(p));
        stack_pop(p);
    }
    printf("\n");
    stack_free(p);
};

int main(){

    //digitar scanf
    
    return 0;
}