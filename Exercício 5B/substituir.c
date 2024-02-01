/* Programa para substituir uma substring por outra*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

/* Recebe a string b e seu tamanho n, string a e seu tamanho m, string x e seu tamanho p, e uma string nova;
   Altere essa funcao para que ela coloque em nova o resultado de substituir em b as ocorrencias de a por x. */
void substituir(char b[], int n, char a[], int m, char x[], int p, char nova){
    // FAZER
}

/* Funcao principal do programa, nao a altere */
int main(){
    /* declaracao das variaveis */
    char a[MAX],b[MAX],x[MAX], nova[MAX];
    /* leitura de b, a e x */
    scanf("%s",b);
    scanf("%s",a);
    scanf("%s",x);
    /* chamando a funcao substituir passando b, ultimo indice de b, a, ultimo indice de a, x, ultimo indice de x, e nova. 
       imprimindo o resultado e terminando o programa.*/
    substituir(b, strlen(b), a, strlen(a), x, strlen(x), nova);
    printf("\n%s", nova);
    return 0;
}