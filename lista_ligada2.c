#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int valor;
    struct registro * inicio;

}lista;

typedef struct registro
{

    int valor;
    struct registro * prox;

}registro;

registro * adiciona_registro(){

    /*
    * Funcao para adionar um novo vetor na lista ligada;
    * A funcao nao recebe nada e retorna um ponteiro do tipo "registro";
    * Primeiro eh alocado um valor inicial;
    * Depois eh colocado o proximo endereco da lista como NULL;
    * E retorna o ponteiro do endereco da lista;
    */

    registro * novo;
    novo = (registro*)malloc(sizeof(registro));
    novo->valor=0;
    novo->prox=NULL;
    return novo;

}

lista * adiciona_lista(){
    /*
    * Essa função serve para adicionar uma nova lista de vetores ligados;
    * É alocada a primeira posicao da lista e a próxima posicao
    * Primeiro eh alocado um valor inicial;
    * Depois eh colocado o proximo endereco da lista como NULL;
    * E retorna a primeira posicao da lista;
    */

    lista * novo;
    novo = (lista*)malloc(sizeof(lista));
    novo->valor=0;
    novo->inicio=NULL;
    return novo;
}

void incluir_final(lista * lista, int x){
    /*
    * A funcao recebe a lista e o valor da informação desejada;
    * Ela cria um novo registro e passa o valor 'x' pra ele;
    * Depois ele percorre a lista até achar o final;
    * Quando ela acha, adiciona o endereco de 'novo' no final e encerra a função;    
    */
    registro * novo, * a;
    novo = adiciona_registro();
    novo->valor = x;

    if(lista->inicio == NULL){
        lista->inicio = novo;
    }
    else{
        a = lista->inicio;
        while(a->prox != NULL){
            a=a->prox;
        }
        a->prox=novo;
    }
    lista->valor++;
}

void mostra_lista(lista * lista){
    registro * l;

    if(lista->inicio == NULL){
        printf("\nLista Vazia!");
    }
    else{
        l=lista->inicio;
        while(l!=NULL){
            printf("\nValor: %d", l->valor);
            l = l->prox;
        }
    }
}


int main(){
    lista * li, * lp;
    int aux;
    int opcao;
    li=adiciona_lista();
    lp=adiciona_lista();

    for(int i=0;i<10;i++){
        printf("\nInsira o valor:");
        scanf("%d", &aux);
        if(aux%2==0){
            incluir_final(lp, aux);
        }
        else{
            incluir_final(li, aux);
        }
    }

    printf("\nLista de Pares");
    mostra_lista(lp);
    printf("\nLista de Impares");
    mostra_lista(li);
    
    return 0;
}