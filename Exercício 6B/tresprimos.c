#include <stdio.h>
#include <stdlib.h>

/* Altere apenas essa funcao para corrigir o programa.
   Nao altere o tipo de retorno da funcao e nem seus argumentos.*/
int *primos (void) {
   int v[3];
   v[0] = 1009; v[1] = 1013; v[2] = 1019;
   return v; }


/* nao modifique esta funcao */
int main(){
    int* v;
    v = primos();
    printf("%d %d %d", v[0], v[1], v[2]);
    return 0;
}