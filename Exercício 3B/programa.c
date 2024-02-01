/* Programa principal contendo a aplicação 

Compile o programa da seguinte forma (assumindo gcc):

    gcc -std=c99 -o programa.exe programa.c racionais.c

*/

#include <stdlib.h>
#include <stdio.h>
/* Usar biblioteca definida pelo usuario */
#include "racionais.h"

int main(void) {
    racional r, x, y;
    int caso;
    printf("\nCaso: ");
    scanf("%d", &caso);
    switch(caso){
        case 1: //testando a funcao reduz
            r = reduz(3,5);
            printf("p: %d q: %d", r.p, r.q); //3 e 5
            r = reduz(165,180);
            printf("\np: %d q: %d", r.p, r.q); //11 e 12
            r = reduz(37,37);
            printf("\np: %d q: %d", r.p, r.q); //1 e 1
            break;
        case 2: //testando a funcao soma
            x.p = 7, x.q = 6;
            y.p = 2, y.q = 6;
            r = soma(x, y); // 7/6 mais 2/6
            printf("p: %d q: %d", r.p, r.q);
            x.p = 1, x.q = 2;
            y.p = 3, y.q = 4;
            r = soma(x, y); // 1/2 mais 3/4
            printf("\np: %d q: %d", r.p, r.q);
            break;
        case 3: //testando a funcao produto
            x.p = 7, x.q = 6;
            y.p = 2, y.q = 6;
            r = produto(x, y); // 7/6 vezes 2/6
            printf("p: %d q: %d", r.p, r.q);
            x.p = 1, x.q = 2;
            y.p = 2, y.q = 4;
            r = produto(x, y); // 1/2 vezes 2/4
            printf("\np: %d q: %d", r.p, r.q);
            break;
        case 4: //testando a funcao quociente
            x.p = 3, x.q = 5;
            y.p = 3, y.q = 2;
            r = quociente(x, y); //3/5 dividido por 3/2
            printf("p: %d q: %d", r.p, r.q);
            break; 
    }
    return 0;
}