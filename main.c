#include <stdio.h>
#include <stdlib.h>

#define VOLTARMENU "4 - Voltar ao menu anterior\n"
#define SAIR "5 - Sair\n"

int main() {

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
                            case 1: //criar
                                break;
                            case 2: //editar
                                break;
                            case 3: //remover
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
                            case 1: //criar
                                break;
                            case 2: //editar
                                break;
                            case 3: //remover
                                break;
                            case 4: 
                                break;
                            case 5: 
                                opc = 4;
                                break;
                        }
                        break;
                    case 3:
                        puts("Relatorios");
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
                    case 1: //pesquisar empresa
                        break;
                    case 2: //classificar empresa
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
}
