/* O programa abaixo compara se duas strings, r e s, sao iguais. 
   Adapte-o para determinar o número de vezes que r ocorre em s*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100 //tamanho maximo das strings

//adapte essa funcao para fazer o pedido no enunciado
int busca(char *r, char *s){
    int ocorrencia = 0; //contador de quantas vezes r apareceu em s
    if (strcmp(r,s) == 0){
        ocorrencia++;
    }
    return ocorrencia;
}


int main(){
    char r[MAX], s[MAX];
    /* o trecho a seguir le apenas uma palavra, 
       adapte o trecho a seguir para ler mais que uma palavra */
    printf("String r: ");
    scanf("%s", r);
    printf("\nString s: ");
    scanf("%s", s);
    printf("Essas sao as strings r e s: %s, %s", r, s);
    
    /* nao altere o que estiver abaixo */
    printf("Ocorrencias de r em s: %d", busca(r,s));
    return 0;
}