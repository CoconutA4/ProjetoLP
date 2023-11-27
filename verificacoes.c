#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int verificaNIF(char *nif) {
    int i, soma = 0;
    int primeiroDigito = nif[0] - '0';

    if (primeiroDigito != 1 && primeiroDigito != 2 && primeiroDigito != 5 && primeiroDigito != 6 && primeiroDigito != 8 && primeiroDigito != 9) {
        return 0;
    }

    // Verifica se o NIF tem 9 dígitos
    if (strlen(nif) != 9) {
        return 0;
    }
    
    return 1;
}