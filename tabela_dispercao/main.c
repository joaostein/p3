#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
    long mat;
    char nome[80];
    char email[40];
} Aluno;

typedef struct No {
    Aluno dados;
    struct No *prox;
} No;

int hash (int mat) {
    return (mat % 100);
}

No *criar_lista () {
    return NULL;
}

No *inserir_lista (No *l, Aluno a) {
    No *no = malloc(sizeof(No));
    no->dados = a;
    no->prox = l;
    l = no;
    return l;
}

No *consultar_lista (No *lista, long m) {
    No *no;
    for (no = lista; no != NULL; no = no->prox) {
        if (no->dados.mat == m) {
            return no;
        }
    }
    return NULL;
}

void inserir (No **t, Aluno a) {
    int h = hash(a.mat);
    No *no;
    no = consultar_lista(t[h], a.mat);
    if (no == NULL) {
        t[h] = inserir_lista(t[h], a);
    } else {
        printf("\n\nMatricula ja cadastradada!!");
    }
}

No *alterar_lista (No *lista, long m) {
    No *no;
    char nome[80], email[40];
    for(no = lista; no != NULL; no = no->prox) {
        if (no->dados.mat == m) {
            printf("\nInforme o novo nome: ");
            fgets(nome, 80, stdin);
            strcpy(no->dados.nome, nome);
            printf("\nInforme o novo email: ");
            fgets(email, 40, stdin);
            strcpy(no->dados.email, email);
            return no;
        }
    }
    return NULL;
}

void alterar (No **t, Aluno a) {
    int h = hash(a.mat);
    No *no;
    no = alterar_lista(t[h], a.mat);
    if (no == NULL) {
        printf("Nao encontrado");
    }
}

void consultar (No **t, long m) {
    int h = hash(m);
    No *no;
    no = consultar_lista(t[h], m);
    if (no == NULL) {
        printf("\nElemento nao encontrado!");
    } else {
        printf("\nMatricula: %i", no->dados.mat);
        printf("\nNome: %s", no->dados.nome);
        printf("\nEmail: %s", no->dados.email);
    }
}

void remover (No **t, long m) {
    int h = hash(m);
    No *ant = NULL;
    No *no = t[h];
    
    while(no != NULL) {
        
        if(no->dados.mat == m) {
            
            if (ant == NULL) {
                t[h] = no->prox;
            } else {
                ant->prox = no->prox;
            }
            
            free(no);
        }

        ant = no;
        no = no->prox;
    }
}

int lerinteiro () {
    char entrada[10];
    fgets(entrada,10,stdin);
    return atoi(entrada);
}

int lerstring () {
    char string[80];
    fgets(string, 80, stdin);
    return string;
}

int main () {
    No *tab[101];
    Aluno entrada;
    int i = 0, opcao = 0;
    long matricula = 0;
    
    for (i = 0; i < 101; i++) {
        tab[i] = criar_lista();
    }

    while (opcao != 99) {

        printf(" ### CADASTRO DE ALUNOS - TABELA DE DISPERSAO ###\n\n");
        printf("\nDigite uma das opcoes abaixo:");
        printf("\n01 - Inserir");
        printf("\n02 - Consulta");
        printf("\n03 - Remover");
        printf("\n04 - Alterar");
        printf("\n05 - Pesquisar Elemento");
        printf("\n06 - Pesquisar o Menor Elemento");
        printf("\n07 - Remover elemento");
        printf("\n99 - SAIR\n");
        printf("\nOpcao: ");
        opcao = lerinteiro();

        if (opcao != 99) {
            switch (opcao) {
                case 1:
                    printf("\nDigite a matricula do aluno: ");
                    entrada.mat = lerinteiro();
                    printf("\nDigite o nome do aluno: ");
                    fgets(entrada.nome, 80, stdin);
                    printf("\nDigite o email do aluno: ");
                    fgets(entrada.email, 80, stdin);
                    inserir(tab, entrada);
                    break;
                
                case 2:
                    printf("\nDigite a matricula do aluno: ");
                    matricula = lerinteiro();
                    consultar(tab, matricula);
                    break;

                case 3:
                    printf("\nDigite a matricula do aluno: ");
                    matricula = lerinteiro();
                    remover(tab, matricula);
                    break;

                case 4:
                    printf("\nDigite a matricula: ");
                    entrada.mat = lerinteiro();
                    alterar(tab, entrada);
                    break;
                case 5:

                    break;
                case 6:

                    break;
                case 7:

                    break;
                default:

                    break;
            }
        }

        system("pause");
        system("cls");
    }
}
