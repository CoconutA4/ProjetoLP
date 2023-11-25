#include <stdio.h>
#include <stdlib.h>
#include "empresas.h"
#include "string.h"
#include "ctype.h"

void criarEmpresa(Empresas *catalogo) {
    if (catalogo->contador == catalogo->alocadas) {
        // Numero maximo atingido aloca mais!
        catalogo->alocadas += 10; 
        catalogo->empresas = realloc(catalogo->empresas, catalogo->alocadas * sizeof(Empresa));
    }

    Empresa novaEmpresa;

    printf("Nif da empresa: ");
    scanf("%s", novaEmpresa.nif);
    printf("Nome da empresa: ");
    scanf("%s", novaEmpresa.nome);
    do {
    printf("Categoria da empresa(Micro, PME ou Grande empresa");
    scanf("%s", novaEmpresa.categoria);
    }while(strcmp(novaEmpresa.categoria, "Micro") && strcmp(novaEmpresa.categoria, "PME") && strcmp(novaEmpresa.categoria, "Grande empresa"));
    printf("Rua da empresa: ");
    scanf("%s", novaEmpresa.rua);
    printf("Localidade da empresa: ");
    scanf("%s", novaEmpresa.localidade);
    printf("Codigo postal da empresa: ");
    scanf("%s", novaEmpresa.codigoPostal);

    novaEmpresa.estado = 1;
    
    catalogo->empresas[catalogo->contador] = novaEmpresa;
    catalogo->contador++;

    printf("Empresa criada com sucesso!\n");
}

void editarEmpresas(Empresas *catalogo){
    
}

void mostrarEmpresas(Empresas *catalogo) {
    printf("Empresas criadas:\n");

    for (int i = 0; i < catalogo->contador; i++) {
        printf("Empresa %d:\n", i + 1);
        printf("Nome: %s\n", catalogo->empresas[i].nome);
        printf("Nif: %s\n", catalogo->empresas[i].nif);
        printf("Categoria: %s\n", catalogo->empresas[i].categoria);
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

void liberarMemoriaEmpresas(Empresas *catalogo) {
    for (int i = 0; i < catalogo->contador; i++) {
        free(catalogo->empresas[i].classis);
        free(catalogo->empresas[i].comment);
    }
    free(catalogo->empresas);
}