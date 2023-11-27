#ifndef RAMOS_H
#define RAMOS_H

#define MAXG 50
#define MAXBIG 200
#define NENCONTRADOCOD "Nao foi encontrado nehum ramo com esse codigo\n"

#ifdef __cplusplus
extern "C" {
#endif
    
typedef struct {
    char codigoAtividade[MAXG];
    char nome[MAXG];
    int estado;
}Ramo;
    

typedef struct {
    int contador;
    int alocadas;
    Ramo *ramos;
}Ramos;
    
void criarRamo(Ramos *catalogo);
void mostrarRamos(Ramos *catalogo);
void editarRamo(Ramos *catalogo);
void liberarMemoriaRamos(Ramos *catalogo);
void ramosAtivos(Ramos *catalogo);

#ifdef __cplusplus
}
#endif

#endif /* RAMOS_H */

