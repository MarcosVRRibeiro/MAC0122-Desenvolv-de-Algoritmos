/* Programa que resolve o problema do cavalo. */
#include <stdio.h>
#include <stdlib.h>

typedef struct st_reg {
    int linha, coluna, valor;
    struct st_reg *prox;
} registro;

/* Le matriz quadrada de inteiros de arquivo de texto.
O arquivo deve conter a ordem N da matriz na primeira linha.
As linhas seguintes enumeram os item da matriz, em ordem.
*/
int **le_matriz(char *nome, int **M, int *N) {
  int** M;
  
  return M;
}


/* Encontra solucao para passeio parcial em M ou determina que nao existe. 

Devolve 1 se solucao for encontrada e -1 caso nao haja solucao. 
Quando houver solucao modifica M para conter solucao. Quando nao ha solucao,
M deve ser igual a matriz inicial ao termino da funcao.

Voce pode declarar novas funcoes livremente.
*/
int cavalo(int **M, int N) {
  /* O par (plin[i], pcol[i]) é uma possível jogada para o cavalo
   * Um cavalo em (x,y) pode se mover para (x',y')=(x+plin[i], y+pcol[i]),
   * desde que 0 <= x < N, 0<= y < N e tab[x][y] == 0
   */
  static const int plin[8] = { 2,  1, -1, -2, -2, -1,  1,  2};
  static const int pcol[8] = { 1,  2,  2,  1, -1, -2, -2, -1};    
    
  registro* pilha;
    
    
  return 1;
}

/* Funcao principal: deve estar presente em todos os programas. */
int main() { 
    
    /* Declaracoes de variaveis */
    char nome[100]; /* nome do arquivo contendo a matriz inicial */
    int i, j, st, tamanho;
    int *N;
    int** M;
    printf("Arquivo: ");
    nome = scanf("%s", nome);
    N = &tamanho;
    M = le_matriz(nome, M, N);
    st = cavalo(M, *N);
    if (st > 0) printf("Solucao:\n");
    else printf("Nao ha' solucao para matriz inicial:\n")
    
    for (i = 0; i < N; ++i) {
       for (j = 0; j < N; ++j)
         printf("%3d ", M[i][j]);
       printf("\n");
    }

    /* Valor de retorno do programa: 0 indica bem sucedido, != 0 indica falha.*/
    return 0;
    
}