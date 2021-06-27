#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0

struct  soldado{   
    char nome[50];
    struct soldado *next;
}*inicio;

void inicializa(){   
    inicio = NULL; 
}
// insere um registro na lista.
int insereNaLista(struct soldado *v){ 
    struct soldado *andarilho=inicio;
	if (inicio==NULL){ 
        inicio = v; 
        v->next = v; 
        return TRUE; 
    }
	do{
        if (andarilho->next == inicio){
            andarilho->next = v; 
            v->next=inicio; 
            return TRUE;
        }
        else{
            andarilho=andarilho->next;
        }
    }while(andarilho != inicio);
        return TRUE;
	}

int empty(){ 
        if (inicio==NULL) 
        return TRUE;
    return FALSE;
}

void imprime(){ 
    struct soldado *andarilho;
    andarilho=inicio;
    if (empty()){
	    printf("\nNinguem no Circulo!"); 
        return;
    };
    printf("\n\nSoldados do Circulo:");
    do {
        printf("\nNome: %s\n",andarilho->nome);
        andarilho=andarilho->next;
    }while (andarilho != inicio);
}

int lerArquivo(){
    FILE *fp;
    struct soldado *novo;
    inicializa();
    if( (fp= fopen("josephus.txt","a+")) == NULL){
        printf("\nERRO: Nao foi possivel abrir o arquivo");
	    printf("'josephus.txt' !");
	    return FALSE; 
    };
	while (!feof(fp)){
	     novo = (struct soldado *) malloc(sizeof(struct soldado));
	     fscanf(fp,"\n%s",novo->nome);
	     insereNaLista(novo);
	}
    fclose(fp);
    return TRUE;
}

int getQuantidade(struct soldado *lista){ 
    int saida = 0;
	struct soldado *c=lista;
        while(c->next != lista) {
            saida++; 
            c=c->next;
        }
    return saida;
}

void Josephus(int n){ 
    struct soldado *andarilho=inicio;
    struct soldado *anterior=inicio;
    int contador=0;
    int tamanho;

    if (empty()){ 
        printf("\nNinguém no Circulo!"); 
        return;   
    };
	do{
	    if (++contador != n){ 
            anterior=andarilho; 
            andarilho=andarilho->next; 
        }
        else {
	        if (andarilho == inicio){
                inicio = andarilho->next;
            }
	         printf("\nO soldado: %s foi morto", andarilho->nome);
	         andarilho = andarilho->next;
	         anterior->next = andarilho;
	         contador=0;
	         tamanho =getQuantidade(inicio);
	    }
	}while( tamanho>1);
	if (tamanho==1){
        printf("\n\n O soldado <<%s>> eh o sobrevivente!",inicio->nome);
    }
}

int main(){  
    if (lerArquivo()){
        imprime();
	    Josephus(3);
	 }
	return TRUE;
}


