#include<stdio.h>
#include<stdlib.h>

/* 
   - altere a funcao abaixo para determinar se uma matriz generica n-por-n e simetrica
   - os elementos da matriz devem ser informados pelo usuario
   - mantenha os printf como estao
 */
int main(){
    /* declaracao das variaveis */
    int i, j; /* inteiros para percorrer matriz */
    int m; /* variavel auxiliar */
    int igual; /* indicador de passagem */
    int matriz[3][3]; /* matriz */
    /* Receber matriz 3-por-3 do usuario - MODIFICAR ABAIXO */
    printf("Digite o elemento em (0,0): ");
    scanf("%d", &m);
    matriz[0][0] = m; 
    /* Verifica se matriz e' simetrica  -- MODIFICAR ABAIXO */
    igual = 1; /* assume inicialmente que matriz e' simetrica */
    /* testa se a matriz e simetrica*/
    if(matriz[0][0] != matriz[0][0]){
        igual = 0;
    }
    /* resposta */
    if (igual == 1){
        printf("Simetrica");
    }
    else{
        printf("Nao e simetrica");
    }
    return 0;
}