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
    int p = 0;
    char string[10];
    while(!feof (fp)){
        int i, j =0;
        fscanf(fp, "%d", &i);
        p++;
    }
    int j=p;
    
    
    while(j>=0){
        printf("%d ", j);
        j--;
        
    }
    
   
    /* fechando o arquivo e terminando o programa */
    fclose(fp);
    return 0;
}