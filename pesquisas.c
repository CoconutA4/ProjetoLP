#include <stdio.h>
#include <stdlib.h>
#include "pesquisas.h"
#include "empresas.h"
#include "string.h"
#include "ctype.h"

void procurarEmpresa(Empresas *catalogo, Pesquisas *pesquisas) {
    if (pesquisas->contador == pesquisas->alocadas) {
        // Numero maximo atingido aloca mais!
        pesquisas->alocadas += 10; 
        pesquisas->pesquisas = realloc(pesquisas->pesquisas, pesquisas->alocadas * sizeof(Pesquisa));
    }

    Pesquisa novaPesquisa;
    
    do {
        printf("Campo de pesquisa (nome, categoria, localidade): ");
        scanf("%s", novaPesquisa.campo);
    }while(strcmp(novaPesquisa.campo, "nome") && strcmp(novaPesquisa.campo, "categoria") && strcmp(novaPesquisa.campo, "localidade"));
    
    printf("Palavra-chave: ");
    scanf("%s", novaPesquisa.palavraChave);

    int encontrou = 0;
    for(int i = 0; i < catalogo->contador; i++) {
        if(strcmp(novaPesquisa.campo, "nome") == 0 && strcmp(catalogo->empresas[i].nome, novaPesquisa.palavraChave) == 0) {
            encontrou = 1;
            break;
        } else if(strcmp(novaPesquisa.campo, "categoria") == 0 && strcmp(catalogo->empresas[i].categoria, novaPesquisa.palavraChave) == 0) {
            encontrou = 1;
            break;
        } else if(strcmp(novaPesquisa.campo, "localidade") == 0 && strcmp(catalogo->empresas[i].localidade, novaPesquisa.palavraChave) == 0) {
            encontrou = 1;
            break;
        }
    }

    if(encontrou) {
        printf("Empresa existe!\n");
    } else {
        printf("Empresa não encontrada.\n");
    }

    pesquisas->pesquisas[pesquisas->contador] = novaPesquisa;
    pesquisas->contador++;

    printf("Pesquisa registada!\n");
}

void liberarMemoriaPesquisas(Pesquisas *catalogo) {
    free(catalogo->pesquisas);
}