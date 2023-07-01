#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carro {
    char proprietario[100];
    char combustivel;
    char modelo[50];
    char cor[30];
    char placa[7];
    int chassi;
    int ano;
    struct carro* prox;
}Carro;

Carro* cadastroDados() {
    Carro* novoCarro =(Carro*)malloc(sizeof(Carro));

    fflush(stdin);
    printf ("Proprietario do veiculo: ");
    scanf ("%[^\n]s", novoCarro->proprietario);

    fflush(stdin);
    printf ("Tipo de combustivel:\n[A]-->Alcool | [D]-->Diesel | [G]-->Gasolina\nOPCAO: ");
    scanf ("%c", &novoCarro->combustivel);

    fflush(stdin);
    printf ("Modelo do veiculo: ");
    scanf ("%[^\n]s", novoCarro->modelo);

    fflush(stdin);
    printf ("Cor: ");
    scanf ("%[^\n]s", novoCarro->cor);

    fflush(stdin);
    printf ("Numero Chassi: ");
    scanf ("%d", &novoCarro->chassi);

    fflush(stdin);
    printf ("Ano do veiculo: ");
    scanf ("%d", &novoCarro->ano);

    fflush(stdin);
    printf ("Placa do veiculo (use letras maiusculas): ");
    scanf ("%[^\n]s", novoCarro->placa);

    novoCarro->prox = NULL;
    return novoCarro;
}

//carros ano 2010 ou posterior e movidos a diesel
void listagemTipo1(Carro* lista) {  

    Carro* atual = lista;
    int i = 1;

    printf("\nClientes com modelos ano 2010 ou posterior:\n");

    while (atual != NULL) {
        if (atual->ano >= 2010 && (atual->combustivel == 'D' || atual->combustivel == 'd')) {
             printf("\nProprietario: %s\n\n", atual->proprietario);
        } else {
        printf("\nNenhum carro foi adicionado a lista.\n");
        }
        atual = atual -> prox;
        i ++;
    } 
}

//carros que placas que começam com a letra "J" e terminam com 0,2,4 ou 7.
void listagemTipo2 (Carro* lista) { 

    Carro* atual = lista;
    int i = 1;
    printf ("\nPlacas que comecam com 'J' e terminam com 0, 2, 4 ou 7:\n");

    while (atual != NULL) {
        char ultimaL = atual->placa[strlen(atual->placa) - 1];
        if (atual->placa[0] == 'J' && (ultimaL == '0' || ultimaL == '2' || ultimaL == '4' || ultimaL == '7')) {
            printf ("\nPlaca: %s\n", atual->placa);
            printf ("\nProprietario do veiculo: %s\n", atual->proprietario);
            printf ("_________________________");
        } else {
        printf("\nNenhum carro foi adicionado a lista.\n");
    }
        atual = atual -> prox;
        i ++;
    }
}

//veículos com placas com segunda letra vogal e soma par para números
void listagemTipo3 (Carro* lista) {
    
    Carro* atual = lista;
    int i = 1;
    printf ("\nVeiculos com placas que possuem segunda letra como uma vogal e resultado par para soma de todos os numeros: ");

    while (atual != NULL) {
        if (atual->placa[1] == 'A' || atual->placa[1] == 'E' || atual->placa[1] == 'I' || atual->placa[1] == 'O' || atual->placa[1] == 'U' && (atual->placa[3] + atual->placa[4] + atual->placa[5] + atual->placa[6] % 2 == 0)) {
            printf ("\n\nModelo do veiculo:%s\n", atual->modelo);
            printf ("\nCor do veiculo:%s\n", atual->cor);
            printf ("\n_________________________\n");
        }else {
            printf("\n\nNenhum carro adicionado a lista.\n");
        }

        atual = atual -> prox;
        i++;
    }
}

//mudança de proprietário
void listagemTipo4 (Carro* lista) {
    Carro* atual = lista;
    int chassi, i = 1;

    while (atual != NULL) {

        if (atual->placa[3] != '0' && atual->placa[4] != '0' && atual->placa[5] != '0' && atual->placa[6] != '0') {
            printf ("Digite o chassi do veiculo ao qual deseja mudar o proprietario: ");
            scanf ("%d", &chassi);

            if (chassi == atual->chassi) {
                printf ("Digite o nome do novo usuario: ");
                scanf ("%[^\n]s", atual->proprietario);
            } else {
                printf("\nNenhum carro adicionado a lista.\n");
        }
        
        atual = atual -> prox;
        i++;
        }
    }  
}

int main () {

    Carro* lista = NULL;
    int adicionar, mudar;

     do {
        Carro* novoCarro = cadastroDados();

        //adicionar o carro a lista
        if (lista == NULL) {
            lista = novoCarro;
        } else {
            Carro* atual = lista;
            while (atual->prox != NULL) {
                atual = atual->prox;
            }
            atual->prox = novoCarro;
        }

        printf("\nCarro cadastrado com sucesso!\n");

        printf("\n\nDeseja adicionar mais um veiculo?\n[1] SIM | [2] NAO:  ");
        scanf("%d", &adicionar);
        fflush (stdin);

    } while (adicionar == 1);

    //chamada das funções.

        printf ("\nVEICULOS ADICIONADOS:\n\n");
        listagemTipo1 (lista);
        listagemTipo2 (lista);
        listagemTipo3 (lista);

        printf("\n\nDeseja mudar algum proprietario?\n[1] SIM | [2] NAO\nOPCAO:");
        scanf("%d", &mudar);

        if (mudar == 1) {
            listagemTipo4 (lista);
        }

        printf ("\n\n\nFIM DO CADASTRO.\n\n");

}