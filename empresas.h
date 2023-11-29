#ifndef EMPRESAS_H
#define EMPRESAS_H

#include "ramos.h"
#include "classificacoes.h"

#define NENCONTRADO "Nao foi encontrada empresa com esse NIF\n"

#define MAXG 50
#define MAXBIG 200

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char nome[MAXG];
    char email[MAXG];
    char titulo[MAXG];
    char texto[MAXBIG];
}Comentario;
    
typedef struct {
    char nif[MAXG];
    char nome[MAXG];
    char categoria[MAXG];
    char ramo[MAXG];
    char rua[MAXBIG];
    char localidade[MAXG];
    char codigoPostal[MAXG];
    int estado;
    int nClassificacoes;
    Classificacao *classis;
    int nComentarios;
    Comentario *comment;
}Empresa;    
    
typedef struct {
    int contador;
    int alocadas;
    Empresa *empresas;
}Empresas;
    
void criarEmpresa(Empresas *catalogo, Ramos *catalogoRamos);
void mostrarEmpresas(Empresas *catalogo);
void liberarMemoriaEmpresas(Empresas *catalogo);
void empresasAtivas(Empresas *catalogo);
void editarEmpresa(Empresas *catalogo, Ramos *catalogoRamos);
void removerEmpresa(Empresas *catalogo);
void classificarEmpresa(Empresas *catalogo);

#ifdef __cplusplus
}
#endif

#endif /* EMPRESAS_H */

