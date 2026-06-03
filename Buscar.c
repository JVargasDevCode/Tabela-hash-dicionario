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
