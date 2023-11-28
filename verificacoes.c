#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Função para verificar se um NIF (Número de Identificação Fiscal) é válido.
 * @param nif Apontador para o NIF a ser verificado.
 * @return Retorna 1 se o NIF for válido e 0 caso contrário.
 */
int verificaNIF(char *nif) {
    int i, soma = 0;
    // Converte o primeiro dígito do NIF de char para int
    int primeiroDigito = nif[0] - '0';

    // Verifica se o primeiro dígito é válido (1, 2, 5, 6, 8 ou 9)
    if (primeiroDigito != 1 && primeiroDigito != 2 && primeiroDigito != 5 && primeiroDigito != 6 && primeiroDigito != 8 && primeiroDigito != 9) {
        return 0;
    }

    // Verifica se o NIF tem 9 dígitos
    if (strlen(nif) != 9) {
        return 0;
    }
    
    // Se todas as condições forem cumpridas, retorna 1
    return 1;
}


/**
 * @brief Função para verificar se uma categoria de empresa é válida.
 * @param categoria Apontador para a categoria a ser verificada.
 * @return Retorna 1 se a categoria for válida e 0 caso contrário.
 */
int verificaCategoria(char *categoria) {
    // Verifica se a categoria é válida ("Micro", "PME" ou "Grande empresa")
    if (strcmp(categoria, "Micro") != 0 && strcmp(categoria, "PME") != 0 && strcmp(categoria, "Grande empresa") != 0) {
        return 0;
    }
    
    // Se a categoria for válida, retorna 1
    return 1;
}


/**
 * @brief Função para verificar se um código postal é válido.
 * @param codigoPostal Apontador para o código postal a ser verificado.
 * @return Retorna 1 se o código postal for válido e 0 caso contrário.
 */
int verificaCodigoPostal(char *codigoPostal) {
    // Verifica se o código postal tem 8 caracteres
    if (strlen(codigoPostal) != 8) {
        return 0;
    }

    // Verifica se o quinto caracter é um '-'
    if (codigoPostal[4] != '-') {
        return 0;
    }

    // Verifica se os outros caracteres são dígitos
    for (int i = 0; i < 8; i++) {
        if (i == 4) continue; // Ignora o '-'
        if (codigoPostal[i] < '0' || codigoPostal[i] > '9') {
            return 0;
        }
    }

    // Se todas as condições forem cumpridas, retorna 1
    return 1;
}
