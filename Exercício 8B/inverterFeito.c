/* Programa para inverter as letras de uma palavra usando pilha. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* registro a ser usado, cada elemento da pilha e' um char.
   nao altere esse registro*/
typedef struct registro {
    char charactere;
    struct registro *prox;
} pilha;

/* definicao da pilha como variavel global*/
pilha *pi;

/*inicializacao da pilha, nao alterar */
void criaPilha(void){
    pi = malloc(sizeof(pilha));
    pi->prox = NULL;
}

/* implemente as funcoes empilha e desempilha*/
void empilha (char y) { 
    pilha *novo;
    novo = malloc(sizeof(pilha));
    novo->charactere = y;
    novo->prox = pi->prox;
    pi->prox = novo;
   }


char desempilha (void) {
    char x;
    pilha *pit;
    pit = pi->prox;
    x = pit->charactere;
    pi->prox = pit->prox;
    free(pit);
    return x;
}

/* Funcao responsavel por inverter a palavra digitada pelo usuario.
   Essa funcao deve utilizar as funcoes empilha e desempilha anteriores.*/
char* inverter(char *palavra){
    char* invertida;
    criaPilha();
    
    int i;
    for(i=0; i<strlen(palavra); i++){
      empilha(palavra[i]);
      }
      
    for(i=0; i<strlen(palavra); i++){
      invertida[i] = desempilha();
      }
    invertida[strlen(palavra)] = '\0';
    return invertida;
}

/* Funcao principal: deve estar presente em todos os programas. */
int main() { 
    char palavra[100]; //declaracao da variavel
    scanf("%s", palavra); //leitura da palavra
    printf("%s", inverter(palavra)); //print da palavra invertida
    return 0;
    
}