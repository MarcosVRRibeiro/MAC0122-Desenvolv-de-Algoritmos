/* O programa abaixo compara se duas strings, r e s, sao iguais. 
   Adapte-o para determinar o número de vezes que r ocorre em s*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100 //tamanho maximo das strings

//adapte essa funcao para fazer o pedido no enunciado
int busca(char *r, char *s){
    int ocorrencia = 0, i, j=0; //contador de quantas vezes r apareceu em s
    
    
    for (i=0; i < strlen(s) -1 ; i++){
        if(tolower((unsigned char) s[i]) == tolower((unsigned char) r[j]))
            j++;
        else 
            j = 0;
        if (j == strlen(r)-1)
            {
            ocorrencia++;
            j = 0;
            }
    }
    return ocorrencia;
}


int main(){
    char r[MAX], s[MAX];
    /* o trecho a seguir le apenas uma palavra, 
       adapte o trecho a seguir para ler mais que uma palavra */
    printf("\nString s: ");
    fgets(s, 256, stdin);
    
    printf("String r: ");
    fgets(r, 256, stdin);

    
    
    /* nao altere o que estiver abaixo */
    printf("Ocorrencias de r em s: %d", busca(r,s));
    return 0;
}
