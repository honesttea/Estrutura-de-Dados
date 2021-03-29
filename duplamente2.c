#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Criar as strcuts
typedef struct lista{
    int qtd;
    struct registro *inicio;
    struct registro *fim;
} lista;

typedef struct registro{
    int ano;
    char marca[30];
    char modelo[30];
    float preco;
    char chassi[30];
    struct registro *prox;
    struct registro *ant;
} registro;


//Prototipar as funções;
lista *cria_lista();
registro *cria_registro();
void mostrar(lista *l, int inverso);
void incluir_no_inicio(lista *l, int x);
void incluir_no_final(lista *l, int x);
void menu(lista *l);
void retira_primo(lista * l);
void tem_igual(lista * l);
void buscar_por_numero(lista * l);
void incluir_ordenada(lista * l, int x);
void busca(int x, registro *le);
void remove_da_lista (registro *p);


int main()
{
    lista * l1;
    






    return 0;
}


lista *cria_lista(){
    lista *novo;
    novo = (lista*)malloc(sizeof(lista));
    return novo;
}

void remove_da_lista(registro *p){
   registro *lixo;
   lixo = p->prox;
   p->prox = lixo->prox;
   free (lixo);
}

registro *cria_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    return novo;
}

void incluir_no_inicio(lista *l, registro *x)
{
    if (l == NULL)
    {
        printf("\n lista nao alocada");
        return;
    }

    registro *novo;
    novo = aloca_registro();
    novo->ano = x->ano;
    strcpy(novo->chassi, x->chassi);
    strcpy(novo->marca, x->marca);
    strcpy(novo->modelo, x->modelo);
    novo->preco = x->preco;

    if (l->inicio == NULL && l->fim == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
    }
    l->qtd++;
}

void incluir_no_final(lista *l, int x)
{
    if (l == NULL)
    {
        printf("\n lista nao alocada");
        return;
    }

    registro *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL && l->fim == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
    }
    l->qtd++;
}

void mostrar(lista *l, int inverso)
{
    registro *aux;
    if (l->inicio == NULL || l->fim == NULL)
    {
        printf("\n lista vazia");
        return;
    }

    if (!inverso)
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("\n %d", aux->valor);
            aux = aux->prox;
        }
    }
    else
    {
        aux = l->fim;
        while (aux != NULL)
        {
            printf("\n %d", aux->valor);
            aux = aux->ant;
        }
    }
}

void menu(lista *l)
{
    int opcao, numero;
    registro * carro;
    do{
        scanf("%d", &opcao);
        if(opcao==1){
            scanf("%d",carro->ano);
            scanf("%f",carro->preco);
            scanf("%s",carro->modelo);
            scanf("%s",carro->chassi);
            scanf("%s",carro->marca);
            incluir_no_inicio(l, carro);
        }
        else if(opcao==2){
            busca(,l->inicio);
        }
        else if(opcao==3){

        }
        else if(opcao==4){

        }
        else if(opcao==5){

        }
        else{
            printf("Opcao invalida!");
        }
    }while(opcao!=5);
}


void busca(int x, registro *le)
{
    registro *p;
    p = le;
    while (p != NULL || strcmp(p->chassi,le->chassi)!=0){ 
        p = p->prox; 
    }
    printf(p);
}