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

void eh_comum(lista *l1, lista *l2){
    registro * lt1, *lt2;
    lt1=l1->inicio;
    lt2=l2->inicio;
    while(lt2->prox!=NULL){
        while(lt1->prox!=NULL){
            if(lt1->valor==lt2->valor){
                printf("\nValor: %d", lt1->valor);
                lt1 = lt1->prox;
            }
            else{
                //printf("aqui:%d", lt1->valor);
                lt1 = lt1->prox;
            }
        }
        lt1 = l1->inicio;
        lt2 = lt2->prox;
    }
}

int main(){
    lista * l1, * l2;
    int aux;
    int opcao;
    int variavel;
    
    l1=adiciona_lista();
    l2=adiciona_lista();

    printf("\nNumeros de valores a serem alocados:");
    scanf("%d",&opcao);

    if(opcao%2!=0){
        aux = opcao/2;
        for(int i=0;i<opcao-aux;i++){
            printf("\nValor:");
            scanf("%d", &variavel);            
            incluir_final(l1, variavel);
        }
        for(int i=0;i<aux;i++){
            printf("\nValor:");
            scanf("%d", &variavel);                
            incluir_final(l2, variavel);
        }
    }
    else{
        for(int i=0;i<opcao/2;i++){
            printf("\nValor:");
            scanf("%d", &variavel);            
            incluir_final(l1, variavel);
        }
        for(int i=0;i<opcao/2;i++){
            printf("\nValor:");
            scanf("%d", &variavel);                
            incluir_final(l2, variavel);
        }
    }

    //printf("\nLista 1:");
    //mostra_lista(l1);
    //printf("\nLista 2:");
    //mostra_lista(l2);
    
    
    printf("\nE comum entre as duas listas:");
    eh_comum(l1,l2);
    
    return 0;
}