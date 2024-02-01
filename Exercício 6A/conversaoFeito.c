/* Programa para converter o codigo decimal de um elemento ASCII em uma string de tamanho 1*/

/* Adapte a funcao para converter o int no elemento ASCII que ele representa. */
char* converter(int *i){
    char* novo;
    novo = malloc(sizeof(char));
    novo = i;
    
    return novo;
    
    
    }

/* Funcao principal do programa, nao a altere. */
int main(){
    int i;
    scanf("%d", &i); //lendo o inteiro
    printf("%s", converter(&i));
    return 0;
}