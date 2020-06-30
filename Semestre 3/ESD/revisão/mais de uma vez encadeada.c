/*
Adaptar o exercício acima para listas duplamente encadeadas:

Inserção no início da lista.           xx
Inserção no final da lista.            xx
Inserção ordenada na lista.            xx
Busca na lista.                        xx
Remoção do primeiro elemento da lista. xx
Remoção do último elemento da lista.   xx
Busca e remoção na lista.              
Impressão da lista.                    xx
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NoD {
	int cont;
	struct NoD *prox;
	struct NoD *ant;
};

typedef struct NoD NoD;

NoD* createNew() {
	NoD *ini = malloc(sizeof(NoD));
	ini->prox = NULL;
	ini->ant = NULL;
	
	return ini;
}

void imprime(NoD* ini) {
	NoD *p;
	p=ini->prox;
	while(p) {
		printf("%d, ", p->cont);
		p=p->prox;
	}
}

void insertFirst(int k, NoD *ini) {
	NoD *novo = malloc(sizeof(NoD));
	novo->cont = k;
	
	novo->ant = ini;
	novo->prox = ini->prox;
	if(novo->prox) {
		novo->prox->ant = novo;
	}
	ini->prox = novo;
}

void insertLast(int k, NoD *ini) {
	NoD *novo = malloc(sizeof(NoD));
	novo->cont = k;
	novo->prox = NULL;
	
	NoD *p = ini->prox;
	
	while(p->prox) {
		p=p->prox;
	}
	
	novo->ant = p;
	p->prox = novo;
}

void insertOrderly(int k, NoD* ini) {
	NoD *p = ini->prox;
	
	while(p->prox && p->prox->cont < k) {
		p=p->prox;
	}
	
	// vitor delayzin TIMES TWO HELL YEA
	insertFirst(k, p);
}

NoD* busca(int k, NoD *ini) {
	NoD *p = ini->prox;
	
	while(p->prox && p->cont != k) {
		p=p->prox;
	}
	
	if(p->cont != k) {
		p = NULL;
	}
	
	return p;
}

void removeFirst(NoD *ini) {
	NoD *p = ini->prox->prox;
	free(ini->prox);
	ini->prox = p;
	p->ant = ini;
}

void removeLast(NoD *ini) {
	NoD *p = ini->prox;
	
	while(p->prox) {
		p=p->prox;
	}
	
	p->ant->prox = NULL;
	free(p);
}

void removeFromList(int k, NoD *ini) {
	NoD *p = busca(k, ini);
	
	if(p) {
		removeFirst(p->ant);
	}
}

int main() {
	NoD *uau = createNew();
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
	
	//removeFirst(uau);
	//removeLast(uau);
	
	removeFromList(7, uau);
	
	imprime(uau);
	return 0;
}

