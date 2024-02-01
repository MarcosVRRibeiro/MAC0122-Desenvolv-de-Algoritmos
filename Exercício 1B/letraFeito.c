/* Programa que exibe letra grande */
#include <stdio.h>
#define ALTURA 5
/* 
1. Execute o programa para ver a sua saida em tela.
2. Modifique as linhas 16-19 para que ele exiba a letra C em vez de I.
3. Rode o avaliador para receber nota 10.
*/

/* Funcao principal: deve estar presente em todos os programas. */
int main() { 
    
    /* Declaracoes de variaveis */
    int i;

    printf("XXXXXXX" "\nXXX  XX");
    for (i = 2; i < ALTURA; i++)
       printf("\nXXX");
    printf("\nXXX  XX" "\nXXXXXXX\n");
    
    /* Valor de retorno do programa: 0 indica bem sucedido, != 0 indica falha.*/
    return 0;
    
}
