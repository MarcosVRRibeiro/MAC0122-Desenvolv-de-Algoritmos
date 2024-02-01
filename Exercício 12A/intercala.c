#include <stdio.h>
#include <stdlib.h>

/*  A funcao intercala recebe v1 de tamanho p, v2 de tamanho q e v3 cujo tamanho e' p+q
    v1 e v2 estao ordenados, a funcao deve intercalar seus valores produzindo v3 ordenado.
    Atualmente ela esta produzindo v3 que e' a concatenacao de v1 com v2,
    altere-a para fazer o que foi pedido.
*/
void intercala(int v1[], int p, int v2[], int q, int v3[]){
    int i;
    for(i=0; i<p; i++) v3[i] = v1[i];
    for(i=0; i<q; i++) v3[p+i] = v2[i];
}

/* Funcao principal do programa, nao a altere.
   Le o tamanho de v1 e v2 de uma vez e aloca dinamicamente os tres vetores.
   Le os elementos de v1, depois os de v2 e chama a funcao que os intercala.
   Por fim, imprime v3 na tela, ele e' o resultado da intercalacao. 
*/
int main(){
    int p, q;
    int i;
    int *v1, *v2, *v3;
    printf("Tamanho de v1 e de v2: ");
    scanf("%d %d", &p, &q);
    v1 = malloc(p*sizeof(int));
    v2 = malloc(q*sizeof(int));
    v3 = malloc((p+q)*sizeof(int));
    for (i=0; i<p; i++){
        printf("Elemento %d de v1: ", i+1);
        scanf("%d", &v1[i]);
    }
    for (i=0;i<q;i++){
        printf("Elemento %d de v2: ", i+1);
        scanf("%d", &v2[i]);
    }
    intercala(v1, p, v2, q, v3);
    printf("Vetores intercalados: ");
    for (i=0; i<p+q; i++){
        printf("%d ", v3[i]);
    }
    free(v1);
    free(v2);
    free(v3);
    return 0;
}