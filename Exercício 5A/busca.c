/* Busca e exibe posição de cada ocorrência de a em b */
#include <stdio.h>
#include <string.h>

typedef char* string; // define tipo string


/* Recebe string p e t e exibe na tela as posicoes
 k tal que p[0..m-1] é sufixo de t[0..k+m]. */
void busca_em_texto (string p, string t) 
{
   // === MODIFIQUE O CODIGO ABAIXO PARA SATISFAZER O ENUNCIADO ===
   int i, ocorrencias = 0;
   int m = strlen(p);
   int n = strlen(t);
   for (int k = 0; k <= n-m; ++k) {
      for (i = 0; i < m && p[i] == t[i+k]; i++); 
      if (i == m) ++ocorrencias;
   }
   printf("%d ocorrências encontradas.", ocorrencias);
}

// Funcao principal do programa - NAO MODIFIQUE O CODIGO ABAIXO
int main(){
    char a[200], b[200]; 
    /* leitura das strings a e b */
    printf("Palavra: "); scanf("%s", a); 
    printf("Texto: "); scanf("%s", b); 
    busca_em_texto(a, b);
    return 0;
}