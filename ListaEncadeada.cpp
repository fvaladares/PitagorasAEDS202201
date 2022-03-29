//============================================================================
// Name        : ListaEncadeada.cpp
// Author      : Fabricio Valadares
// Version     :
// Copyright   : Copy with attribution
// Description : Hello World in C++, Ansi-style
//============================================================================

/**
 * Atividade:
 * Permitir inserir em uma posição definida pelo usuário,
 * se a posição não existir, inserir no final;
 * Permitir inserir direto no final da lista;
 */


/**
 * 1. Criar uma estrura que represente uma nó da lista ligada;
 * 2. Criar uma lista vazia;
 * 3. Criar uma função para imprimir a lista completa;
 * 4. Criar uma função para inserir os elementos diretamente
 * no início da lista;
 * 5. Criar uma função para excluir os elementos da lista a partir da chave;
 * 6. Criar na função principal os testes das demais funções;
 * 7. O usuário deve fornecer os valores das chaves;
 * 8. Pode haver repetição de chaves;
 * 9. Criar uma função para apagar a lista completamente;
 * 10. Criar uma função que elimina todas as chaves repetidas, eg. Usuário informa
 * chave = 2, para a lista [1,3,2,5,2,4,2] a lista final deve ser [1,3,5,4];
 */
#include <iostream>

typedef struct TipoNo{
	int chave;
	struct TipoNo* proximo;
} No;

void imprimirLista(No *listaOriginal) {
	if ( listaOriginal != NULL ) {
		No* aux = listaOriginal; // Aponta para o início da lista original;
		while(aux != NULL){
			std::cout << aux->chave << ", ";
			aux = aux -> proximo;
		}
		std :: cout << "\n";
	} else {
		std::cout << "A lista está vazia.\n";
	}
}

/**
 * Função para inserir elementos no início da lista
 */
No* inserirNovoNo(No* listaOriginal, int novaChave) {
	// Alocação de memória para um novo nó da lista;
	// Criação de um novo nó;
	No *novoNo = (No*)(malloc(sizeof(No*)));
	novoNo -> chave = novaChave;
	novoNo -> proximo = listaOriginal;

	return novoNo; // Endereço da nova lista;
}

// Retornará a primeira posição onde uma dada
// chave for encontrada;
int buscarChave(No *lista, int chave) {
	if ( lista != NULL) {
		int posicaoChave = 0;
		No* aux = lista;
		// Tentar criar o condição de parada direta
		while( aux != NULL) {
			if(aux -> chave == chave) {
				return posicaoChave;
			} else {
				aux = aux -> proximo;
				posicaoChave++;
			}
		}
	}

	return -1;
}

No* excluirElementoPorChave(No* lista, int chave) {
	if ( lista != NULL) {
		No* aux = lista;
		int posicaoChave = buscarChave(lista, chave);
		if ( posicaoChave != 0) {
			for ( int i = 0; i < posicaoChave -1; i++) {
				aux = aux -> proximo;
			}
			No* excluir = aux -> proximo;
			aux ->proximo = aux->proximo -> proximo;
			free(excluir);
		} else {
			No* excluir = aux;
			aux = aux -> proximo;
			free(excluir); // limpa a memória da posição corrente
			return aux;
		}
	}

	return lista;
}

int main() {
	std::cout << "Iniciando a aplicação. \n";
	No *lista = NULL; // Lista inicialmente aponta para nulo (NULL)
	imprimirLista(lista); // Tenta imprimir a lista vazia;

	lista = inserirNovoNo(lista, 3); // Insere um novo elemento na lista;
	lista = inserirNovoNo(lista, 4); // Insere um novo elemento na lista;
	lista = inserirNovoNo(lista, 33); // Insere um novo elemento na lista;
	lista = inserirNovoNo(lista, -1);

	imprimirLista(lista);
	std::cout << "O valor 33 está na posição "<< buscarChave(lista, 33) << "\n";
	std::cout << "O valor 55 está na posição "<< buscarChave(lista, 55) << "\n";

	lista = excluirElementoPorChave(lista, 33);
	imprimirLista(lista);
	lista = excluirElementoPorChave(lista, -1);
	imprimirLista(lista);

	std::cout << "Finalizando a aplicação. \n";
	return 0;
}
