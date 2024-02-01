/* Programa para substituir uma substring por outra*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

/* Recebe a string b e seu tamanho n, string a e seu tamanho m, string x e seu tamanho p, e uma string nova;
   Altere essa funcao para que ela coloque em nova o resultado de substituir em b as ocorrencias de a por x. */
void substituir(char b[], int n, char a[], int m, char x[], int p, char nova[]){
    int i, ondocorr = 0, ocorr = 0;
    m = strlen(a); 
    n = strlen(b);  /* palavra que será varrida */
    /* Essa parte busca a posição de onde começa a ocorrencia de a em b*/
    for (int k = 0; k <= n; ++k) {
        for (i = 0; i < m && a[i] == b[i+k]; i++); {
            if (i == m) {
                ondocorr=k;
                ocorr++;
          
            }
        }
    }  
    int g;
    
    for (g = ondocorr; g < ondocorr+p+1 && ocorr > 0; g++){
        nova[g] = x[g-ondocorr];
        }
    
     for (g=0; g<ondocorr && ocorr > 0; g++){
         nova[g]=b[g];
        }
     
     int z = n+(p-1)*ocorr;
     
    for (g=ondocorr; g <= z && ondocorr+p != n+p-m && ocorr > 0; g++){
       nova[g+p]=b[g+m];
       }
    ocorr = ocorr - 1;
    
    if (ocorr != 0 && ocorr > 0 ) {
      char p[MAX]; 
      strcpy(p, nova); 
      substituir(p, strlen(p), a, strlen(a), x, strlen(x), nova);
      }
}
/* Funcao principal do programa, nao a altere */

int main(){
    /* declaracao das variaveis */
    char a[MAX],b[MAX],x[MAX], nova[MAX];
    /* leitura de b, a e x */
    scanf("%s",b);
    scanf("%s",a);
    scanf("%s",x);
    /* chamando a funcao substituir passando b, ultimo indice de b, a, ultimo indice de a, x, ultimo indice de x, e nova. 
       imprimindo o resultado e terminando o programa.*/
    substituir(b, strlen(b), a, strlen(a), x, strlen(x), nova);
    printf("\n%s", nova);
    return 0;
    
}
