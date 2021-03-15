#include <stdio.h>
#include <stdlib.h>

typedef struct cachorros
{
    char nome[30];
    int idade;
    char raca[30];
    char cor[30];
    int peso;
    float altura;
}cachorros;

void inserirCachorros(cachorros * c, int ent){
    for(int i=0;i<ent;i++){
        printf("\nColoque o nome:");
        scanf("%s", c[i].nome);
        printf("\nColoque a idade:");
        scanf("%d", c[i].idade);
        printf("\nColoque a raca:");
        scanf("%s", c[i].raca);
        printf("\nColoque a cor:");
        scanf("%s", c[i].cor);
        printf("Coloque o peso:");
        scanf("%d", c[i].peso);
        printf("Coloque a altura:");
        scanf("%f", c[i].altura);
    }
}

int main(void){
    int ent;
    int peso;
    float alto = 0;
    int velho = 0;
    int check=0;
    cachorros * c;

    printf("Coloque o numero de cachorros desejados:");
    scanf("%d", &ent);
    
    c = (cachorros*)malloc(sizeof(cachorros)*ent);

    inserirCachorros(c, ent);

    for(int i = 0;i<ent;i++){
        if(c[i].nome[0]=="m"||c[i].nome[0]=="M"){
            printf("\n%s comeca com a letra 'm'", c[i].nome);
        }
    }

    for(int i = 0;i<ent;i++){
        peso+=c[i].peso;
    }
    printf("\nO peso medio e de: %d Kg", peso);

    for(int i=0; i<ent; i++){
        if(c[i].altura>alto){
            alto = c[i].altura;
            check = i;
        }
    }
    print("\nO cachorro mais alto eh: %s com %.2f m.", c[check].nome, c[check].altura);
    
    for(int i =0; i < ent; i++){
        if(c[i].idade>velho){
            velho = c[i].idade;
            check = i;
        }
    }
    print("\nO cachorro mais velho eh: %s com %d m.", c[check].nome, c[check].idade);

    for(int i =0; i < ent; i++){
        if(c[i].altura>0.3){
            printf("\n%s tem mais de 30cm.'", c[i].nome);
        }
    }

    return 0;
}