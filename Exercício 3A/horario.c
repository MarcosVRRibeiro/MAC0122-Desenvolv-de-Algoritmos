#include <stdlib.h>
#include <stdio.h>

/* Registro para manipular horarios */
struct hm {
   int horas;
   int minutos;
};

typedef struct hm horario;

/* Funcao que calcula diferena entre dois horarios, assumindo que horario1 > horario2 */
horario diferenca(horario horario1, horario horario2){
    horario diff;
    diff.horas = 0;
    diff.minutos = 0;
    return diff;
}

int main(){
    horario h1, h2, hd;
    printf("Entre com primeiro horario no formato hora:minutos: ");
    scanf("%d:%d", &h1.horas, &h1.minutos);
    printf("Entre com segundo horario no formato hora:minutos: ");
    scanf("%d:%d", &h2.horas, &h2.minutos);
    /* Funcao diferenca espera que horario h1 seja mais adiantado que h2 */
    hd = diferenca(h1, h2);
    printf("A diferenca entre %d:%d e %d:%d e' %d:%d", h1.horas, h1.minutos, h2.horas, h2.minutos, hd.horas, hd.minutos);
    return 0;
}