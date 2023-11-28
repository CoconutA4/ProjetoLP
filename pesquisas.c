#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pesquisas.h"
#include "empresas.h"
#include "ctype.h"

/**
 * @brief Função para procurar uma empresa no catálogo.
 * @param catalogo Apontador para o catálogo de empresas.
 * @param pesquisas Apontador para o catálogo de pesquisas.
 */
void procurarEmpresa(Empresas *catalogo, Pesquisas *pesquisas) {
    // Verifica se o número de pesquisas atingiu o limite atualmente alocado
    if (pesquisas->contador == pesquisas->alocadas) {
        // Se o limite for atingido, aloca mais espaço
        pesquisas->alocadas += 10; 
        pesquisas->pesquisas = realloc(pesquisas->pesquisas, pesquisas->alocadas * sizeof(Pesquisa));
    }

    Pesquisa novaPesquisa;
    
    // Solicita o campo de pesquisa e verifica se é válido
    do {
        printf("Campo de pesquisa (nome, categoria, localidade): ");
        scanf("%s", novaPesquisa.campo);
    }while(strcmp(novaPesquisa.campo, "nome") && strcmp(novaPesquisa.campo, "categoria") && strcmp(novaPesquisa.campo, "localidade"));
    
    // Solicita a palavra-chave da pesquisa
    printf("Palavra-chave: ");
    scanf("%s", novaPesquisa.palavraChave);

    int encontrou = 0;
    // Percorre o catálogo de empresas
    for(int i = 0; i < catalogo->contador; i++) {
        // Se a empresa for encontrada, informa o usuário
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
    
    // Informa ao usuário se a empresa foi encontrada ou não
    if(encontrou) {
        printf("Empresa existe!\n");
    } else {
        printf("Empresa não encontrada.\n");
    }

    // Adiciona a nova pesquisa ao catálogo
    pesquisas->pesquisas[pesquisas->contador] = novaPesquisa;
    pesquisas->contador++;

    // Informa ao usuário que a pesquisa foi registada
    printf("Pesquisa registada!\n");
}


/**
 * @brief Função para liberar a memória alocada para as pesquisas no catálogo.
 * @param catalogo Apontador para o catálogo de pesquisas.
 */
void liberarMemoriaPesquisas(Pesquisas *catalogo) {
    // Libera a memória alocada para o array de pesquisas
    free(catalogo->pesquisas);
}
