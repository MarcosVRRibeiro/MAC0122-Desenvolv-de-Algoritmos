/* Programa que resolve recursivamente o problema do cavalo. */
#include <stdio.h>
#include <stdlib.h>

typedef struct st_reg {
    int linha, coluna, valor;
} registro;

/* Le matriz quadrada de inteiros de arquivo de texto.
O arquivo deve conter a ordem N da matriz na primeira linha.
As linhas seguintes enumeram os item da matriz, em ordem.
*/
int **le_matriz(char *nome, int **M, int *N) {
  FILE *tabuleiro;
  int adress, i, j, **M, w;

  tabuleiro = fopen(nome, "r");
  fscanf(arq, "%d ", &adress);
  

    M = (int **)malloc(sizeof(int *)*n);

    for(w = 0; w < n; w++){
        M[w] = (int *)malloc(sizeof(int)*n);
    }
}

/* Essa funcao recebe um registro, o tabuleiro e o tamanho do tabuleiro.
   Ela deve encontrar a posicao do tabuleiro que tem o maior valor,
   ou seja, a posicao onde o cavalo iniciara'.
   Essa posicao e o valor dela devem ser colocadas no registro.
*/
void encontraPosInicial(registro *r, int **M, int N){
    r->valor = -1;
    r->linha = 0;
    r->coluna = 0;
    r->valor = 0;
}



/* Encontra solucao para passeio parcial em M ou determina que nao existe. 

Devolve 1 se solucao for encontrada e -1 caso nao haja solucao. 
Quando houver solucao modifica M para conter solucao. Quando nao ha solucao,
M deve ser igual a matriz inicial ao termino da funcao.

Voce pode declarar novas funcoes livremente.
*/
int cavalo(int** M, int N, int x, int y, int valor, int valorInicial) {
  /* O par (plin[i], pcol[i]) é uma possível jogada para o cavalo
   * Um cavalo em (x,y) pode se mover para (x',y')=(x+plin[i], y+pcol[i]),
   * desde que 0 <= x < N, 0<= y < N e tab[x][y] == 0
   */
  static const int plin[8] = { 2,  1, -1, -2, -2, -1,  1,  2};
  static const int pcol[8] = { 1,  2,  2,  1, -1, -2, -2, -1};
  if (valor == N*N){
      return 1;
  }
  return cavalo(M, N, x, y, valor+1, valorInicial);
}


/* Funcao principal: deve estar presente em todos os programas. */
int main() { 
    /* Declaracoes de variaveis */
    char nome[100]; /* nome do arquivo contendo a matriz inicial */
    int i, j, st, variavel = 0;
    int** M;
    int *N;
    N = &variavel;
    printf("Arquivo: ");
    scanf("%s", nome);
    M = le_matriz(nome, M, N);
    registro *r = malloc(sizeof(registro));
    encontraPosInicial(r, M, *N);
    st = cavalo(M, *N, r->linha, r->coluna, r->valor, r->valor);
    if (st > 0) printf("Solucao:\n");
    else printf("\nNao ha' solucao para matriz inicial:\n");
    for (i = 0; i < *N; ++i) {
       for (j = 0; j < *N; ++j)
         printf("%3d ", M[i][j]);
       printf("\n");
    }
    /* Valor de retorno do programa: 0 indica bem sucedido, != 0 indica falha.*/
    return 0;
    
}