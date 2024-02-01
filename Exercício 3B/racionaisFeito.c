/* Biblioteca de manipulacao de numeros racionais. 

Arquivo de implementacao.

Este arquivo deve conter as definicoes das funcoes declaradas em racionais.h

*/
#include "racionais.h"
#include <stdio.h>
/* Recebe inteiros p e q e devolve o racional representando p/q, tal que q > 0
 e p e q devem ser coprimos. */
racional reduz(int p, int q) {
    racional x;
     int d;
    int f;
    if (q==0 || p==0){
         x.p = 0;
         x.q = 0;
    }
    else {
    if (q<0){
        p *= -1;
        q *= -1;
    }
    
    if (p<0){
        f = 0;
        p *= -1;}
    else 
        f = 1;
    
    if (p >= q){
        d = q; };
    
    if (p < q) {
        d = p; };
        
     while (d) {
         if (p%d==0 && q%d==0) {
         p=p/d;
         q=q/d;
         };
     d --;
     };
     
    if (f)
         x.p = p;
    else 
         x.p = p * -1;
    
    x.q = q;
    }
    
    return x;
}

/* Recebe racionais x e y e devolve z = x+y. */
racional soma(racional x, racional y) {
    racional z;
    if (x.q == y.q) {z.p = x.p+y.p; z.q = x.q;}
    
    if (x.q != y.q) 
    { 
    int denom, num1, num2; 
    z.q = x.q*y.q;
    z.p = (z.q/x.q*x.p)+(z.q/y.q*y.p);
    }
    z = reduz (z.p,z.q);
    
    return z;
}

/* Recebe racionais x e y e devolve z = x*y. */
racional produto(racional x, racional y) {
    racional z;
    z.p = x.p * y.p;
    z.q = x.q * y.q;
    z = reduz (z.p,z.q);
    return z;
}

/* 
Recebe racionais x=a/b e y=c/d e devolve z=x/y.
Note que z pode ser calculado como reduz(a*d,b*d).
*/
racional quociente(racional x, racional y) {
    racional z;
    z.p = x.p * y.q;
    z.q = x.q * y.p;
    z = reduz (z.p,z.q);
    return z;
}
