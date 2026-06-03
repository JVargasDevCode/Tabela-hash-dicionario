#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct Palavra {
	char palavra[50];
	char definicao[200];
	struct Palavra *prox;
} Palavra;

typedef struct {
	Palavra *lista;
} Hash;

Hash tabela[TAM];

void inicializarTabela() {
	for(int i = 0; i < TAM; i++) {
		tabela[i].lista = NULL;
	}
}

int funcaoHash(char *str) {
	int soma = 0;

	while(*str) {
		soma += *str;
		str++;
	}

	return soma % TAM;
}
void inserir(char *palavra, char *definicao) {
    int indice = funcaoHash(palavra);
    
    Palavra *aux = tabela[indice].lista;
    while(aux != NULL) {
        if(strcmp(aux->palavra, palavra) == 0) {
            strcpy(aux->definicao, definicao); 
            printf("Palavra ja existia. Definicao atualizada!\n");
            return;
        }
        aux = aux->prox;
    }

    Palavra novo = (Palavra) malloc(sizeof(Palavra));
    if (novo == NULL) {
        printf("Erro: Falha ao alocar memoria!\n");
        return;
    }

    strcpy(novo->palavra, palavra);
    strcpy(novo->definicao, definicao);

    novo->prox = tabela[indice].lista;
    tabela[indice].lista = novo;
    printf("\n Palavra foi insirida com sucesso!\n");
}
