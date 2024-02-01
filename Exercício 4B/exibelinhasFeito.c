/*Escreva um programa que le o nome de um arquivo e exibe apenas as linhas do arquivo de texto correspondente que não iniciam com # */
#include <stdlib.h>
#include <stdio.h>

/* Atualmente a funcao principal esta apenas lendo o nome de um arquivo e o imprimindo.
   Adepte-a para abrir o arquivo com o nome dado e imprimir as linhas conforme o enunciado.
*/
int main(){
    FILE *arq;
    char Linha[100], s[100], b[1] = "#";
    char *result;
    int i;
    
    printf("Nome do arquivo: ");
    scanf("%s", s);
    arq = fopen(s, "rt");
    
    i = 1;
    while (!feof(arq))
    {
    result = fgets(Linha, 100, arq);  
    if (result && Linha[0] != b[0]) 
        printf( "%s",Linha);
        i++;
    }
    fclose(arq);
    
    return 0;
}