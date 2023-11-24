#ifndef EMPRESAS_H
#define EMPRESAS_H

#define MAXG 50
#define MAXBIG 200

#ifdef __cplusplus
extern "C" {
#endif
    
    
    typedef struct {
        int contador;
        int alocadas;
        Empresa *empresas;
    } Empresas;
    
    typedef struct {
        int avaliacao;
        char nome[MAXG];
        char email [MAXG];
    } Classificacao;
    
    typedef struct {
        char nome[MAXG];
        char email[MAXG];
        char titulo[MAXG];
        char texto[MAXBIG];
    } Comentario;


    typedef struct {
        char nif[MAXG];
        char nome[MAXG];
        char categoria[MAXG];
        char ramo[MAXG];
        char rua[MAXBIG];
        char localidade[MAXG];
        int codigoPostal;
        int estado;
        int nClassificacoes;
        Classificacao *classis;
        int nComentarios;
        Comentario *comment;
    } Empresa;


#ifdef __cplusplus
}
#endif

#endif /* EMPRESAS_H */

