/* Programa que lista os numeros perfeitos <= 1000. */
#include <stdio.h>
#define N 1000

/* Funcao principal: deve estar presente em todos os programas. */
int main() { 
    
    /* Declaracoes de variaveis */
    int n = 1; /* menor candidato a numero perfeito */
    int i;
    int soma;

    while (n <= N) {
        soma = 0;
        /* soma os divisores de n */
        for (i = 1; i <= n/2; ++i) 
        {
        if (n % i == 0) 
        soma += i;
        }
            
            
    
            
        if (soma == n) {
        printf("%d\n", n);    
        soma = 0;}
            
        
        
        n++;
    }

    /* Valor de retorno do programa: 0 indica bem sucedido, != 0 indica falha.*/
    return 0;
    
}