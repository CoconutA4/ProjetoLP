#include <stdio.h>
#include <stdlib.h>
#include "empresas.h"
#include "verificacoes.h"
#include "string.h"
#include "ctype.h"

void criarEmpresa(Empresas *catalogo, Ramos *catalogoRamos) {
    if (catalogo->contador == catalogo->alocadas) {
        // Numero maximo atingido aloca mais!
        catalogo->alocadas += 10; 
        catalogo->empresas = realloc(catalogo->empresas, catalogo->alocadas * sizeof(Empresa));
    }

    Empresa novaEmpresa;

    do{
        printf("Nif da empresa: ");
        scanf("%s", novaEmpresa.nif);
        if (verificaNIF(novaEmpresa.nif)) {
        }else {
                printf("O NIF não é válido.\n");
        }
    }while(verificaNIF(novaEmpresa.nif) != 1);
    
    printf("Nome da empresa: ");
    scanf(" %[^\n]", novaEmpresa.nome);
    
    do {
        printf("Categoria da empresa(Micro, PME ou Grande empresa): ");
        scanf("%s", novaEmpresa.categoria);
    }while(strcmp(novaEmpresa.categoria, "Micro") && strcmp(novaEmpresa.categoria, "PME") && strcmp(novaEmpresa.categoria, "Grande empresa"));
    
    printf("Rua da empresa: ");
    scanf(" %[^\n]", novaEmpresa.rua);
    printf("Localidade da empresa: ");
    scanf("%s", novaEmpresa.localidade);
    printf("Codigo postal da empresa: ");
    scanf("%s", novaEmpresa.codigoPostal);

    //gatt
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
        printf("Não existem ramos de atividade disponíveis. Por favor, crie um ramo de atividade antes de criar uma empresa.\n");
        return;
    }

    novaEmpresa.estado = 1;
    
    catalogo->empresas[catalogo->contador] = novaEmpresa;
    catalogo->contador++;

    printf("Empresa criada com sucesso!\n");
}

void editarEmpresa(Empresas *catalogo, Ramos *catalogoRamos) {
    char nif[MAXG];
    printf("Intruduza o nif da empresa que pretende editar: ");
    scanf("%s", nif);

    for (int i = 0; i < catalogo->contador; i++) {
        if (strcmp(catalogo->empresas[i].nif, nif) == 0) {
            printf("Intruduza o novos detalhes da empresa:\n");

            printf("NIF: ");
            scanf("%s", catalogo->empresas[i].nif);
            printf("Nome: ");
            scanf(" %[^\n]", catalogo->empresas[i].nome);
            do {
                printf("Categoria (Micro, PME or Grande empresa): ");
                scanf("%s", catalogo->empresas[i].categoria);
            } while(strcmp(catalogo->empresas[i].categoria, "Micro") && strcmp(catalogo->empresas[i].categoria, "PME") && strcmp(catalogo->empresas[i].categoria, "Grande empresa"));
            printf("Rua: ");
            scanf(" %[^\n]", catalogo->empresas[i].rua);
            printf("Localidade: ");
            scanf("%s", catalogo->empresas[i].localidade);
            printf("Codigo postal: ");
            scanf("%s", catalogo->empresas[i].codigoPostal);
            printf("Estado: (0/1)");
            scanf("%d", catalogo->empresas[i].estado);

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
                printf("Não existem ramos de atividade disponíveis. Por favor, crie um ramo de atividade antes de editar uma empresa.\n");
                return;
            }
            printf("Empresa editada!\n");
            return;
        }
    }

    printf(NENCONTRADO);
}


void mostrarEmpresas(Empresas *catalogo) {
    printf("Empresas criadas:\n");

    for (int i = 0; i < catalogo->contador; i++) {
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

    if (catalogo->contador == 0) {
        printf("Nenhuma empresa criada.\n");
    }
}

void empresasAtivas(Empresas *catalogo) {
    for (int i = 0; i < catalogo->contador; i++) {
        if(catalogo->empresas[i].estado==1)
        printf("Empresas ativas:\n");
        printf("Empresa: %s\n", catalogo->empresas[i].nome);
        printf("\n");
    }
}

void removerEmpresa(Empresas *catalogo) {

}

void liberarMemoriaEmpresas(Empresas *catalogo) {
    for (int i = 0; i < catalogo->contador; i++) {
        free(catalogo->empresas[i].classis);
        free(catalogo->empresas[i].comment);
    }
    free(catalogo->empresas);
}