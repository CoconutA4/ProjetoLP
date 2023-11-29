#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresas.h"
#include "verificacoes.h"
#include "ctype.h"

/**
 * @brief Função para criar uma nova empresa.
 * @param catalogo Apontador para o catálogo de empresas.
 * @param catalogoRamos Apontador para o catálogo de ramos.
 */
void criarEmpresa(Empresas *catalogo, Ramos *catalogoRamos) {
    // Verifica se o número de empresas atingiu o limite atualmente alocado
    if (catalogo->contador == catalogo->alocadas) {
        // Se o limite for atingido, aloca mais espaço
        catalogo->alocadas += 10; 
        catalogo->empresas = realloc(catalogo->empresas, catalogo->alocadas * sizeof(Empresa));
    }
    

    Empresa novaEmpresa;

    // Solicita o NIF da empresa e verifica se é válido
    do{
        printf("Nif da empresa: ");
        scanf("%s", novaEmpresa.nif);
        if (!verificaNIF(novaEmpresa.nif))
        {
                printf("O NIF nao e valido.\n");
        }
    }while(!verificaNIF(novaEmpresa.nif));
    
    // Solicita o nome da empresa
    printf("Nome da empresa: ");
    scanf(" %[^\n]", novaEmpresa.nome);
    
    // Solicita a categoria da empresa e verifica se é válida
    do {
        printf("Categoria da empresa(Micro, PME ou Grande empresa): ");
        scanf("%s", novaEmpresa.categoria);
        if (!verificaCategoria(novaEmpresa.categoria))
        {
                printf("A categoria nao e valida.\n");
        }
    }while(!verificaCategoria(novaEmpresa.categoria));
    
    // Solicita a rua da empresa
    printf("Rua da empresa: ");
    scanf(" %[^\n]", novaEmpresa.rua);
    // Solicita a localidade da empresa
    printf("Localidade da empresa: ");
    scanf("%s", novaEmpresa.localidade);
    
    // Solicita o código postal da empresa e verifica se é válido
    do{
        printf("Codigo postal da empresa: ");
        scanf("%s", novaEmpresa.codigoPostal);
        if (!verificaCodigoPostal(novaEmpresa.codigoPostal)) 
        {
            printf("O NIF nao e valido.\n");
        }
    }while(!verificaCodigoPostal(novaEmpresa.codigoPostal));

    // Se existirem ramos de atividade, solicita que o usuário escolha um para a empresa
    if(catalogoRamos->contador > 0) {
        for(int i = 0; i < catalogoRamos->contador; i++) {
            printf("%d. %s\n", i+1, catalogoRamos->ramos[i].nome);
        }
        int escolha;
        do {
            printf("Escolha o ramo de atividade da empresa (1-%d): ", catalogoRamos->contador);
            scanf("%d", &escolha);
        } while(escolha < 1 || escolha > catalogoRamos->contador);
        strcpy(novaEmpresa.ramo, catalogoRamos->ramos[escolha-1].nome);
    } else {
        // Se não existirem ramos de atividade, informa o usuário e retorna
        printf("Nao existem ramos de atividade disponíveis. Por favor, crie um ramo de atividade antes de criar uma empresa.\n");
        return;
    }

    // Define o estado da empresa como ativo
    novaEmpresa.estado = 1;
    
    // Adiciona a nova empresa ao catálogo
    catalogo->empresas[catalogo->contador] = novaEmpresa;
    catalogo->contador++;

    // Informa ao usuário que a empresa foi criada com sucesso
    printf("Empresa criada com sucesso!\n");
}

/**
 * @brief Função para editar uma empresa existente.
 * @param catalogo Apontador para o catálogo de empresas.
 * @param catalogoRamos Apontador para o catálogo de ramos.
 */
void editarEmpresa(Empresas *catalogo, Ramos *catalogoRamos) {
    
    char nif[MAXG];
    // Solicita o NIF da empresa a ser editada e verifica se é válido
    do{
        printf("Intruduza o nif da empresa que pretende editar: ");
        scanf("%s",nif);
        if (!verificaNIF(nif))
        {
                printf("O NIF não é válido.\n");
        }
    }while(!verificaNIF(nif));

    // Percorre o catálogo de empresas
    for (int i = 0; i < catalogo->contador; i++) {
        // Se a empresa for encontrada, solicita os novos detalhes
        if (strcmp(catalogo->empresas[i].nif, nif) == 0) {
            printf("Intruduza o novos detalhes da empresa:\n");

            // Solicita o novo NIF e verifica se é válido
            do{
                printf("NIF: ");
                scanf("%s", catalogo->empresas[i].nif);
                if (!verificaNIF(catalogo->empresas[i].nif))
                {
                        printf("O NIF não é válido.\n");
                }
            }while(!verificaNIF(catalogo->empresas[i].nif));
            
            // Solicita o novo nome da empresa
            printf("Nome: ");
            scanf(" %[^\n]", catalogo->empresas[i].nome);
            
            // Solicita a categoria da empresa e verifica se é válida
            do {
                printf("Categoria da empresa(Micro, PME ou Grande empresa): ");
                scanf("%s", catalogo->empresas[i].categoria);
                if (!verificaCategoria(catalogo->empresas[i].categoria))
                {
                        printf("A categoria nao e valida.\n");
                }
            }while(!verificaCategoria(catalogo->empresas[i].categoria));
            
            // Solicita a nova rua da empresa
            printf("Rua: ");
            scanf(" %[^\n]", catalogo->empresas[i].rua);
            // Solicita a nova localidade da empresa
            printf("Localidade: ");
            scanf("%s", catalogo->empresas[i].localidade);
            
            // Solicita o novo código postal da empresa e verifica se é válido
            do{
                printf("Codigo postal da empresa: ");
                scanf("%s", catalogo->empresas[i].codigoPostal);
                if (!verificaCodigoPostal(catalogo->empresas[i].codigoPostal)) 
                {
                    printf("O NIF não é válido.\n");
                }
            }while(!verificaCodigoPostal(catalogo->empresas[i].codigoPostal));
            
            // Solicita o novo estado da empresa e verifica se é válido
            do {
                printf("Estado: (0/1)");
                scanf("%d", &catalogo->empresas[i].estado);
            }while(catalogo->empresas[i].estado != 1 && catalogo->empresas[i].estado != 0);

            // Se existirem ramos de atividade, solicita que o usuário escolha um para a empresa
            if(catalogoRamos->contador > 0) {
                for(int j = 0; j < catalogoRamos->contador; j++) {
                    printf("%d. %s\n", j+1, catalogoRamos->ramos[j].nome);
                }
                int escolha;
                do {
                    printf("Escolha o novo ramo de atividade da empresa (1-%d): ", catalogoRamos->contador);
                    scanf("%d", &escolha);
                } while(escolha < 1 || escolha > catalogoRamos->contador);
                strcpy(catalogo->empresas[i].ramo, catalogoRamos->ramos[escolha-1].nome);
            } else {
                // Se não existirem ramos de atividade, informa o usuário e retorna
                printf("Não existem ramos de atividade disponíveis. Por favor, crie um ramo de atividade antes de editar uma empresa.\n");
                return;
            }
            // Informa ao usuário que a empresa foi editada com sucesso
            printf("Empresa editada!\n");
            return;
        }
    }
    // Se a empresa não for encontrada, informa o usuário
    printf(NENCONTRADO);
}

/**
 * @brief Função para mostrar todas as empresas no catálogo.
 * @param catalogo Apontador para o catálogo de empresas.
 */
void mostrarEmpresas(Empresas *catalogo) {
    // Inicia a listagem das empresas
    printf("Empresas criadas:\n");

    // Percorre o catálogo de empresas
    for (int i = 0; i < catalogo->contador; i++) {
        // Mostra os detalhes de cada empresa
        printf("Empresa %d:\n", i + 1);
        printf("Nome: %s\n", catalogo->empresas[i].nome);
        printf("Nif: %s\n", catalogo->empresas[i].nif);
        printf("Categoria: %s\n", catalogo->empresas[i].categoria);
        printf("Ramo: %s\n", catalogo->empresas[i].ramo);  
        printf("Rua: %s\n", catalogo->empresas[i].rua);
        printf("Localidade: %s\n", catalogo->empresas[i].localidade);
        printf("Codigo postal: %s\n", catalogo->empresas[i].codigoPostal);
        printf("Estado: %d\n", catalogo->empresas[i].estado);
        printf("\n");
    }

    // Se não existirem empresas no catálogo, informa o usuário
    if (catalogo->contador == 0) {
        printf("Nenhuma empresa criada.\n");
    }
}

/**
 * @brief Função para mostrar todas as empresas ativas no catálogo.
 * @param catalogo Apontador para o catálogo de empresas.
 */
void empresasAtivas(Empresas *catalogo) {
    // Percorre o catálogo de empresas
    for (int i = 0; i < catalogo->contador; i++) {
        // Se a empresa estiver ativa, mostra o nome da empresa
        if(catalogo->empresas[i].estado==1) {
            printf("Empresas ativas:\n");
            printf("Empresa: %s\n", catalogo->empresas[i].nome);
            printf("\n");
        }
    }
}

void removerEmpresa(Empresas *catalogo) {

}

/**
 * @brief Função para liberar a memória alocada para as empresas no catálogo.
 * @param catalogo Apontador para o catálogo de empresas.
 */
void liberarMemoriaEmpresas(Empresas *catalogo) {
    // Percorre o catálogo de empresas
    for (int i = 0; i < catalogo->contador; i++) {
        // Libera a memória alocada para os campos 'classis' e 'comment' de cada empresa
        free(catalogo->empresas[i].classis);
        free(catalogo->empresas[i].comment);
    }
    // Libera a memória alocada para o array de empresas
    free(catalogo->empresas);
}


