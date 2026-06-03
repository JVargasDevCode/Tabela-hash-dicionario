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
void buscar(char *palavra) {

	int indice = funcaoHash(palavra);

	Palavra *aux = tabela[indice].lista;

	while(aux != NULL) {

		if(strcmp(aux->palavra, palavra) == 0) {

			printf("\nPalavra: %s\n", aux->palavra);
			printf("Definicao: %s\n", aux->definicao);

			return;
		}

		aux = aux->prox;
	}

	printf("\nPalavra nao encontrada!\n");
}

void removerPalavra(char *palavra) {

	int indice = funcaoHash(palavra);

	Palavra *atual = tabela[indice].lista;
	Palavra *anterior = NULL;

	while(atual != NULL) {

		if(strcmp(atual->palavra, palavra) == 0) {

			if(anterior == NULL)
				tabela[indice].lista = atual->prox;
			else
				anterior->prox = atual->prox;

			free(atual);

			printf("\nPalavra removida com sucesso!\n");
			return;
		}

		anterior = atual;
		atual = atual->prox;
	}

	printf("\nPalavra nao encontrada!\n");
}

void exibirTabela() {

    printf("\n----- Tabela Hash ------\n");

	for(int i = 0; i < TAM; i++) {

		printf("[%d] -> ", i);

		Palavra *aux = tabela[i].lista;

		while(aux != NULL) {
			printf("%s -> ", aux->palavra);
			aux = aux->prox;
		}

		printf("NULL\n");
	}
}
void exibirEstatisticas() {

	int elementos = 0;
	int colisoes = 0;
	int maiorLista = 0;

	for(int i = 0; i < TAM; i++) {

		int tamanhoLista = 0;

		Palavra *aux = tabela[i].lista;

		while(aux != NULL) {
			tamanhoLista++;
			elementos++;
			aux = aux->prox;
		}

		if(tamanhoLista > 1)
			colisoes += tamanhoLista - 1;

		if(tamanhoLista > maiorLista)
			maiorLista = tamanhoLista;
	}

	float fatorCarga = (float) elementos / TAM;

	printf ("\n-------- Estatisticas ---------\n");
	printf("Numero de elementos: %d\n", elementos);
	printf("Numero de colisoes: %d\n", colisoes);
	printf("Fator de carga: %.2f\n", fatorCarga);
	printf("Maior lista encadeada: %d\n", maiorLista);
}
void carregarPalavrasIniciais() {

	inserir("Computador",
	        "Maquina capaz de processar dados.");

	inserir("Algoritmo",
	        "Sequencia de passos para resolver um problema.");

	inserir("Hash",
	        "Estrutura usada para armazenamento rapido.");

	inserir("Ponteiro",
	        "Variavel que armazena endereco de memoria.");

	inserir("Compilador",
	        "Programa que traduz codigo fonte.");
}

void liberarMemoria() {

	for(int i = 0; i < TAM; i++) {

		Palavra *aux = tabela[i].lista;

		while(aux != NULL) {

			Palavra *temp = aux;
			aux = aux->prox;
			free(temp);
		}
	}
}
int main() {

	inicializarTabela();
	carregarPalavrasIniciais();

	int opcao;

	char palavra[50];
	char definicao[200];

	do {

		printf ("\n------- Dicionario com a tabela Hash ---------\n");
		printf("1 - Inserir Palavra\n");
		printf("2 - Buscar Palavra\n");
		printf("3 - Remover Palavra\n");
		printf("4 - Exibir Tabela Hash\n");
		printf("5 - Exibir Estatisticas\n");
		printf("0 - Sair\n");
		printf("Opcao: ");

        if(scanf("%d", &opcao) != 1) {
        printf("Digite apenas numeros!\n");

        while(getchar() != '\n'); 
        opcao = -1;
        continue;
        }
		switch(opcao) {

        case 1:
            while(getchar() != '\n');
            printf("Digite a palavra: ");
            fgets(palavra, sizeof(palavra), stdin);
            palavra[strcspn(palavra, "\n")] = '\0';
        
            printf("Digite a definicao: ");
            fgets(definicao, sizeof(definicao), stdin);
            definicao[strcspn(definicao, "\n")] = '\0';
        
            inserir(palavra, definicao);
        
            printf("Palavra inserida!\n");
            break;
        
        case 2:
            while(getchar() != '\n');
            printf("Digite a palavra: ");
            fgets(palavra, sizeof(palavra), stdin);
            palavra[strcspn(palavra, "\n")] = '\0';
        
            buscar(palavra);
            break;
        
        case 3:
            while(getchar() != '\n');
            printf("Digite a palavra para remover: ");
            fgets(palavra, sizeof(palavra), stdin);
            palavra[strcspn(palavra, "\n")] = '\0';
        
            removerPalavra(palavra);
            break;
            case 4:
            exibirTabela();
			break;

	    	case 5:
			exibirEstatisticas();
			break;

	    	case 0:
			printf("Sistema encerrado.\n");
			break;

	    	default:
			printf("Opcao invalida!\n");
		}
} 
  while(opcao != 0);
	liberarMemoria();
 return 0;
}
