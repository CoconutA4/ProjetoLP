#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresas.h"
#include "ramos.h"
#include "pesquisas.h"

#define VOLTARMENU "4 - Voltar ao menu anterior\n"
#define SAIR "5 - Sair\n"

/**
 * @brief Função principal do programa.
 */
int main() {
    
    // Inicializa o catálogo de empresas
    Empresas Empresa = {.contador = 0};
    // Inicializa o catálogo de ramos
    Ramos Ramo = {.contador = 0};
    // Inicializa o catálogo de pesquisas
    Pesquisas Pesquisa = {.contador = 0};
    
    int opc, opc1, opc2;
    do {
        // Mostra o menu principal
        printf("1-Administrador\n");
        printf("2-User\n");
        printf("3-Sair\n");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
                do {
                    // Solicita a senha do administrador
                    char password[20];
                    char adminPassword[] = "0404";
                    printf("Enter password: ");
                    scanf("%s", password);
                    if (strcmp(password, adminPassword) != 0) {
                        printf("Incorrect password!\n");
                        break;
                    }
                    // Mostra o menu do administrador
                    printf("1- Gerir o Catalogo de Empresas \n");
                    printf("2- Gerir ramos de empresa \n");
                    printf("3- Visualizar relatorios \n");
                    printf(VOLTARMENU);
                    printf(SAIR);
                    scanf("%d", &opc1);
                } while (opc1 < 0 || opc1 > 5);
                switch (opc1) {
                    case 1:
                        do {
                            // Mostra o menu de gestão de empresas
                            printf("1- Criar empresa\n");
                            printf("2- Editar empresa\n");
                            printf("3- Remover empresa\n");
                            printf(VOLTARMENU);
                            printf(SAIR);
                            scanf("%d", &opc2);
                        } while (opc2 < 0 || opc2 > 5);
                        switch (opc2) {
                            case 1:
                                // Cria uma nova empresa
                                criarEmpresa(&Empresa, &Ramo);
                                break;
                            case 2:
                                // Edita uma empresa existente
                                editarEmpresa(&Empresa, &Ramo);
                                break;
                            case 3:
                                // Remove uma empresa
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
                            // Mostra o menu de gestão de ramos
                            printf("1- Criar ramos\n");
                            printf("2- Editar ramos\n");
                            printf("3- Remover ramos \n");
                            printf(VOLTARMENU);
                            printf(SAIR);
                            scanf("%d", &opc2);
                        } while (opc2 < 0 || opc2 > 5);
                        switch (opc2) {
                            case 1:
                                // Cria um novo ramo
                                criarRamo(&Ramo);
                                break;
                            case 2:
                                // Edita um ramo existente
                                editarRamo(&Ramo);
                                break;
                            case 3:
                                // Remove um ramo
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
                            // Mostra o menu de relatórios
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
                                // Lista as empresas
                                mostrarEmpresas(&Empresa);
                                break;
                            case 2:
                                // Mostra as empresas ativas
                                empresasAtivas(&Empresa);
                                break;
                            case 3:
                                // Lista os ramos
                                mostrarRamos(&Ramo);
                                break;
                            case 4:
                                // Mostra os ramos ativos
                                ramosAtivos(&Ramo);
                                break;
                            case 5: 
                                break;
                            case 6: 
                                // Sai do programa
                                opc = 4;
                                break;
                        }
                        break;
                    case 4:
                        break;
                    case 5: 
                        // Sai do programa
                        opc = 4;
                        break;
                }
                break;
            case 2:
                do {
                    // Mostra o menu do utilizador
                    printf("1- Pesquisar empresa \n");
                    printf("2- Classificar empresa \n");
                    printf("3- Comentar relatorios \n");
                    printf(VOLTARMENU);
                    printf(SAIR);
                    scanf("%d", &opc1);
                } while (opc1 < 0 || opc1 > 5);
                switch (opc1) {
                    case 1:
                        // Procura uma empresa
                        procurarEmpresa(&Empresa, &Pesquisa);
                        break;
                    case 2:
                        // Classifica uma empresa
                        break;
                    case 3:
                        // Comenta sobre relatórios
                        break;
                    case 4:
                        break;
                    case 5: 
                        // Sai do programa
                        opc = 4;
                        break;
                }
                break;
            case 3:
                // Sai do programa
                opc = 4;
                break;
        }
    } while (opc != 4);

    // Libera a memória alocada para as empresas, ramos e pesquisas
    liberarMemoriaEmpresas(&Empresa);
    liberarMemoriaRamos(&Ramo);
    liberarMemoriaPesquisas(&Pesquisa);
}

