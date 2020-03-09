#include <stdio.h>
#include <stdlib.h>

typedef struct NoD {
  int cont;
  struct NoD *prox, *ant;
} NoD;

typedef struct No {
  int cont;
  struct No *prox;
} No;

No* new_llcc() {
  No* ini = malloc(sizeof(No));
  ini->prox = ini;

  return ini;
}

NoD* new_ldlcc() {
  NoD* ini = malloc(sizeof(NoD));
  ini->prox = ini;
  ini->ant = ini;

  return ini;
}

void insert_llcc(No* p, int k) {
  No* novo = malloc(sizeof(No));
  novo->cont = k;
  novo->prox = p->prox;
  p->prox = novo;
}

void insert_ldlcc(NoD* p, int k) {
  NoD* novo = malloc(sizeof(NoD));
  novo->cont = k;
  novo->prox = p->prox;
  novo->ant = p;
  p->prox = novo;
  novo->prox->ant = novo;
}

void print_llcc(No* ini) {
  No *p = ini->prox;

  while(p != ini) {
    printf("%d, ", p->cont);
    p = p->prox;
  }
}

void print_ldlccf(NoD* ini) {
  NoD *p = ini->prox;

  while(p != ini) {
    printf("%d, ", p->cont);
    p = p->prox;
  }
}

void print_ldlccb(NoD* ini) {
  NoD *p = ini->ant;

  while(p != ini) {
    printf("%d, ", p->cont);
    p = p->ant;
  }
}

No* search_llcc(No *ini, int k) {
  No* p = ini;
  No* q = ini->prox;
  ini->cont = k;

  while(q->cont != k) {
    p = p->prox;
    q = q->prox;
  }

  if(q == ini) {
    return NULL;
  } else {
    return p;
  }
}

NoD* search_ldlcc(NoD *ini, int k) {
  NoD* p = ini->prox;
  ini->cont = k;

  while(p->cont != k) {
    p = p->prox;
  }

  if(p == ini) {
    return NULL;
  } else {
    return p;
  }
}

int remove_llcc(No *ini, int k) {
  No* p = search_llcc(ini, k);
  
  if(p) {
    No* q = p->prox;
    p->prox = q->prox;
    free(q);
    return 1;
  } else {
    return 0;
  }
}

void remove_ldlcc(NoD *remove) {
  remove->ant->prox = remove->prox;
  remove->prox->ant = remove->ant;
  free(remove);
}

void insere_lcco(No* ini, int k) {
  No* p = ini;
  No* q = ini->prox;
  ini->cont = k;

  while(q->cont < k) {
    p = p->prox;
    q = q->prox;
  }

  insert_llcc(p, k);
}

int main() {
  No* novo = new_llcc();
  insert_llcc(novo, 123);
  insert_llcc(novo, 99);
  insert_llcc(novo, 75);
  insert_llcc(novo, 67);
  insert_llcc(novo, 63);
  insert_llcc(novo, 7);
  insert_llcc(novo, 3);
  insert_llcc(novo, 2);
  insert_llcc(novo, -77);

  print_llcc(novo);
  printf("\n\n");

  insere_lcco(novo, 100);

  print_llcc(novo);
  return 0;
}
