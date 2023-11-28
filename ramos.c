#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ramos.h"
#include "empresas.h"
#include "ctype.h"

/**
 * @brief Função para criar um novo ramo de atividade.
 * @param catalogo Apontador para o catálogo de ramos.
 */
void criarRamo(Ramos *catalogo) {
    // Verifica se o número de ramos atingiu o limite atualmente alocado
    if (catalogo->contador == catalogo->alocadas) {
        // Se o limite for atingido, aloca mais espaço
        catalogo->alocadas += 10; 
        catalogo->ramos = realloc(catalogo->ramos, catalogo->alocadas * sizeof(Ramo));
    }

    Ramo novoRamo;

    // Solicita o código da atividade
    printf("Codigo da atividade: ");
    scanf("%s", novoRamo.codigoAtividade);
    // Solicita o nome do ramo de atividade
    printf("Nome do ramo de atividade: ");
    scanf(" %[^\n]", novoRamo.nome);

    // Define o estado do ramo como ativo
    novoRamo.estado = 1;
    
    // Adiciona o novo ramo ao catálogo
    catalogo->ramos[catalogo->contador] = novoRamo;
    catalogo->contador++;

    // Informa ao usuário que o ramo foi criado com sucesso
    printf("Ramo criado com sucesso!\n");
}


/**
 * @brief Função para mostrar todos os ramos no catálogo.
 * @param catalogo Apontador para o catálogo de ramos.
 */
void mostrarRamos(Ramos *catalogo) {
    // Inicia a listagem dos ramos
    printf("Ramos criados:\n");

    // Percorre o catálogo de ramos
    for (int i = 0; i < catalogo->contador; i++) {
        // Mostra os detalhes de cada ramo
        printf("Ramo %d:\n", i + 1);
        printf("Codigo: %s\n", catalogo->ramos[i].codigoAtividade);
        printf("Nome: %s\n", catalogo->ramos[i].nome);
        printf("Estado: %d\n", catalogo->ramos[i].estado);
        printf("\n");
    }

    // Se não existirem ramos no catálogo, informa o usuário
    if (catalogo->contador == 0) {
        printf("Nenhum ramo criado.\n");
    }
}


/**
 * @brief Função para editar um ramo de atividade existente.
 * @param catalogo Apontador para o catálogo de ramos.
 */
void editarRamo(Ramos *catalogo){
    char codigo[MAXG];
    // Solicita o código do ramo a ser editado
    printf("Intruduza o codigo do ramo que pretende editar: ");
    scanf("%s", codigo);

    // Percorre o catálogo de ramos
    for (int i = 0; i < catalogo->contador; i++) {
        // Se o ramo for encontrado, solicita os novos detalhes
        if (strcmp(catalogo->ramos[i].codigoAtividade, codigo) == 0) {
            printf("Intruduza o novos detalhes do ramo:\n");
            printf("Codigo: ");
            scanf("%s", catalogo->ramos[i].codigoAtividade);
            printf("Nome: ");
            scanf(" %[^\n]", catalogo->ramos[i].nome);
            printf("Esrado: (0/1): ");
            scanf("%d", catalogo->ramos[i].estado);
            // Informa ao usuário que o ramo foi editado com sucesso
            printf("Ramo editado!\n");
            return;
        }
    }

    // Se o ramo não for encontrado, informa o usuário
    printf(NENCONTRADOCOD);
}


/**
 * @brief Função para mostrar todos os ramos ativos no catálogo.
 * @param catalogo Apontador para o catálogo de ramos.
 */
void ramosAtivos(Ramos *catalogo) {
    // Percorre o catálogo de ramos
    for (int i = 0; i < catalogo->contador; i++) {
        // Se o ramo estiver ativo, mostra o nome do ramo
        if(catalogo->ramos[i].estado==1) {
            printf("Ramos ativas:\n");
            printf("Ramo: %s\n", catalogo->ramos[i].nome);
            printf("\n");
        }
    }
}


/**
 * @brief Função para remover um ramo de atividade do catálogo.
 * @param catalogo Apontador para o catálogo de ramos.
 * @param catalogoEmpresas Apontador para o catálogo de empresas.
 */
void removerRamo(Ramos *catalogo, Empresas *catalogoEmpresas) {
    char codigoAtividade[MAXG];
    // Solicita o código da atividade do ramo a ser removido
    printf("Introduza o código da atividade do ramo que pretende remover: ");
    scanf("%s", codigoAtividade);

    // Percorre o catálogo de ramos
    for (int i = 0; i < catalogo->contador; i++) {
        // Se o ramo for encontrado
        if (strcmp(catalogo->ramos[i].codigoAtividade, codigoAtividade) == 0) {
            // Verifica se o ramo está sendo usado por alguma empresa
            for (int j = 0; j < catalogoEmpresas->contador; j++) {
                // Se o ramo estiver sendo usado, define o estado como inativo e retorna
                if (strcmp(catalogoEmpresas->empresas[j].ramo, catalogo->ramos[i].nome) == 0) {
                    printf("O ramo está a ser usado por uma empresa. Estado inativo.\n");
                    catalogo->ramos[i].estado = 0;
                    return;
                }
            }

            // Se o ramo não estiver sendo usado, remove o ramo do catálogo
            for (int j = i; j < catalogo->contador - 1; j++) {
                catalogo->ramos[j] = catalogo->ramos[j + 1];
            }
            catalogo->contador--;
            // Informa ao usuário que o ramo foi removido com sucesso
            printf("Ramo removido com sucesso!\n");
            return;
        }
    }

    // Se o ramo não for encontrado, informa o usuário
    printf("Ramo não encontrado.\n");
}

/**
 * @brief Função para liberar a memória alocada para os ramos no catálogo.
 * @param catalogo Apontador para o catálogo de ramos.
 */
void liberarMemoriaRamos(Ramos *catalogo) {
    // Libera a memória alocada para o array de ramos
    free(catalogo->ramos);
}


