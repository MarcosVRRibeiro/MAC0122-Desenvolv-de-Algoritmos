/* Programa que efetua divisao inteira */
#include <stdio.h>

/* 
1. Execute o programa para verificar o erro.
*/

/* Funcao principal: deve estar presente em todos os programas. */
int main() { 
    
    /* Declaracoes de variaveis */
    int x;
    int y;
    /* Definicoes de valores */
    x = 0;
    y = 0;
    
    if (y != 0) /* 3. descomente essa linha com a linha 22 comentada para 
                                                   tornar o programa correto. */
    x = 1 / y; /* 2. comente essa linha e descomente a proxima para verificar
                                                         a diferenca de erro. */
    /*x = 1 / 0;*/ 
    
    printf("%d", x);
    
    /* Valor de retorno do programa: 0 indica bem sucedido, != 0 indica falha.*/
    return 0;
    
}
/*
4. Avalie o programa para receber uma nota 10.
*/