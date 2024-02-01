/* Programa para inverter os numeros contidos em um arquivo.*/
#include <stdlib.h>
#include <stdio.h>

/* Adepte a funcao principal para que faca o que e' pedido 
   Teste com o arquivo "arq.txt" */
int main(){
    /* declaracao das variaveis */
    FILE *fp;
    char nome[100];
    /* leitura do nome do arquivo e o abrindo em modo leitura */
    scanf("%s", nome);
    fp = fopen(nome,"r");
    /* lendo e printando na ordem que os numeros aparecem*/
    while(!feof (fp)){
        int i;
        fscanf(fp, "%d", &i);
        printf("%d ",i);
    }
    /* fechando o arquivo e terminando o programa */
    fclose(fp);
    return 0;
}