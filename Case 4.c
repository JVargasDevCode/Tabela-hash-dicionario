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

	} while(opcao != 0);
	liberarMemoria();
	return 0;
}