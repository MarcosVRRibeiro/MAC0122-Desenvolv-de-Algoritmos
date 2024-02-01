#include <stdlib.h>
#include <stdio.h>

/* definicao da struct apelidada de celula.
   os valores a serem comparados sao inteiros. 
   não alterar a struct. */
typedef struct elemento{
    int valor;
    struct elemento* prox;
} celula;


/* Funcao responsavel por verificar se a lista esta em ordem crescente 
   Recebe o ponteiro para a celula-cabeca
   Retorna 1 se estiver em ordem crescente, 0 caso contrario.
   A modifique para fazer o que foi pedido.*/
int verifica(celula *p){
        int r = 3;
    while (p != NULL && r != 0) {
        int i, maior = 0;
        p->valor = i;
        if (i > maior && r != 0) { 
            i = maior; 
            r = 1;
        }
        if (i < maior) {
            r = 0;
            
        }
        p = p->prox;
    }
    
    
    return r;
}

/* Funcao para criar a lista encadeada, nao a altere */
celula* adicionar_elemento(celula *atual, int n){
    celula *novo;
    novo = malloc(sizeof(celula));
    novo->valor = n;
    novo->prox = NULL;
    atual->prox = novo;
    return novo;
} 


/* Funcao principal, nao a altere */
int main(){
    /* declaracao e inicializacao das variaveis */
    int c, resposta;
    celula *inicial, *lista;
    inicial = malloc(sizeof(celula));
    /* leitura do caso a ser executado */
    printf("Caso: ");
    scanf("%d", &c);
    switch(c){
        case 1:
            lista = adicionar_elemento(inicial, 10);
            lista = adicionar_elemento(lista, 22); 
            lista = adicionar_elemento(lista, 23);
            lista = adicionar_elemento(lista, 4);
            lista = adicionar_elemento(lista, 55); // lista final: 10, 22, 23, 4, 55
            break;
        case 2:
            lista = adicionar_elemento(inicial, 10);
            lista = adicionar_elemento(lista, 22); 
            lista = adicionar_elemento(lista, 23);
            lista = adicionar_elemento(lista, 40);
            lista = adicionar_elemento(lista, 55); // lista final: 10, 22, 23, 40, 55
            break;
    }
    /* verificacao se a lista esta em ordem crescente
       seguido de print do resultado */
    resposta = verifica(inicial);
    if (resposta == 1){
        printf("Lista esta em ordem crescente");
    }
    else if(resposta == 0){
        printf("Lista nao esta em ordem crescente");
    }
    else
        printf("Resposta invalida");
    return 0;
}