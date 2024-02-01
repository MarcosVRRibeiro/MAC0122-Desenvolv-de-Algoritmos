/* Simula lancamentos de uma roleta e exibe contagens */
/* Define bibliotecas usadas */
#include <stdio.h>
#include <stdlib.h>
/* Funcao principal */
int main()
{
    srand(3); /* fixa semente de numeros aleatorios para garantir reproducibilidade: NAO ALTERE ESSA LINHA! */
    /* altere o codigo abaixo para fazer o pedido no enunciado */
    int jogada, n;
    /* Criar estrutura de dados para armazenar contagens */
    printf("Digite n:");
    /* Receber inteiro n do usuario */
    /* ... */
    /* Simular n lancamentos e guardar contagens */
    while (n > 0){
        jogada = rand() % 37; /* gera numero pseudo-aleatorio entre 0 e 36 */
        printf("Lancamento: %d\n", jogada);
        /* Incrementar contagem de numero lancado */
        n--;
    }
    /* Modificar trecho abaixo para exibir inteiros com contagens positivas
    Atente para plural vez/vezes */
    printf("Numero %d ocorreu %d vez\n", jogada, 1);
    
    return 0; 
}