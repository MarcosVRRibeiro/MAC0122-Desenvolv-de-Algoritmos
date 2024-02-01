#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000
#define MAX_PATH 256

typedef struct pilha{
    char fragmento[MAX];
    struct No * prox;
} No;

void Empilha(No *cabeca, char *recorte){  
    if(cabeca != NULL ){  
        No *novo_no = malloc(sizeof(No));
        strcpy(novo_no->fragmento, recorte);      
        novo_no->prox = cabeca->prox;
        cabeca->prox = novo_no;
	}
}

char *Desempilha(No *cabeca){
	if (cabeca != NULL){
		No *seguinte = cabeca->prox;
		if (seguinte){
			char frag[MAX];
            strcpy(frag, seguinte->fragmento);
			cabeca->prox = seguinte->prox;
			free(seguinte);
			return frag;
		}
	}
	return;
}

void ImprimePilha(No *pilha){
        pilha = pilha->prox;
        int posicao=0;
        while(pilha != NULL){
            printf("\n>>Pos %d:", posicao);
            printf("\n%s", pilha->fragmento);
            printf("\n");                
            pilha = pilha -> prox;
            posicao++;
        }
        
}

typedef struct lista {
    int num_linha;
    char text_linha[MAX];
    struct lista *prox;
} Lista;

/*variaveis global para primeiro e ultimo no*/
Lista *Lcabeca = NULL; 
Lista *Lcauda = NULL;


/* Recebe a string linha e seu tamanho n, string padrao e seu tamanho m, string substituto e seu tamanho p, e uma string novaLinha*/
void substituir(char linha[], int n, char padrao[], int m, char substituto[], int p, char novaLinha[]) {
    int i, k, g, ondocorr, ocorr=0;
    m = strlen(padrao); 
    n = strlen(linha);  /* palavra que será varrida */
    /* Essa parte busca a posição de onde começa a ocorrencia de a em b*/
    for (k = 0; k <= n; ++k) {
        for (i = 0; i < m && padrao[i] == linha[i+k]; i++); {
            if (i == m) {ondocorr=k; ocorr++;}
            }
        }
    if (ocorr > 0) {
        for (g = ondocorr; g < ondocorr+p && ocorr > 0; g++){
            novaLinha[g] = substituto[g-ondocorr];
            //printf("\nnova linha primeiro for: %s", novaLinha);
            }
        for (g=0; g<ondocorr && ocorr > 0; g++){
            novaLinha[g]=linha[g];
            //printf("\nnova linha segundo for: %s", novaLinha);
            }
        int z = n+(p-1)*ocorr; 
        for (g=ondocorr; g <= z && ondocorr+p != n+p-m && ocorr > 0; g++){
        novaLinha[g+p]=linha[g+m];
        //printf("\nnova linha terceiro for: %s", novaLinha);
        }
        //printf("\n");
        ocorr = ocorr - 1;

        if (ocorr != 0 && ocorr > 0) {
        char p[MAX]; 
        strcpy(p, novaLinha); 
        substituir(p, strlen(p), padrao, strlen(padrao), substituto, strlen(substituto), novaLinha);
        }
    }
}

/*Recebe uma string e uma string texto e retorna a posicao da ocorrencia da string no texto*/
int OndeOcorre(char *string, char *texto, int posi_linha) {
    int i, k, m, n, o = 0;
    int ondOcorr;

    m = strlen(string); n = strlen(texto);
    //printf("\nentro na ondeocorre");
    for (k = posi_linha; k <= n-m; k++){
        i = 0;
        while (i < m && string[i] == texto[i+k]) i++;
        if (i>=m) {o++; return ondOcorr = k+m;}
    }
    return -1;
}

/*Recebe o numero da posicao da linha e do cursor em que será feita a alteracao*/
void InsereNaLinha(int posi_texto, int posi_linha, char* novaString) {
    Lista *aux = Lcabeca;
    unsigned int tamanhoNovaString = strlen(novaString), tamanhoStringAtual = strlen(aux->text_linha), i;
    char *stringAux = malloc((tamanhoStringAtual+tamanhoNovaString)*sizeof(char));

    while(aux->num_linha != posi_texto) {aux = aux->prox;}
    strcpy(stringAux, aux->text_linha);

    for(i=posi_linha; i<tamanhoNovaString+tamanhoStringAtual-1; i++) {
        aux->text_linha[i+tamanhoNovaString-1] = stringAux[i];      
        }

    for(i=0; i<tamanhoNovaString-1; i++) {
        aux->text_linha[posi_linha+i] = novaString[i];            
        }
}

/*Recebe um ponteiro para a lista encadeada e insere nova linha no final*/
void insereLinhaNaLista(char *linha, int n) {
    Lista *novoPtr = (Lista*)malloc(sizeof(Lista));
    int ccc = strlen(linha);
    linha[ccc-1] = '\0';
    strcpy(novoPtr->text_linha, linha);

    if (Lcabeca == NULL) {
        Lcabeca = novoPtr;
        Lcauda = novoPtr;
        novoPtr->num_linha = n;
        }
    
    else if (Lcabeca != NULL) {
        
        Lcauda->prox = novoPtr;
        Lcauda = novoPtr;
        Lcauda->prox = NULL;
        novoPtr->num_linha = n;
    }
}


int main(){
    char input[MAX_PATH];
    int posi_linha=0, posi_texto=0;
    int posiLinha_lembrada, posiTexto_lembrada;
    Lista *aux = Lcabeca;
    No *cabecaPilha = malloc(sizeof(No));
    cabecaPilha->prox = NULL;
    int a=1;
    
       
    while (a==1) {
        Lista *imprimir = Lcabeca;
        if (Lcabeca != NULL)
        {
            while(imprimir->num_linha != posi_texto){
                imprimir = imprimir->prox;
                }  
        } 

        //Imprimindo a atualizacao feita  
        if (Lcabeca != NULL && posi_texto == 0){
            printf("%s",Lcabeca->text_linha);
            }
        
        
        else if (Lcabeca != NULL) { // imprimindo as linhas                
            printf("%s",imprimir->text_linha); // imprimindo as linhas
            }
        
        char cursor[MAX];
        if (Lcabeca != NULL) { //Controle do cursor
            int contC;            
            
            for(contC = 0; contC <= strlen(imprimir->text_linha); contC++) {
                cursor[contC] = ' ';
                }        
            
            cursor[posi_linha+1] = ' ';

            if (posi_texto == 0 && posi_linha == 0 ) cursor[0] = 'M';          
            if (posi_texto == posiTexto_lembrada) {
                cursor[posiLinha_lembrada]='M';
            }
            cursor[posi_linha]='^';

            printf("\n%s", cursor);
            
            }
        
        printf("\n%d,%d>", posi_texto, posi_linha);
        fgets(input, MAX, stdin);

        
        int passo;
        for(passo=0; passo <= strlen(input); passo++) {
        //Inicio da execucao das instrucoes recebidas no input


        // Is - Insere a string 's' na posição atual do texto
        if (input[passo] == 'I') {
            int size = strlen(input);
            unsigned int i;
            char *string = malloc((size-passo)*sizeof(char));

            for (i=0; i < strlen(input); i++) {
                string[i] = input[passo+i+1];               
            }
            
            if (Lcabeca == NULL) {
                insereLinhaNaLista(string, 0);
                posi_linha = strlen(string)+posi_linha;
            }
            else {
                InsereNaLinha(posi_texto,posi_linha,string);
                posi_linha = strlen(string)+posi_linha;
                }
            passo = strlen(input);            
        }

        //An - Carrega o conteudo do arquivo de texto de nome n no editor
        else if (input[passo] == 'A') {
            Lcabeca = NULL;
            char linha[MAX], s[MAX_PATH];
            FILE *text;
            unsigned int i;
                       
            //retirando o A da string pra poder abrir o arquivo
            for (i=0; i < strlen(input)-2; i++) {
                s[i]=input[passo+i+1];
            }
            text = fopen(s, "r");
            if (text == NULL) {printf("Nao foi possivel abrir o arquivo.");}
             
            /*Armazenando linhas na lista encadeada com cabeça e enumerando as linhas*/
            int num = 0;
            while(fgets(linha, MAX, text) != NULL) {
                insereLinhaNaLista(linha, num);
                num++;
                }
            fclose(text);

            Lista *aux = Lcabeca;
            while(aux != NULL) {
            aux = aux->prox;
                }
            passo = strlen(input);  
        }
        
        //(Sobre)escreve o conteudo do editor no arquivo de texto de nome n
        else if (input[passo] == 'E') {
            FILE *text1;
            char linha[MAX], s[MAX_PATH];
            unsigned int i;

            //retirando o E da string pra poder abrir o arquivo
            for (i=0; i+passo < strlen(input)-2; i++) {
                s[i]=input[passo+i+1];     
                }
            printf("\nesse e o s: .%s.\n", s);
            text1 = fopen(s, "w");
            // Aqui copio so a linha do lcabeca porque nao e possivel descer linhas
            //sem arquivo aberto
            fputs(Lcabeca->text_linha, text1);
            fclose(text1);
            passo = strlen(input);  
        }

        //Move o cursor um caractere a frente
        else if (input[passo] == 'F') {
            aux = Lcabeca;
            if (Lcabeca != NULL)
            while(aux->num_linha != posi_texto){
                aux = aux->prox;
                }
            if (Lcabeca != NULL && posi_linha < strlen(aux->text_linha)) posi_linha = posi_linha + 1; 
        }

        //Move o cursor um caractere para tras
        else if (input[passo] == 'T') {
            if (posi_linha > 0) posi_linha = posi_linha - 1; 
        }

        //Move o cursor para o inıcio da linha atual
        else if (input[passo] == 'O') {
            posi_linha = 0;
            
        }

        //Move cursor para inıcio da proxima palavra (dentro da mesma linha)
        else if (input[passo] == 'P') {
            aux = Lcabeca;
            if (Lcabeca != NULL)
            while(aux->num_linha != posi_texto){
                aux = aux->prox;
                }
            int tamang = strlen(aux->text_linha);     
            int guardar = posi_linha;

            char teste = aux->text_linha[posi_linha];
            while(teste != ' ' && posi_linha < tamang) {
                teste = aux->text_linha[posi_linha];
                posi_linha++;                
            }
            if (guardar != tamang-1 && posi_linha == tamang-1) posi_linha = guardar;
        }

        //Move cursor para inıcio da palavra atual
        else if (input[passo] == 'Q') {
            aux = Lcabeca;
            if (Lcabeca != NULL)
            while(aux->num_linha != posi_texto){
                aux = aux->prox;
                }

            
            int guardar = posi_linha;
            char teste = aux->text_linha[posi_linha];
            
            while(teste != ' ' && posi_linha > 0) {
                teste = aux->text_linha[posi_linha];
                posi_linha--;                
            }
            
            if (guardar != 0 && posi_linha == 0) posi_linha = guardar;
            
        }

        //Move o cursor para o fim da linha atual
        else if (input[passo] == '$') {
            int i;
            aux = Lcabeca;
            if (Lcabeca != NULL) {
                while(aux->num_linha != posi_texto){
                    aux = aux->prox;
                    }
                posi_linha = strlen(aux->text_linha);
                }

        }

        //Move o cursor para o inıcio da linha :(x)
        else if (input[passo] == ':') {
            char x;           
            x = input[passo+1];
            int xN = x - '0';
            

            int i;
            char numeros[MAX_PATH];
            for (i=0; input[i+1] != '\0'; i++) {
                numeros[i]=input[passo+i+1];     
                }
            
            if( xN <= Lcauda->num_linha) {
                posi_linha = 0;
                posi_texto = xN;
            }
            else if (x == 'F') {
                posi_texto = Lcauda->num_linha;
            }
        }

        //Apaga o caractere da posicao atual
        else if (input[passo] == 'D') {
            int i;
            aux = Lcabeca;
            while(aux->num_linha != posi_texto){
                aux = aux->prox;
                }

            char *stringAux = aux->text_linha;
            for(i=posi_linha; i<strlen(aux->text_linha); i++) {
                aux->text_linha[i] = stringAux[i+1];
                }
        }

        //Marca (lembra) a posicao atual do cursor
        else if (input[passo] == 'M') {
            posiLinha_lembrada=posi_linha;
            posiTexto_lembrada=posi_texto;
        }

        //Exibe a pilha de memoria, comecando pelo topo.
        else if (input[passo] == 'Z') {
            ImprimePilha(cabecaPilha);
        }

        //Desempilha e insere o conteudo do topo pilha na posicao atual
        else if (input[passo] == 'V') {
            char ctrlV[MAX];
            strcpy(ctrlV, Desempilha(cabecaPilha));            
            InsereNaLinha(posi_texto,posi_linha, ctrlV);
        }

        //Empilha o texto entre a posicao marcada e a posicao atual (sem modifica-lo)
        else if (input[passo] == 'C') {
            aux = Lcabeca;
            if (Lcabeca != NULL)
            while(aux->num_linha != posi_texto){
                aux = aux->prox;
                }

            char stringCC[MAX];
            strcpy(stringCC, aux->text_linha);
            int copia;

            //recuando a string ate a posi marcada
            for (copia=0; copia <= posi_linha; copia++) {
                stringCC[copia]=aux->text_linha[copia+posiLinha_lembrada];
            }
            stringCC[posi_linha+1] = '\0';        
            Empilha(cabecaPilha, stringCC);
        }

        //Empilha o texto entre a posicao marcada e a posicao atual e o deleta
        else if (input[passo] == 'X') {
            aux = Lcabeca;
            if (Lcabeca != NULL)
            while(aux->num_linha != posi_texto){
                aux = aux->prox;
                }

            char stringCC[MAX];
            strcpy(stringCC, aux->text_linha);
            int copia;
            //recuando a string ate a posi marcada
            for (copia=0; copia <= posi_linha; copia++) {
                stringCC[copia]=aux->text_linha[copia+posiLinha_lembrada];
            }
            stringCC[posi_linha+1] = '\0';
            Empilha(cabecaPilha, stringCC);
            char *stringAUXc;
            strcpy(stringAUXc, aux->text_linha);


            for (copia = 0; copia < strlen(aux->text_linha)-strlen(stringCC);  copia++) {
                aux->text_linha[posiLinha_lembrada+copia]=stringAUXc[posi_linha+copia];              
            }
            aux->text_linha[strlen(aux->text_linha)-strlen(stringCC)] = '\0';
        }

        //Bs Busca pela proxima ocorrencia do padrao 's' no texto
        else if (input[passo] == 'B') {
            Lista *Buscaaux = Lcabeca;
            int AuxPosi_linha = posi_linha;

            while(Buscaaux->num_linha != posi_texto){
                Buscaaux = Buscaaux->prox;
                }

            char stringOO[MAX];
            unsigned int i, sizeS = strlen(input);

            for (i=0; i < sizeS-2; i++) {
                stringOO[i] = input[passo+i+1];       
                }
            stringOO[sizeS-2]='\0';
            AuxPosi_linha = OndeOcorre(stringOO, Buscaaux->text_linha, posi_linha);          
            if (AuxPosi_linha > 0) {posi_linha=AuxPosi_linha;}  

            while (Buscaaux != NULL && AuxPosi_linha == -1) {
                Buscaaux = Buscaaux->prox;
                AuxPosi_linha = 0;
                AuxPosi_linha = OndeOcorre(stringOO, Buscaaux->text_linha, AuxPosi_linha);
                }
                if (AuxPosi_linha > 0) {
                posi_texto = Buscaaux->num_linha;
                posi_linha=AuxPosi_linha;
            } 
            passo = strlen(input);          
        }

        //Substitui toda ocorrencia de s por r no texto a partir da posicao atual - Ss/r
        else if (input[passo] == 'S') {
            //separar as strings do input
            char dupla[MAX];
            int i;
            for (i=0; i < strlen(input)-2; i++) {
                dupla[i]=input[passo+i+1];
            }

            char *padraoTok, *substitutoTok;
            padraoTok = strtok(dupla,"/");   
            substitutoTok = strtok(NULL, "/");

            Lista *AuxTroca = Lcabeca;
            char StringAux[MAX];

            while (AuxTroca != NULL) {
                substituir(AuxTroca->text_linha, strlen(AuxTroca->text_linha), padraoTok, strlen(padraoTok), substitutoTok, strlen(substitutoTok), StringAux);
                strcpy(AuxTroca->text_linha, StringAux);               
                AuxTroca = AuxTroca->prox;
            }
            passo=strlen(input);
        }

        //Separa linha atual na posicao do cursor
        else if (input[passo] == 'N') {
            if (Lcabeca != NULL) {
                aux = Lcabeca;
                while(aux->num_linha != posi_texto){
                aux = aux->prox;
                }
                int SizeLinha = strlen(aux->text_linha);
                char metade1[MAX];
                char metade2[MAX];

                int contN;
                for(contN = 0; contN < posi_linha; contN++){
                    metade1[contN]=aux->text_linha[contN];
                }
                metade1[posi_linha]='\0';
                for(contN = 0; contN < strlen(aux->text_linha); contN++){
                    metade2[contN]=aux->text_linha[posi_linha+contN];
                }
                metade2[strlen(aux->text_linha)]='\0';
                strcpy(aux->text_linha, metade1);

                Lista *novoPtr = (Lista*)malloc(sizeof(Lista));
                strcpy(novoPtr->text_linha, metade2);
                novoPtr->num_linha = aux->num_linha+1;
                

                Lista *reserva = aux->prox;
                aux->prox = novoPtr;
                novoPtr->prox = reserva;

                Lista *reconta = reserva;               
                while(reconta != NULL){
                    reconta->num_linha = reconta->num_linha+1;
                    reconta=reconta->prox;
                    }     
                }
        }

        //Unir linha atual e a proxima
        else if (input[passo] == 'U') {
            Lista *auxiliar = Lcabeca;
            
            if (Lcabeca != NULL){
            while(auxiliar->num_linha != posi_texto){
                auxiliar = auxiliar->prox;
                }

            if(auxiliar->prox != NULL) {
                char *string2 = malloc(strlen(auxiliar->prox->text_linha)*sizeof(char));  //string da proxima linha 
                strcpy(string2, auxiliar->prox->text_linha);
                strncat(auxiliar->text_linha, string2, strlen(auxiliar->text_linha)+strlen(string2));
                 free(string2);
                }
            }
            Lista *reserve;
            reserve = auxiliar;
            auxiliar=auxiliar->prox;

            reserve->prox = auxiliar;

            Lista *reconta;
            reconta = reserve->prox;
            while(reconta != NULL){
                reconta->num_linha = reconta->num_linha -1;
                reconta=reconta->prox;
            }
           
        }

        //Encerra o programa
        else if (input[passo] == '!') {           
            return 0;
        }

        //Ir para proxima linha (manter a mesma coluna, se possivel)
        else if (input[passo] == 'J') { 
            //avançando as linhas
            Lista *aux = Lcabeca;
            int sizeLatual = strlen(aux->text_linha), sizeLprox=strlen(aux->prox->text_linha);

            while(aux->num_linha != posi_texto){
                aux = aux->prox;             
                }  

            if (aux->prox != NULL && aux != NULL) {
                posi_texto = posi_texto + 1;                
                aux = aux->prox;
                if (sizeLatual > sizeLprox) { //agora verificar se e possivel ficar na mesma coluna
                    posi_linha = sizeLprox;                   
                }
                }
        }

        //Ir para a linha anterior (manter a mesma coluna, se possivel)
        else if (input[passo] == 'H' && posi_texto > 0) {           
            Lista *aux = Lcabeca;
            posi_texto = posi_texto - 1;

            //Indo do topo para a uma antes
            while(aux->num_linha != posi_texto && posi_texto > 0){
                aux = aux->prox;
                }

            int sizeLatual = strlen(aux->text_linha);
            if (posi_linha > sizeLatual) { //agora verificar se e possivel ficar na mesma coluna
                posi_linha = sizeLatual;                   
            }
        
        }
        }
    }
    return 0;
}  