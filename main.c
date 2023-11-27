#include <stdio.h>
#include <stdlib.h>
#include "empresas.h"
#include "ramos.h"
#include "pesquisas.h"

#define VOLTARMENU "4 - Voltar ao menu anterior\n"
#define SAIR "5 - Sair\n"

int main() {
    
    Empresas Empresa = {.contador = 0};
    Ramos Ramo = {.contador = 0};
    Pesquisas Pesquisa = {.contador = 0};
    
    int opc, opc1, opc2;
    do {
        printf("1-Administrador\n");
        printf("2-User\n");
        printf("3-Sair\n");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
                do {
                    printf("1- Gerir o Catálogo de Empresas \n");
                    printf("2- Gerir ramos de empresa \n");
                    printf("3- Visualizar relatorios \n");
                    printf(VOLTARMENU);
                    printf(SAIR);
                    scanf("%d", &opc1);
                } while (opc1 < 0 || opc1 > 5);
                switch (opc1) {
                    case 1:
                        do {
                            printf("1- Criar empresa\n");
                            printf("2- Editar empresa\n");
                            printf("3- Remover empresa\n");
                            printf(VOLTARMENU);
                            printf(SAIR);
                            scanf("%d", &opc2);
                        } while (opc2 < 0 || opc2 > 5);
                        switch (opc2) {
                            case 1:
                                criarEmpresa(&Empresa, &Ramo);
                                break;
                            case 2:
                                editarEmpresa(&Empresa, &Ramo);
                                break;
                            case 3:
                                removerEmpresa(&Empresa);
                                break;
                            case 4: 
                                break;
                            case 5: 
                                opc = 4;
                                break;
                        }
                        break;
                    case 2:
                        do {
                            printf("1- Criar ramos\n");
                            printf("2- Editar ramos\n");
                            printf("3- Remover ramos \n");
                            printf(VOLTARMENU);
                            printf(SAIR);
                            scanf("%d", &opc2);
                        } while (opc2 < 0 || opc2 > 5);
                        switch (opc2) {
                            case 1:
                                criarRamo(&Ramo);
                                break;
                            case 2:
                                editarRamo(&Ramo);
                                break;
                            case 3:
                                removerRamo(&Ramo, &Empresa);
                                break;
                            case 4: 
                                break;
                            case 5: 
                                opc = 4;
                                break;
                        }
                        break;
                    case 3:
                        do {
                            printf("1- Listar empresas\n");
                            printf("2- Empresas ativas\n");
                            printf("3- Listar ramos\n");
                            printf("4- Ramos ativos\n");
                            printf("5- Voltar ao menu anterior\n");
                            printf("6- Sair!");
                            scanf("%d", &opc2);
                        } while (opc2 < 0 || opc2 > 6);
                        switch (opc2) {
                            case 1:
                                mostrarEmpresas(&Empresa);
                                break;
                            case 2:
                                empresasAtivas(&Empresa);
                                break;
                            case 3:
                                mostrarRamos(&Ramo);
                                break;
                            case 4:
                                ramosAtivos(&Ramo);
                                break;
                            case 5: 
                                break;
                            case 6: 
                                opc = 4;
                                break;
                        }
                        break;
                    case 4:
                        break;
                    case 5: 
                        opc = 4;
                        break;
                }
                break;
            case 2:
                do {
                    printf("1- Pesquisar empresa \n");
                    printf("2- Classificar empresa \n");
                    printf("3- Comentar relatorios \n");
                    printf(VOLTARMENU);
                    printf(SAIR);
                    scanf("%d", &opc1);
                } while (opc1 < 0 || opc1 > 5);
                switch (opc1) {
                    case 1:
                        procurarEmpresa(&Empresa, &Pesquisa);
                        break;
                    case 2:
                        classificarEmpresa(&Empresa);
                        break;
                    case 3: //comentar relatiorios
                        break;
                    case 4:
                        break;
                    case 5: 
                        opc = 4;
                        break;
                }
                break;
            case 3:
                opc = 4;
                break;
        }
    } while (opc != 4);
    
    liberarMemoriaEmpresas(&Empresa);
    liberarMemoriaRamos(&Ramo);
    liberarMemoriaPesquisas(&Pesquisa);
}
