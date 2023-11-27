#include <stdio.h>
#include <stdlib.h>
#include "ramos.h"
#include "empresas.h"
#include "string.h"
#include "ctype.h"

void criarRamo(Ramos *catalogo) {
    if (catalogo->contador == catalogo->alocadas) {
        // Numero maximo atingido aloca mais!
        catalogo->alocadas += 10; 
        catalogo->ramos = realloc(catalogo->ramos, catalogo->alocadas * sizeof(Ramo));
    }

    Ramo novoRamo;

    printf("Codigo da atividade: ");
    scanf("%s", novoRamo.codigoAtividade);
    printf("Nome do ramo de atividade: ");
    scanf("%s", novoRamo.nome);

    novoRamo.estado = 1;
    
    catalogo->ramos[catalogo->contador] = novoRamo;
    catalogo->contador++;

    printf("Ramo criado com sucesso!\n");
}

void mostrarRamos(Ramos *catalogo) {
    printf("Ramos criados:\n");

    for (int i = 0; i < catalogo->contador; i++) {
        printf("Ramo %d:\n", i + 1);
        printf("Codigo: %s\n", catalogo->ramos[i].codigoAtividade);
        printf("Nome: %s\n", catalogo->ramos[i].nome);
        printf("Estado: %d\n", catalogo->ramos[i].estado);
        printf("\n");
    }

    if (catalogo->contador == 0) {
        printf("Nenhum ramo criado.\n");
    }
}

void editarRamo(Ramos *catalogo){
    char codigo[MAXG];
    printf("Intruduza o codigo do ramo que pretende editar: ");
    scanf("%s", codigo);

    for (int i = 0; i < catalogo->contador; i++) {
        if (strcmp(catalogo->ramos[i].codigoAtividade, codigo) == 0) {
            printf("Intruduza o novos detalhes do ramo:\n");
            printf("Codigo: ");
            scanf("%s", catalogo->ramos[i].codigoAtividade);
            printf("Nome: ");
            scanf("%s", catalogo->ramos[i].nome);
            printf("Esrado: (0/1): ");
            scanf("%d", catalogo->ramos[i].estado);
            printf("Ramo editado!\n");
            return;
        }
    }

    printf(NENCONTRADOCOD);
}

void ramosAtivos(Ramos *catalogo) {
    for (int i = 0; i < catalogo->contador; i++) {
        if(catalogo->ramos[i].estado==1)
        printf("Ramos ativas:\n");
        printf("Ramo: %s\n", catalogo->ramos[i].nome);
        printf("\n");
    }
}

void removerRamo(Ramos *catalogo, Empresas *catalogoEmpresas) {
    char codigoAtividade[MAXG];
    printf("Introduza o código da atividade do ramo que pretende remover: ");
    scanf("%s", codigoAtividade);

    for (int i = 0; i < catalogo->contador; i++) {
        if (strcmp(catalogo->ramos[i].codigoAtividade, codigoAtividade) == 0) {
            // Verificar se o ramo está sendo usado por alguma empresa
            for (int j = 0; j < catalogoEmpresas->contador; j++) {
                if (strcmp(catalogoEmpresas->empresas[j].ramo, catalogo->ramos[i].nome) == 0) {
                    printf("O ramo está a ser usado por uma empresa. Estado inativo.\n");
                    catalogo->ramos[i].estado = 0;
                    return;
                }
            }

            for (int j = i; j < catalogo->contador - 1; j++) {
                catalogo->ramos[j] = catalogo->ramos[j + 1];
            }
            catalogo->contador--;
            printf("Ramo removido com sucesso!\n");
            return;
        }
    }

    printf("Ramo não encontrado.\n");
}


void liberarMemoriaRamos(Ramos *catalogo) {
    free(catalogo->ramos);
}