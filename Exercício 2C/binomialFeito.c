/* Programa que calcula a funcao binomial de m n-a-n */
#include <stdio.h>

/* Calcula o fatorial de um dado numero valor */
int fatorial(int valor){
    int produto = 1;
    /* completar o codigo */
    return produto;
}

/* Calcula o coeficiente binomial de m e n */
int binomial(int m, int n){
    int resultado = 1;
    /* ... */
    return resultado;
}


/* Funcao principal: deve estar presente em todos os programas. 

 NAO ALTERAR A FUNCAO ABAIXO!

*/
int main() { 
    int m, n; 
    printf("Insira m e n: ");
    scanf("%d %d", &m, &n); /* recebe valores do usuario */ 
    printf("Resultado: %d", binomial(m,n)); /* exibe resultado */
    return 0; /* devolve sinal de sucesso */
}