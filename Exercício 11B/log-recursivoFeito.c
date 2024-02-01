#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Calcula log N! de maneira recursiva: log N! = log(N) + log((N-1)!)
   Utilize a funcao log() da biblioteca math.h
*/
float logfatorial(int N){

    if (N == 0) return 0;
    
    double lg, logNfat;
    if (N > 0) {
        logNfat = log(N) + logfatorial(N-1);
    }
    
    return logNfat; /* recursao */
}

//Funcao principal do programa, nao a altere
int main(){
    int N;
    printf("Insira o valor de N: ");
    scanf("%d", &N);
    printf("\nLog(N!): %.4f", logfatorial(N));
    return 0;
}