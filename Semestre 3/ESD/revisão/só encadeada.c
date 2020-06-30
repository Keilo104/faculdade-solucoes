/*
Criar uma lista simplesmente encadeada com cabeça para armazenar
inteiros que implemente as seguintes funções:

Inserção no início da lista.           xx
Inserção no final da lista.            xx
Inserção ordenada na lista.            xx
Busca na lista.                        xx
Remoção do primeiro elemento da lista. xx
Remoção do último elemento da lista.   xx
Busca e remoção na lista.              xx
Impressão da lista.                    xx
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
	int cont;
	struct No *prox;
};

typedef struct No No;

No* createNew() {
	No *ini = malloc(sizeof(No));
	ini->prox = NULL;
	
	return ini;
}

void imprime(No* ini) {
	No *p;
	p=ini->prox;
	while(p) {
		printf("%d, ", p->cont);
		p=p->prox;
	}
}

void insertFirst(int k, No *ini) {
	No *novo = malloc(sizeof(No));
	novo->cont = k;
	novo->prox = ini->prox;
	ini->prox = novo;
}

void insertLast(int k, No *ini) {
	No *novo = malloc(sizeof(No));
	novo->cont = k;
	novo->prox = NULL;
	
	No *p = ini->prox;
	
	while(p->prox) {
		p=p->prox;
	}
	
	p->prox = novo;
}

void insertOrderly(int k, No* ini) {
	No *novo = malloc(sizeof(No));
	novo->cont = k;
	
	No *p = ini->prox;
	
	while(p->prox && p->prox->cont < k) {
		p=p->prox;
	}
	
	// vitor delayzin
	
	novo->prox = p->prox;
	p->prox = novo;
}

No* busca(int k, No *ini) {
	No *p = ini->prox;
	
	while(p->prox && p->cont != k) {
		p=p->prox;
	}
	
	if(p->cont != k) {
		p = NULL;
	}
	
	return p;
}

No* buscaAnt(int k, No *ini) {
	No *p = ini->prox;
	No *q = ini;
	
	while(p->prox && p->cont != k) {
		q=p;
		p=p->prox;
	}
	
	if(p->cont != k) {
		q = NULL;
	}
	
	return q;
}

void removeFirst(No *ini) {
	No *p = ini->prox->prox;
	free(ini->prox);
	ini->prox = p;
}

void removeLast(No *ini) {
	No *p = ini->prox;
	No *q = ini;
	
	while(p->prox) {
		q=p;
		p=p->prox;
	}
	
	free(p);
	q->prox = NULL;
}

void removeFromList(int k, No *ini) {
	No *p = buscaAnt(k, ini);
	
	if(p) {
		removeFirst(p);
	}
}

int main() {
	No *uau = createNew();
	insertFirst(2, uau);
	insertFirst(1, uau);
	insertLast(4, uau);
	insertLast(5, uau);
	insertLast(6, uau);
	insertFirst(0, uau);
	insertOrderly(3, uau);
	insertOrderly(7, uau);
	insertOrderly(2, uau);
	insertOrderly(9, uau);
	
	removeFromList(8, uau);
	
	imprime(uau);
	return 0;
}

