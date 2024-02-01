#include <stdlib.h>
#include <stdio.h>

/* Atualmente a funcao esta transferindo sequencialmente o conteudo dos vetores a, b e c para d. 
   Altere-a para que passe a fazer o que foi pedido*/
void intercala3(int a[], int tam_a, int b[], int tam_b, int c[], int tam_c, int d[], int tam_d){
    int indice=0;
    for (int i=0; i< tam_a; i++){
        d[indice] = a[i];
        indice++;
    }
    for (int i=0; i< tam_b; i++){
        d[indice] = b[i];
        indice++;
    }
    for (int i=0; i< tam_c; i++){
        d[indice] = c[i];
        indice++;
    }
}

/*  Primeiro le o tamanho de a b c em um scanf.
    Depois, le os elementos um a um.
    Então chama a funcao intercala3 para ordena-los no vetor d.
    Por fim, imprime o vetor d ordenado.
*/
int main(){
    int n1, n2, n3, n4;
    int *a, *b, *c, *d;
    int i;
    printf("Tamanho dos tres vetores: ");
    scanf("%d %d %d", &n1, &n2, &n3);
    n4 = n1+n2+n3;
    a = malloc(n1*sizeof(int));
    b = malloc(n2*sizeof(int));
    c = malloc(n3*sizeof(int));
    d = malloc(n4*sizeof(int));
    for (i=0; i<n1; i++){
        printf("\nElemento de a: ");
        scanf("%d", &a[i]);
    }
    for (i=0; i<n2; i++){
        printf("\nElemento de b: ");
        scanf("%d", &b[i]);
    }
    for (i=0; i<n3; i++){
        printf("\nElemento de c: ");
        scanf("%d", &c[i]);
    }
    intercala3(a, n1, b, n2, c, n3, d, n4);
    printf("Vetor d:\n");
    for (i=0; i<n4; i++) printf("%d ", d[i]);
    free(a), free(b), free(c), free(d);
    return 0;
}