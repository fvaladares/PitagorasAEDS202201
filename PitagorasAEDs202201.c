/*
 ============================================================================
 Name        : PitagorasAEDs202201.c
 Author      : Fabricio Valadares
 Version     :
 Copyright   : Copy with attribution
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * malloc -- aloca memória dinamicamente
 * calloc -- aloca memória dinamencamente e inicializa com 0
 * realloc -- aumenta a quantidade de memória (insere mais memória)
 * free -- libera a memória
 */

/**
 * Protótipo das funções (assinatura ou interface)
 * a implementação está no final do arquivo.
 */
void exemplo01(); // Ponteiro declaração
void exemplo02(); // Ponteiro manipulação
void exemplo03(); // Ponteiro com vetor (trabalhando com vetores)
void exemplo04(); // Alocação de memória
void exemplo05();
void exemplo06();
void exemplo07VetorPonteiro();
void exemplo08MatrizPonteiro();
void printStringInt(char *word, int *pt);

// Construção do tipo abstrato de dados tipo_pessoal
struct tipo_pessoa {
	char *nome;
	int idade;
	float peso;
};

// Definição do identificador tPessoa,
// isso evita a utilização da palavra struct em todas as chamadas
typedef struct tipo_pessoa tPessoa;

/**
 * Exemplo de declaração da função antes do main
 */
// Exemplo de uso da estrutura tPessoa
void imprimirPessoa(tPessoa pessoa) {
	printf("\n");
	printf("Nome: %s\n", pessoa.nome);
	printf("Idade: %d\n", pessoa.idade);
	printf("Peso: %.2f\n", pessoa.peso);
	printf("\n");
}

void exemploEstrutura() {
	struct tipo_pessoa pessoa;
	tPessoa pessoas[10];

	pessoa.nome = "Fabricio Geraldo Valadares";
	pessoa.idade = 35;
	pessoa.peso = 90.5f;

	imprimirPessoa(pessoa);
}


int main() {

	int opt = 0;

	srand(time(0));

	for (int i = 0; i < 100; i++)
		printf("%3d, ", rand()%100 + 1);

	while (1) {
		printf("\n\n>>>Escolha uma opção abaixo<<<\n\n");

		printf("\t%2d - Declaração de ponteiros\n", 1);
		printf("\t%2d - Ponteiro manipulação\n", 2);
		printf("\t%2d - Ponteiro com vetor\n", 3);
		printf("\t%2d - Alocação de memória, uma variável\n", 4);
		printf("\t%2d - Alocação de memória, vetor \n", 5);
		printf("\t%2d - Alocação de memória, vetor (caminhando com ptr)\n", 6);
		printf("\t%2d - Alocação de memória, vetor (calloc + ptr auxiliar)\n",
				7);
		printf("\t%2d - Alocação de memória, matriz\n", 8);

		printf("Opção:\\>");
		scanf("%d", &opt);

		switch (opt) {
		case 1:
			exemplo01();
			break;
		case 2:
			exemplo02();
			break;
		case 3:
			exemplo03();
			break;
		case 4:
			exemplo04();
			break;
		case 5:
			exemplo05();
			break;
		case 6:
			exemplo06();
			break;

		case 7:
			exemplo07VetorPonteiro();
			break;
		case 8:
			exemplo08MatrizPonteiro();
			break;
		default:
			printf(
					"\n\nOpção inválida, tente novamente ou, pressione ctrl+c para cancelar.\n");
			break;
		}
	}

	/**
	 * Testes
	 */

	//	printf("\npt: \t%p", pt);
	//	printf("\nptaux: \t%p", ptAux);
	//
	//	ptAux++;
	//	printf("\npt: \t%p", pt);
	//	printf("\nptaux: \t%p", ptAux);
	//	for (int i = 0; i < 100; i++){
	//
	//	}
	return 0;
}

void exemplo01() {
	int *pt = NULL;
	int count = 10;

	pt = &count;

	*pt = 13;

	printf("count: %d\n", count); // %d número inteiro
	printf("*pt: %d\n", *pt);
	printf("pt: \t\t %p\n", pt); // %p endereço de memória
	printf("&count: \t %p\n", &count);
	printf("&pt: \t\t %p\n", &pt); // %p endereço de memória

}

void exemplo02() {
	int a = 10;
	int b = 20;
	int *pta;
	int *ptb;

	pta = &a;
	ptb = &b;

	printStringInt("Valor de a:", pta);
	printStringInt("Valor de b:", ptb);

	printf("\nDois ponteiros apontando para a mesma variável: \n");

	pta = ptb;

	*pta = 37;

	printStringInt("Valor de a:", pta);
	printStringInt("Valor de b:", ptb);

	pta = &a;

	printf("\nCopiando o conteúdo de um ponteiro no outro: \n");

	*pta = 2020;

	pta = ptb;

	printStringInt("Valor de a:", pta);
	printStringInt("Valor de b:", ptb);

	printf("\n");

	pta = &a;
	ptb = &b;

	printf("Endereço de pta: %p\n", pta);
	pta++;
	printf("Endereço de pta++: %p\n", pta);

	printf("\n");
	pta = &a; // retorna o ponteiro para a posição original
	printStringInt("Valor de a:", pta);

	// incrementa o valor da variável apontada
	(*pta)++;
	printStringInt("Valor de a++:", pta);

}

void exemplo03() {
	int *pt = NULL;
	int num[10];

	// pt aponta para num ou pt = &num[0]
	pt = num;

	// Percorrer o vetor usando o ponteiro;
	for (int i = 0; i < 10; i++) {
		// num[i] = i+1
		*pt = i + 1; // Alternado o valor do vetor
		pt++; // incrementa o endereço apontado pelo ponteiro.
	}

	pt = num; // retorna com o ponteiro para a cabeça do vetor

	printf("\nImprimindo: \n");

	for (int i = 0; i < 10; i++) {
		printf("%d, ", *pt);
		pt++;
	}
	//
	//	printf("%li bytes\n", sizeof(int));
	//	printf("%li bytes\n", sizeof(float));
	//	printf("%li bytes\n", sizeof(double));

}

void exemplo04() {
	//	void *malloc (unsigned int num)
	//	malloc(sizeof(int))

	int *pt = NULL;

	pt = malloc(sizeof(int)); // reserva memória para um inteiro!

	if (pt == NULL) {
		printf("\n**ERRO: Memória insuficiente!!**\n");
		return;
	}

	printf("\nInforme a idade: ");
//	scanf("%d", &idade);
	scanf("%d", pt); // endereço onde o dado será salvo

	// imprime o conteúdo associado ao ponteiro
	printf("\nA idade informada foi : %d\n", *pt);

}

void exemplo05() {
	int *pt = NULL;
	int a;

	printf("\nA quantidade de idades: ");
	scanf("%d", &a); // endereço onde o dado será salvo
	// reserva memória para um vetor de inteiros!
	pt = malloc(a * sizeof(int));

	// Preenche o vetor
	for (int i = 0; i < a; i++) {
		printf("Infore a %da. idade: ", i + 1);
		scanf("%d", &pt[i]);
	}

	printf("\nImprimendo as idades informadas: \n");

	for (int i = 0; i < a; i++) {
		printf("%d, ", pt[i]);
	}

}

void exemplo06() {
	int *pt = NULL;
	int a;

	printf("\nExemplo 06 A quantidade de idades: ");
	scanf("%d", &a); // endereço onde o dado será salvo
	// reserva memória para um vetor de inteiros!
	pt = malloc(a * sizeof(int));

	// Preenche o vetor
	for (int i = 0; i < a; i++) {
		printf("Infore a %da. idade: ", i + 1);
		scanf("%d", pt);
		pt++;
	}

	// retorna para a posição inicial
	for (int i = 0; i < a; i++) {
		pt--;
	}

	printf("\nImprimendo as idades informadas: \n");

	for (int i = 0; i < a; i++) {
		printf("%d, ", *pt);
		pt++;
	}

	printf("\n");

	for (int i = 0; i < a; i++) {
		pt--;
	}

	printf("\n%p\n", &pt);

	free(pt); // libera a memória aloca
	pt = NULL;

	printf("\nDepois da mudança: %p\n", pt);

}

void exemplo07VetorPonteiro() {
	srand(time(NULL)); // Cria uma semente baseado na hora atual
	int *pt = NULL;
	int *ptAux = NULL;

	printf("\n\nTeste 1: \n\n");
	pt = calloc(10, sizeof(int));

	ptAux = pt;

	// Demonstra que o calloc preeche o novo vetor com zeros
	for (int i = 0; i < 10; i++) {
		printf("*ptAux: %3d, i: %3d\n", *ptAux, i);
		ptAux++;
	}

	printf("\n\nTeste 2:\n\n");

	// Aponta o ptAux para o vetor alocado dinâmicamente
	ptAux = pt;

	for (int i = 0; i < 10; i++) {
//		Gera um número aleatório entre 1 e 100
		*ptAux = rand() % 100 + 1; //
		ptAux++;
	}

	// Volta o ponteiro para acabeça do vetor.
	ptAux = pt;

	for (int i = 0; i < 10; i++) {
		printf("*ptAux: %3d, i: %3d\n", *ptAux, i);
		ptAux++;
	}

	printf("\n");

}

void exemplo08MatrizPonteiro() {
	srand(time(NULL));
	int **pt = NULL; // armazenara uma matriz dinâmica
	int *ptAux = NULL;
	const int MAX = 5;

	// Alocação das linhas da matriz
	pt = calloc(MAX, sizeof(int*));

	// Alocação de memória para as colunas
	for (int i = 0; i < MAX; i++) {
		pt[i] = calloc(MAX, sizeof(int));
	}

	// Preenchimento da matrix
	for (int i = 0; i < MAX; i++) {
		ptAux = pt[i];
		for (int j = 0; j < MAX; j++){
//			pt[i][j] = (rand() % 100 + 1);
			*ptAux = (rand()% 100 + 1);
			ptAux++;
		}
	}

	// Impressão da matriz
	for (int i = 0; i < MAX; i++) {
		ptAux = pt[i]; // ptAux será usado para percorrer as colunas a matrix
		printf("|");
		for (int j = 0; j < MAX; j++){
			printf("[%d][%d]: %2d | ", i+1, j+1, *ptAux);
			ptAux++;
		}
		printf("\n");
	}
}

void printStringInt(char *word, int *pt) {
	printf("%s %d\n", word, *pt);
}

