#include <stdio.h>
#include <stdlib.h>

typedef struct dieta {
    char comida[50];
    float pesoPorcao;
    int calorias;
    struct dieta* proximo;
} Dieta;


Dieta* solicitarDados() {
    Dieta* novaDieta = (Dieta*)malloc(sizeof(Dieta));

    printf("Digite o nome da comida: ");
    scanf ("%[^\n]s", novaDieta->comida);

    printf("Digite o peso da porcao (em gramas): ");
    scanf("%f", &novaDieta->pesoPorcao);
    fflush (stdin);

    printf("Digite o numero de calorias: ");
    scanf("%d", &novaDieta->calorias);
    fflush (stdin);

    novaDieta->proximo = NULL;

    return novaDieta;
}

//função que lista todas as dietas
void listarDietas(Dieta* lista) {
    if (lista == NULL) {
        printf("A lista de dietas esta vazia.\n");
        return;
    }

    Dieta* atual = lista;
    int i = 1;

    printf("-----Lista de Dietas:-----\n\n");

    while (atual != NULL) {
        printf("* Dieta %d:\n", i);
        printf("* Comida: %s", atual->comida);
        printf("\n* Peso da Porcao: %.2f g\n", atual->pesoPorcao);
        printf("* Calorias: %d\n\n", atual->calorias);

        atual = atual->proximo;
        i++;
    }
}

int main() {
    Dieta* lista = NULL;
    int opcao;

    do {
        
        Dieta* novaDieta = solicitarDados();

        if (lista == NULL) {
            lista = novaDieta;
        } else {
            Dieta* atual = lista;
            while (atual->proximo != NULL) {
                atual = atual->proximo;
            }
            atual->proximo = novaDieta;
        }

        printf("Dieta adicionada a lista.\n");

        printf("Deseja adicionar mais uma dieta?\n[1] SIM | [2] NAO\nOPCAO: ");
        scanf(" %d", &opcao);
        fflush (stdin);

    } while (opcao == 1);

    printf (" ____________________________");
    printf ("\n|______DIETAS ADICIONADAS____|\n\n");
    listarDietas(lista);

    return 0;
}
