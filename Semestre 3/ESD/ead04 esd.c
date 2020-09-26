#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAXVERTICES 100

typedef int Peso;
typedef struct Grafo {
	int** matriz;
	int NumVert;
	int NumArestas;
	int direcionado; // 0 não direcionado - 1 direcionado
} Grafo;

Grafo* createGrafo(int vert, int direcionado) {
	Grafo* grafo = calloc(sizeof(Grafo), 1);
	grafo->NumVert = vert;
	grafo->NumArestas = 0;
	grafo->matriz = malloc(sizeof(int *) * vert);
	grafo->direcionado = direcionado;
	
	int i;
	for(i=0; i<vert; i++) {
		grafo->matriz[i] = calloc(sizeof(int), vert);
	}

	return grafo;
}

void insertAresta(Grafo* grafo, int vert1, int vert2) {
	if(grafo->matriz[vert1][vert2] != 1) {
		if(grafo->direcionado) {
			grafo->matriz[vert1][vert2] = 1;
			grafo->NumArestas++;
		} else if (vert1 != vert2) {
			grafo->matriz[vert1][vert2] = 1;
			grafo->matriz[vert2][vert1] = 1;
			grafo->NumArestas++;
		}
	}
}

void removeAresta(Grafo* grafo, int vert1, int vert2) {
	if(grafo->matriz[vert1][vert2] != 0) {
		if(grafo->direcionado) {
			grafo->matriz[vert1][vert2] = 0;
			grafo->NumArestas--;
		} else {
			grafo->matriz[vert1][vert2] = 0;
			grafo->matriz[vert2][vert1] = 0;
			grafo->NumArestas--;
		}
	}
}

void printMatrizAdj(Grafo* grafo) {	
	int i, j;
	
	printf("x| ");
	for(i = 0; i < grafo->NumVert; i++) {
		printf("%d ", i);
	}
	printf("\n-+");
	for(i = 0; i < grafo->NumVert*2; i++) {
		printf("-");
	}
	printf("\n");
	
	for(i = 0; i < grafo->NumVert; i++) {
		printf("%d| ", i);
		for(j = 0; j < grafo->NumVert; j++) {
			printf("%d ", grafo->matriz[i][j]);
		}
		printf("\n");
	}
}

void printListaArestas(Grafo* grafo) {
	int i, j;
	
	if(grafo->direcionado > 0) {
		for(i = 0; i<grafo->NumVert; i++) {
			for(j = 0; j<grafo->NumVert; j++) {
				if(grafo->matriz[i][j] > 0) {
					printf("%d -> %d\n", i, j);
				}
			}
		}
	} else {
		for(i = 0; i<grafo->NumVert; i++) {
			for(j = i; j<grafo->NumVert; j++) {
				if(grafo->matriz[i][j] > 0) {
					printf("%d - %d\n", i, j);
				}
			}
		}
	}
}

int arestaExiste(Grafo* grafo, int i, int j) {
	return (grafo->matriz[i][j] > 0);
}

void transformIntoNotDirected(Grafo* grafo) {
	int i, j;
	for(i = 0; i < grafo->NumVert; i++) {
		for(j = 0; j < grafo->NumVert; j++) {
			if(grafo->matriz[i][j] > 0 && grafo->matriz[j][i] == 0) {
				grafo->matriz[j][i] = grafo->matriz[i][j];
				grafo->NumArestas++;
			}
			
			if(i == j && grafo->matriz[i][j] > 0) {
				grafo->matriz[i][j] = 0;
				grafo->NumArestas--;
			}
		}
	}
	grafo->direcionado = 0;
}

int factorial(int x) {
	int fact = 1, i;
	
	for(i=0; i<x; i++) {
		fact *= i+1;
	}
	
	return fact;
}

int permutations(int n, int r) {
	return factorial(n) / factorial(n - r);
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int compareMatrix(int **a, int **b, int x) {
	int i, j;
	for(i=0; i<x; i++) {
		for(j=0; j<x; j++) {
			if(a[i][j] != b[i][j]) {
				return 0;
			}
		}
	}
	
	return 1;
}

int** transpose(int** a, int x) {
	int i, j;
	int **retorno = malloc(sizeof(int *) * x);
	for(i = 0; i<x; i++) {
		retorno[i] = malloc(sizeof(int) * x);
	}
	
	for(i=0; i<x; i++) {
		for(j=0; j<x; j++) {
			retorno[i][j] = a[j][i];
		}
	}
	
	return retorno;
}


int** multMatrix(int **a, int **b, int x) {
	int i, j, k, soma;
	int **retorno = malloc(sizeof(int *) * x);
	for(i = 0; i<x; i++) {
		retorno[i] = malloc(sizeof(int) * x);
	}
	
	for(i=0; i<x; i++) {
		for(j=0; j<x; j++) {
			soma = 0;
			for(k=0; k<x; k++) {
				soma += a[i][k] * b[k][j];
			}
			retorno[i][j] = soma;
		}
	}
	
	return retorno;
}

int** generateMatrix(int** grafo, int *a, int x) {
	int i, j;
	int **retorno = malloc(sizeof(int *) * x);
	for(i = 0; i<x; i++) {
		retorno[i] = calloc(sizeof(int), x);
	}
	
	for(i = 0; i < x; i++) {
		for(j = 0; j < x; j++) {
			retorno[i][j] = grafo[a[i]][a[j]];
		}
	}
	
	return retorno;
}

int checkAllAlphas(int** grafo1, int** grafo2, int *a, int l, int r, int y) {
	int i, x = 0;
	int **p;
	
	if(l == r) {
		p = generateMatrix(grafo1, a, r);
		/*
		for(i=0; i<r; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		
		for(i = 0; i < r; i++) {
			printf("%d| ", i);
			for(j = 0; j < r; j++) {
				printf("%d ", p[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/
		
		x = compareMatrix(grafo1, p, r);
	
	} else {
		for(i = l; i < y; i++) {
			swap(a+l, a+i);
			x |= checkAllAlphas(grafo1, grafo2, a, l+1, r, y);
			swap(a+l, a+i);
		}
	}
	
	return x;
}

int checkSubgrafo(Grafo* grafo1, Grafo* grafo2) {
	if(grafo2->NumVert > grafo1->NumVert) {
		return 0;
	}
	
	int* allIdxs = malloc(sizeof(int) * grafo1->NumVert);
	int i;
	
	for(i=0; i<grafo1->NumVert; i++) {
		allIdxs[i] = i;
	}

	return checkAllAlphas(grafo1->matriz, grafo2->matriz, allIdxs, 0, grafo2->NumVert, grafo1->NumVert);
}

void transformIntoDirected(Grafo* grafo) {
	grafo->direcionado = 1;
	grafo->NumArestas *= 2;
}

int checkIfComplete(Grafo* grafo) {
	int i, j;
	
	if(grafo->direcionado) {
		return 0;
	}

	for(i=0;i<grafo->NumVert;i++) {
		for(j=i+1;j<grafo->NumVert;j++) {
			if(grafo->matriz[i][j] == 0) {
				return 0;
			}
		}
	}
	
	return 1;
}

int main() {
	setlocale(LC_ALL, "portuguese");
	
	Grafo* uau = createGrafo(5, 1);
	Grafo* uwu = createGrafo(3, 1);
	
	insertAresta(uau, 0, 1);
	insertAresta(uau, 0, 3);
	insertAresta(uau, 1, 3);
	insertAresta(uau, 2, 3);
	insertAresta(uau, 2, 4);
	insertAresta(uau, 3, 4);
	
	insertAresta(uwu, 1, 2);
	insertAresta(uwu, 0, 1);
	insertAresta(uwu, 0, 2);
	
	printMatrizAdj(uau);
	printf("\n\n");
	printMatrizAdj(uwu);
	printf("\n\n");
	
	transformIntoNotDirected(uau);
	transformIntoNotDirected(uwu);
	
	printMatrizAdj(uau);
	printf("\n\n");
	printMatrizAdj(uwu);
	printf("\n\n");
	
	if(checkSubgrafo(uau, uwu)) {
		printf("é subgrafo! hooray!");
	} else {
		printf("nem é kk");
	}
	
	return 0;
}