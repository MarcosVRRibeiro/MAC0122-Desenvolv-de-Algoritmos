/* Arquivo de interface da biblioteca de manipulacao de numeros racioais 

Este arquivo deve conter apenas definicoes de novos tipos e prototipos de 
funcoes (declaracoes). Coloque as definicoes das funcoes no arquivo racionais.c
e o programa principal em programa.c.

Nao coloque diretivas de #include nesse arquivo.
*/
#ifndef RACIONAIS_H
/* Definimos uma constante que nos diz se esse arquivo já foi "#included" antes
Essa é um boa prática que evita que este arquivo seja incluído mais de uma vez, 
quando múltiplos arquivos-fonte são concatenados para compilar um programa. */
#define RACIONAIS_H

/* Tipo de dado definido pelo usuario, representando um numero racional.

Por convencao, q > 0 e p e q sao co-primos, ou seja, o maior divisor comum entre
eles e' igual a 1.
*/
typedef struct {
   int p, q;
} racional;

/* Recebe inteiros p e q e devolve o racional representando p/q, tal que q > 0
 e p e q devem ser coprimos. */
racional reduz(int p, int q);
/* Recebe racionais x e y e devolve x + y. */
racional soma(racional x, racional y);
/* Recebe racionais x e y e devolve z = x*y. */
racional produto(racional x, racional y);
/* Recebe racionais x=a/b e y=c/d e devolve z=x/y.
Note que z pode ser calculado como reduz(a*d,b*d).
*/
racional quociente(racional x, racional y);

#endif