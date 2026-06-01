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

