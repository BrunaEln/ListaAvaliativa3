#include <stdio.h>
#include <stdlib.h>

typedef struct restaurante {
    char nome[50];
    char endereco[100];
    float precoMedio;
    char tipoComida[50];
    struct restaurante* proximo;
} Restaurante;

Restaurante* solicitarDados() {
    Restaurante* novoRestaurante = (Restaurante*)malloc(sizeof(Restaurante));

    fflush (stdin);
    printf("Digite o nome do restaurante: ");
    scanf("%[^\n]s", novoRestaurante->nome);

    fflush (stdin);
    printf("Digite o endereco do restaurante: ");
    scanf("%[^\n]", novoRestaurante->endereco);

    fflush (stdin);
    printf("Digite o preco medio do restaurante: ");
    scanf("%f", &(novoRestaurante->precoMedio));

    fflush (stdin);
    printf("Digite o tipo de comida do restaurante: ");
    scanf("%[^\n]", novoRestaurante->tipoComida);
    fflush (stdin);

    novoRestaurante->proximo = NULL;

    return novoRestaurante;
}

//funcao para listar restaurantes
void listarRestaurantes(Restaurante* lista) {
    if (lista == NULL) {
        printf("\nA lista de restaurantes esta vazia.\n");
        return;
    }

    Restaurante* atual = lista;
    int i = 1;

    printf("LISTA DE RESTAURANTES:\n");

    while (atual != NULL) {
        printf("\nRestaurante %d:\n", i);
        printf("\nNome: %s", atual->nome);
        printf("\nEndereco: %s", atual->endereco);
        printf("\nPreco Medio: R$ %.2f", atual->precoMedio);
        printf("\nTipo de Comida: %s\n", atual->tipoComida);

        atual = atual->proximo;
        i++;
    }
}

int main() {
    Restaurante* lista = NULL;
    int opcao;

    do {
        Restaurante* novoRestaurante = solicitarDados();

        if (lista == NULL) {
            lista = novoRestaurante;
        } else {
            Restaurante* atual = lista;
            while (atual->proximo != NULL) {
                atual = atual->proximo;
            }
            atual->proximo = novoRestaurante;
        }

        printf("\nRestaurante adicionado a lista.\n");

        printf("\n\nDeseja adicionar mais um restaurante?\n [1] SIM | [2] NAO\nOPCAO: ");
        scanf("%d", &opcao);
        fflush (stdin);

    } while (opcao == 1);

    printf ("\n\n+++++++++++++++++++++++++++++++\n");
    printf ("   RESTAURANTES CADASTRADOS\n");
    printf ("+++++++++++++++++++++++++++++++\n\n");
    listarRestaurantes(lista);

    return 0;
}
