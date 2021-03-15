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

int mostra_opcoes(){
    int opcao;
    printf("\n 1 - Incluir novo valor na lista;");
    printf("\n 2 - Motrar lista;");
    printf("\n 3 - Mostrar numeros pares da lista");
    printf("\n 4 - Encerrar programa;");
    printf("\n Insira a opcao desejada:");
    scanf("%d", &opcao);
    return opcao;
}

void mostra_pares(lista * lista){
    registro * l;

    if(lista->inicio == NULL){
        printf("\nLista Vazia!");
    }
    else{
        l=lista->inicio;
        while(l!=NULL){
            if(l->valor%2==0){
                printf("\nValor: %d", l->valor);
            }
            l = l->prox;
        }
    }
}

int main(){
    lista * l;
    int aux;
    int opcao;
    l=adiciona_lista();

    while(opcao!=4){
        opcao = mostra_opcoes();
        if(opcao==1){
            printf("\nValor que deseja incluir na lista:");
            scanf("%d",&aux);
            incluir_final(l,aux);
            printf("Valor incluso!");
        }
        else if(opcao==2){
            mostra_lista(l);
        }
        else if(opcao==3){
            mostra_pares(l);
        }
    }
    return 0;
}