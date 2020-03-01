#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

typedef struct No {
	int cont;
	struct No *prox;
} No;

No* createList() {
	No *nova;
	
	nova = malloc(sizeof(No));
	nova->cont = 0;
	nova->prox = NULL;
	
	return nova;
};

void pushList(No *lista, int conteudo) {
	No *novo;
	
	novo = malloc(sizeof(No));
	novo->cont = conteudo;
	novo->prox = NULL;
	
	No *p = lista;
	
	while(p->prox){
		p = p->prox;
	}
	
	lista->cont++;
	p->prox = novo;
};

void removeItem(No *itemAnt) {
	No* remove = itemAnt->prox;
	itemAnt->prox = remove->prox;
	free(remove);
}

void removeAll(No *lista, int remove) {
	No *p = lista->prox;
	No *q = lista;
	
	while(p) {
		if(p->cont == remove) {
			removeItem(q);
			p = q;
		} else {
			q = p;
			p = p->prox;
		}
	}
}

void printList(No *lista) {
	No *p = lista->prox;
	int i = 1;
	
	while(p) {
		printf("Elemento #%d: %d\n", i++, p->cont);
		p = p->prox;
	}
}

void insertFirst(No *lista, int conteudo) {
	No* p = lista->prox;
	
	No* novo = malloc(sizeof(No));
	novo->cont = conteudo;
	
	if(p) {
		novo->prox = p;
	} else {
		novo->prox = NULL;
	}
	
	lista->prox = novo;
}


No* copyList(No *lista) {
	No *nova = createList();
	No *p = lista->prox;
	No *item, *anterior = nova;
	
	nova->cont = lista->cont;
	
	while(p) {
		item = malloc(sizeof(No));
		item->cont = p->cont;
		anterior->prox = item;
		anterior = item;
		
		p = p->prox;
	}
	
	item->prox = NULL;
	
	return nova;
}

No* invertList(No *lista) {
	No* nova = createList();
	nova->cont = lista->cont;
	No* p = lista->prox;
	
	while(p) {
		insertFirst(nova, p->cont);
		p = p->prox;
	}
	
	return nova;
}

No* minimo(No *lista) {
	No *p = lista->prox;
	No* menor = NULL;
	
	while(p) {
		if(!menor || p->cont < menor->cont) {
			menor = p;
		}
    p = p->prox;
	}
	
	return menor;
}

int tamanhoNoCab(No *lista) {
	int i = 0;
	No *p = lista->prox;
	
	while(p) {
		i++;
		p = p->prox;
	}
	
	return i;
}


int tamanhoCab(No *lista) {
	return tamanhoNoCab(lista->prox);
}

void invert(No *lista) {
	No *p = lista->prox, *q, *r;
	
	q = p->prox;
	p->prox = NULL;
	
	while(q) {
		r = q->prox;
		q->prox = p;
		p = q;
		q = r;
	}

  lista->prox = p;
  
}

void libera(No *lista) {
	No *p = lista->prox, *q;
	
	while(p->prox) {
		q = p->prox;
		free(p);
		p = q;
	}

  lista->prox = NULL;
  
}

void insertAfter(No *lista, int conteudo) {
	No* q = lista->prox;
	No* novo = malloc(sizeof(No));
	
	novo->cont = conteudo;
	novo->prox = q;
	lista->prox = novo;
}

void conta_Remove(No *lista, int numero) {
	No *p = lista;
	int i;
	
	for(i = 1; i < numero; i++) {
		p = p->prox;
	}
	
	removeItem(p);
}

void conta_Insere(No* lista, int k, int x) {
	No *p = lista->prox;
  int i;
	
	for(i = 1; i < k; i++) {
		p = p->prox;
	}
	
	insertAfter(p, x);
}

int main() {
	return 0;
}