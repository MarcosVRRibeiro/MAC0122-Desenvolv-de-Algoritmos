/* Programa que exibe letra grande */
#include <stdio.h>

/* 
1. Execute o programa para ver a sua saida em tela.
2. Modifique o programa como pedido.
3. Avalie o programa para receber nota 10.
*/

/* Funcao principal: deve estar presente em todos os programas. */
int main() { 
    
    /* Declaracoes de variaveis */
    int cont;
    char *p;
    char texto[] = "A long time ago, in a galaxy far far away...";
    
    /* Conta qtd de palavras no texto */
    /*** Modifique o trecho abaixo para implementa-lo com um unico laco `for`
     * cujo corpo contem apenas o comando if (*p == ' ') cont += 1;        ***/
    cont = 0;
    p = texto;
    

    for (p = texto; *p != '\0';p++) 
    {
    if (*p == ' ') cont += 1;
    };
    
    /*** Deixe o restante inalterado                 **************************/
    if (*(p-1) != ' ') cont += 1; /* tratar de última palavra */
    /* Exibe contagem */
    printf("%d palavras", cont);
    /* Valor de retorno do programa: 0 indica bem sucedido, != 0 indica falha.*/
    return 0;
    
}
