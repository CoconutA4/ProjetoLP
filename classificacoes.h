#ifndef CLASSIFICACOES_H
#define CLASSIFICACOES_H

#define MAXG 50
#define MAXBIG 200

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int avaliacao;
    char nome[MAXG];
    char email [MAXG];
}Classificacao;


#ifdef __cplusplus
}
#endif

#endif /* CLASSIFICACOES_H */

