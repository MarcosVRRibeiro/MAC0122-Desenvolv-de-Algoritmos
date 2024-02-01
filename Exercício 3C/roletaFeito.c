/* Simula lancamentos de uma roleta e exibe contagens */
/* Define bibliotecas usadas */
#include <stdio.h>
#include <stdlib.h>
/* Funcao principal */
int main()
{
    srand(3); /* fixa semente de numeros aleatorios para garantir reproducibilidade: NAO ALTERE ESSA LINHA! */
    
    /* altere o codigo abaixo para fazer o pedido no enunciado */
    int jogada, n, i;
    
    
    /* Criar estrutura de dados para armazenar contagens */
    int u[37];
    for (i = 0; i<37; i++) {u[i]=0;}
    
    printf("Digite n:\n");
    /* Receber inteiro n do usuario */
    scanf("%d", &n);
    /* ... */
    
    /* Simular n lancamentos e guardar contagens */
    while (n > 0)
    {
        jogada = rand() % 37; /* gera numero pseudo-aleatorio entre 0 e 36 */
        printf("Lancamento: %d\n", jogada);
        u[n-1] = jogada;
        /* Incrementar contagem de numero lancado */
        n--;
    }
    int k, c=1, aparece;
    
    for (k=1;k<37;k++) 
    
    {
        aparece = 0;
        c = 0;
        while (c<37)
        {
            if (k==u[c]) {aparece = aparece + 1;} 
            c++;
            
        }
        if (aparece == 1) {printf("Numero %d ocorreu %d vez\n", k, 1);}
        if (aparece > 1) {printf("Numero %d ocorreu %d vezes\n", k, aparece);}
        
    }
    
    
    /* Modificar trecho abaixo para exibir inteiros com contagens positivas
    Atente para plural vez/vezes */
    
    /*printf("Numero %d ocorreu %d vez\n", jogada, 1);*/
    
    /*for (i = 0; i<37; i++) printf("Esse é o vetor%d\n",u[i]);*/
    
    return 0; 
}