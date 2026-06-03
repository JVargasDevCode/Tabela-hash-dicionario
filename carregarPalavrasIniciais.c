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