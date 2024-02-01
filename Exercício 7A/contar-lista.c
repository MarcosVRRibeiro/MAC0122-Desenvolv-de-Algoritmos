#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* definicao do registro de um jogador para montarmos uma equipe (lista de jogadores) 
   nao altere essa parte*/
typedef struct jogador{
    int camisa;
    char nome[100];
    struct jogador* prox;
} celula;

/* conta quantos jogadores estao na equipe*/
int contar_jogadores(celula *p){
    int count=0;
    /* ... */
    return count;
}

/* funcao responsavel por adicionar um jogador 'a lista de jogadores 
  ela recebe o ponteiro para a ultima celula e deve retornar o ponteiro para a nova ultima celula
  altere a funcao para que faca isso*/
celula* adicionar_jogador(celula* atual, int n, char name[]){
    celula *novo;
    /* ... */
    return novo;
}


/* funcao principal, nao a altere*/
int main(){
    celula* inicial, *lista;
    /* vamos cadastrar uma equipe como exemplo,
    os titulares do Pentacampeonato: */
    lista = adicionar_jogador(inicial, 1, "Marcos"); 
    lista = adicionar_jogador(lista, 2, "Cafu"); 
    lista = adicionar_jogador(lista, 3, "Lucio");
    lista = adicionar_jogador(lista, 4, "Roque Junior");
    lista = adicionar_jogador(lista, 5, "Edmilson");
    lista = adicionar_jogador(lista, 6, "Roberto Carlos");
    lista = adicionar_jogador(lista, 7, "Ricardinho");
    lista = adicionar_jogador(lista, 8, "Gilberto Silva");
    lista = adicionar_jogador(lista, 9, "Ronaldo");
    lista = adicionar_jogador(lista,10, "Rivaldo");
    lista = adicionar_jogador(lista,11, "Ronaldinho");
    printf("Numero de jogadores cadastrados: %d", contar_jogadores(inicial));
    return 0;
}