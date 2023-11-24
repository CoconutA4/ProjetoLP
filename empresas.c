#include <stdio.h>
#include <stdlib.h>
#include "empresas.h"


void criarEmpresa(Empresas *catalogo) {
    if (catalogo->contador == catalogo->alocadas) {
        // Numero maximo atingido aloca mais!
        catalogo->alocadas += 10; 
        catalogo->empresas = realloc(catalogo->empresas, catalogo->alocadas * sizeof(Empresa));
    }

    Empresa novaEmpresa;

    printf("Nome da empresa: ");
    scanf("%s", novaEmpresa.nome);
    

    catalogo->empresas[catalogo->contador] = novaEmpresa;
    catalogo->contador++;

    printf("Empresa criada com sucesso!\n");
}

void mostrarEmpresas(Empresas *catalogo) {
    printf("Empresas cadastradas:\n");

    for (int i = 0; i < catalogo->contador; i++) {
        printf("Empresa %d:\n", i + 1);
        printf("Nome: %s\n", catalogo->empresas[i].nome);
        printf("\n");
    }

    if (catalogo->contador == 0) {
        printf("Nenhuma empresa cadastrada.\n");
    }
}

void liberarMemoriaEmpresas(Empresas *catalogo) {
    for (int i = 0; i < catalogo->contador; i++) {
        free(catalogo->empresas[i].classis);
        free(catalogo->empresas[i].comment);
    }
    free(catalogo->empresas);
}