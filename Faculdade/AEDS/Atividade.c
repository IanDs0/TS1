#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//dados das pessoas
typedef struct Dados {

    int cpf,code;
    char name[25];

}dados;

//a lista em si
typedef struct Pessoa{

    dados dados;
    
    struct Pessoa *D;
    struct Pessoa *E;

}P;

//separar as pontas
typedef struct Pontas{

    P *esquerda;
    P *direita;
    
    int tam;

}Pontas;

void inicializar(Pontas *O) {

    O->direita=NULL;
    O->esquerda=NULL;

}

void Fim(Pontas *O, dados D){

    P *novo = (P*) malloc(sizeof(P));

    novo->dados.cpf=D.cpf;
    novo->dados.code=D.code;
    strcpy(novo->dados.name,D.name);
    
    if (O->tam==0)
    {
        
        novo->E=NULL;
        novo->D=NULL;

        O->esquerda = novo;
        O->direita = novo;

    }else
    {
        
        novo->D = NULL;
        novo->E = O->direita;

        O->direita->D = novo;
        O->direita = novo;

    }
    
    O->tam++;
    
}

void Inicio(Pontas *O, dados E){

    P *novo = (P*) malloc(sizeof(P));

    novo->dados.cpf=E.cpf;
    novo->dados.code=E.code;
    strcpy(novo->dados.name,E.name);

    if (O->tam==0)
    {
        
        novo->E=NULL;
        novo->D=NULL;

        O->esquerda = novo;
        O->direita = novo;

    }else
    {
        
        novo->D = O->esquerda;
        novo->E = NULL;

        O->direita->E = novo;
        O->esquerda = novo;

    }
    
    O->tam++;
    
}

void Retira_Fim(Pontas *O, dados *E){

    P  *aux = (P*) malloc(sizeof(P));

    aux = O->direita;

    if (O->tam<=0)
    {
        printf("Error");
    }else
    {
        
        *E = aux->dados;

        O->tam--;
        O->direita=aux->E;

        free(aux);

    }
}

void Retira_Inicial(Pontas *O, dados *E){

    P  *aux = (P*) malloc(sizeof(P));

    aux = O->esquerda;

    if (O->tam<=0)
    {
        printf("Error");
    }else
    {
        
        *E = aux->dados;

        O->tam--;
        O->esquerda=aux->D;

        free(aux);

    }
}

void PrintaDados(dados *E){

    printf("\nCPF: %d",E->cpf);
    printf("\nCodgo: %d",E->code);
    printf("\nNome: %s",E->name);

}

int main(){ 
    
    Pontas *Dados_Pessoa = (Pontas *) malloc(sizeof(Pontas));

    int op;

    inicializar(Dados_Pessoa);

    dados *Dados = (dados *) malloc(sizeof(dados));

    do
    {

        printf("\nDigite:\n0)Sair\n1)Mostrar valor a Direita:\n2)Mostrar valor a Esquerda:\n3)Incluir dados:\n4)Retirar valor a Esquerda:\n5)Retirar valor a Direita:\n");
        scanf("%d", &op);
        
        switch (op)
        {

        case 1:

            PrintaDados(&Dados_Pessoa->direita->dados);
            
            break;
        
        case 2:

            PrintaDados(&Dados_Pessoa->esquerda->dados);

            break;

        case 3: 
        
            printf("\nDigite o DADOS a ser incluido:\n");

            if (Dados_Pessoa->tam%2==0)
            {

                //direita
                printf("\nDigite NOME: ");
                gets(&Dados->name,25,stdin);

                printf("\nDigite CPF: ");
                scanf("%d",&Dados->cpf);

                printf("\nDigite CODIGO: ");    
                scanf("%d",&Dados->code); 

                Fim(Dados_Pessoa, *Dados);               
               
            }else{

                //esquerda
                printf("\nDigite NOME: ");
                fgets(&Dados->name,25,stdin);

                printf("\nDigite CPF: ");
                scanf("%d",&Dados->cpf);

                printf("\nDigite CODIGO: ");    
                scanf("%d",&Dados->code);

                Inicio(Dados_Pessoa, *Dados);

            }

            break;

        case 4:

            Retira_Inicial(Dados_Pessoa, Dados);

            PrintaDados(Dados);

            break;

        case 5:

            Retira_Fim(Dados_Pessoa, Dados);

            PrintaDados(Dados);

            break;

        default:
            break;
        }

    } while (op > 0 && op < 6);
    
    return 0;
}