/* Programa que exibe inteiros de -10 a 0 (inclusive) */
#include <stdio.h>
#define TAM 100

/* 
1. Execute o programa para ver a sua saida em tela.
2. Modifique o programa para que ele exiba os inteiros como pretendido.
3. Rode o avaliador (no VPL) para receber nota 10.
*/

/* Funcao principal: deve estar presente em todos os programas. */
int main() { 
    
    /* Declaracoes de variaveis */
    int i;
    int breque;

    i = -10; 
    breque = 0;

    /* exibe numeros de -10 a 0 */ 
    while (i <= breque){
       printf("%d\n", i);
       i = i + 1;
    }
    
    /* Valor de retorno do programa: 0 indica bem sucedido, != 0 indica falha.*/
    return 0;
    
}

