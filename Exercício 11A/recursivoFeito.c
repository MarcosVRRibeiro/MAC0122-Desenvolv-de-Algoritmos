#include <stdio.h>
#include <stdlib.h>
 
/* Funcao auxiliar para trocar o valor de duas posicoes em um vetor.
   Nao a altere.
*/
void trocar(int v[], int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
 
/*  Funcao para ordenar o vetor v.
    Indice i indica a posicao atual e n indica o tamanho do vetor.
    Atualmente a funcao esta trocando o elemento da posicao atual por ele mesmo.
    Altere a funcao para ela ordene o vetor recursivamente.
*/
void selection(int v[], int i, int n)
{
    int j;
    for (j = 0; j < n; j++){
        if (v[i] < v[j]) {
        trocar(v, i, j);
    }
    }
      
    if (i + 1 < n) {
        selection(v, i + 1, n);
    }
}
 
/*  Funcao principal do programa, nao a altere.
    Le o tamanho do vetor a ser informado, o aloca dinamicamente e entao le seus elementos.
    Chama a funcao de ordenacao e imprime o vetor ordenado na tela.
*/
int main()
{
    int *v;
    int n, i;
    //printf("Tamanho do vetor: ");
    scanf("%d", &n);
    v = malloc(n*sizeof(int));
    for (i=0;i<n;i++){
    //    printf("Elemento %d: ", i+1);
        scanf("%d",&v[i]);
    }
    selection(v, 0, n);
    printf("\nVetor ordenado: ");
    for (i=0; i<n; i++) {
        printf("%d ", v[i]);
    }
    free(v); 
    return 0;
}