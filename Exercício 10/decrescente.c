#include <stdlib.h>
#include <stdio.h>

/*  A funcao insercao atualmente ordena em ordem crescente,
    Altere-a para que ela ordene em ordem decrescente.
    Nao altere a assinatura da funcao.
*/
void insercao (int n, int v[]){
   for (int j = 1; j < n; ++j) {
      int x = v[j];
      int i;
      for (i = j-1; i >= 0 && v[i] > x; --i) 
         v[i+1] = v[i];
      v[i+1] = x;
   }
}

/*  Funcao principal do algoritmo, nao a altere.
    Le o tamanho do vetor, o cria dinamicamente e le o valor dos elementos.
    Depois, chama a funcao insercao para que o vetor seja ordenado e o printa na tela.
*/
int main(){
    int n, i;
    int* v;
    printf("Tamanho do vetor: ");
    scanf("%d", &n);
    v = malloc(n*sizeof(int));
    for (i=0; i<n; i++){
        printf("\nElemento: ");
        scanf("%d", &v[i]);
    }
    printf("\nVetor ordenado:\n");
    insercao(n, v);
    for (i=0; i<n; i++)
        printf("%d ", v[i]);
    free(v);
    return 0;
}