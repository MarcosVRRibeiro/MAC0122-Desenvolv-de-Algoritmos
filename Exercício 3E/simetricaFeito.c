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
    
    
    int a=0, b=0;
    while (a < 3) 
    {
        while (b < 3) 
        {
        printf("Digite o elemento em (%d,%d): ", a, b);
        scanf("%d", &m);
        matriz[a][b] = m;
        b++;
        
        }
    b=0;
    a++;
    }
    
    /* Verifica se matriz e' simetrica  -- MODIFICAR ABAIXO */
    igual = 1; /* assume inicialmente que matriz e' simetrica */
    /* testa se a matriz e simetrica*/
    for(i = 0; i < 3; i++)
    {
    for(j = i + 1; j < 3; j++)
    {
    if(matriz[i][j] != matriz[j][i]){
        igual = 0;
    }
    }
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
