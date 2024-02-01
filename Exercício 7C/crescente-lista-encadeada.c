#include <stdlib.h>
#include <stdio.h>

/* nao modifique o registro */
typedef struct reg {
   int v; 
   struct reg *prox;
} celula;

/* 
 Modifique a funcao para que ela pare de inserir apenas no final e realize o que foi pedido.
*/
celula* busca_e_insere_seq(int valor, celula* vetor){
    while(vetor->prox !=NULL) vetor = vetor->prox;
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->v = valor;
    vetor->prox = nova;
    return nova;
}

/* Funcao responsavel por printar a lista encadeada 
  Nao alterar */
void printVetor(celula* v){
    v = v->prox;
    while(v != NULL){
        printf("%d ", v->v);
        v = v->prox;
    }
}


/* Nao alterar a funcao main */
int main(){
    /* reclarando as variaveis*/
    int  c; 
    celula *inicial;
    /* Recebe caso de teste: 1 ou 2 */
    printf("Caso: ");
    scanf("%d", &c);
    inicial = malloc(sizeof(celula));
    inicial->prox=NULL;
    switch (c) {
        case 1: //testa insercao ao fim e no meio
            printf("%d ",busca_e_insere_seq(4, inicial)->v); // busca e insere 4. v = [4]
            printf("%d ",busca_e_insere_seq(4, inicial)->v); // busca 4 novamente, v = [4]
            printf("%d ",busca_e_insere_seq(10, inicial)->v); // busca e insere 10 no final do vetor, v = [4, 10]
            printf("%d ",busca_e_insere_seq(10, inicial)->v); // busca 10
            printf("%d ",busca_e_insere_seq(5, inicial)->v); // busca e insere 5 no meio do vetor, v = [4, 5, 10]
            printf("%d",busca_e_insere_seq(5, inicial)->v); // busca 5 */
            break;
        case 2: //testa insercao no fim e no comeco
            printf("%d ",busca_e_insere_seq(5, inicial)->v); // busca e insere 5. v = [5]
            printf("%d ",busca_e_insere_seq(5, inicial)->v); // busca 5 novamente, v = [5]
            printf("%d ",busca_e_insere_seq(15, inicial)->v); // busca e insere 15 no final do vetor, v = [5, 15]
            printf("%d ",busca_e_insere_seq(15, inicial)->v); // busca 10
            printf("%d ",busca_e_insere_seq(2, inicial)->v); // busca e insere 2 no comeco do vetor, v = [2, 5, 15]
            printf("%d",busca_e_insere_seq(2, inicial)->v); // busca 2 */
            break;
    }
    /* print final do vetor, liberacao da memoria e fim do programa */
    printf("\nVetor: ");
    printVetor(inicial);// exibe o vetor final
    free(inicial);
    return 0;
}