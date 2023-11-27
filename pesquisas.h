#ifndef PESQUISAS_H
#define PESQUISAS_H

#define MAXG 50
#define MAXBIG 200

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char campo[MAXG];
    char palavraChave[MAXG];
}Pesquisa;
    

typedef struct {
    int contador;
    int alocadas;
    Pesquisa *pesquisas;
}Pesquisas;

void liberarMemoriaPesquisas(Pesquisas *catalogo);

#ifdef __cplusplus
}
#endif

#endif /* PESQUISAS_H */

