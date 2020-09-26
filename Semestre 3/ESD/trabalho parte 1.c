#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

typedef struct musica {
	int id;
	char titulo[200];
	char artista[200];
	int duracao; // segundos
} musica;


typedef struct musica_no {
	musica *musica;
	struct musica_no *ant;
	struct musica_no *prox;
} musica_no;


typedef struct playlist_no {
	musica *musica;
	struct playlist_no *prox;
} playlist_no;


typedef struct lplaylists_no {
	int id;
	char nome[200];
	int qtd_musicas;
	playlist_no *musicas;
	struct lplaylists_no *prox;
} lplaylists_no;


void           exibir_menu             ();
musica_no*     create_collection       ();
void           add_first_to_collection (musica*);
musica*        create_song             ();
void           print_collection        ();
void           print_song              (musica* song);
lplaylists_no* create_list_playlist    ();
lplaylists_no* create_new_playlist     ();
playlist_no*   create_playlist_no      ();
void           add_to_playlist         (lplaylists_no*, musica*);
musica*        search_collection       (int);
void           add_to_lista_playlist   (lplaylists_no*);
void           print_playlist          (lplaylists_no*);
void           imprimir_playlist       ();
lplaylists_no* search_playlist         (int);
void           remove_song             ();
void           shuffle_playlist        (lplaylists_no*);
void           clear_playlist          (lplaylists_no*);
void           swap_items              (int*, int*);
void           shuffle_array           (int*, int);
void           option_shuffle_playlist ();


// GLOBAIS DE CONTAGEM
int cont_musicas = 0;
int cont_playlists = 0;


// LISTAS GLOBAIS
musica_no* colecao;
lplaylists_no* lista_playlist;


int main() {
	int resposta = -1;
	colecao = create_collection();
	lista_playlist = create_list_playlist();
	
	setlocale(LC_ALL, "Portuguese");
	
	while(resposta != 0) {
		exibir_menu();
		scanf("%d", &resposta);
		fflush(stdin);
		
		if(resposta == 1) {
			musica* new_musica = create_song();
			add_first_to_collection(new_musica);
			
			printf("Música inserida com sucesso!\n");
			
		} else if(resposta == 2) {
			print_collection();
			
		} else if(resposta == 3) {
			lplaylists_no* new_playlist = create_new_playlist();
			add_to_lista_playlist(new_playlist);
			
			printf("Playlist criada com sucesso!\n");
			
		} else if(resposta == 4) {
			option_shuffle_playlist();
			
		} else if(resposta == 5) {
			imprimir_playlist();
			
		} else if(resposta == 6) {
			remove_song();
			
		} else if(resposta == 0){
			printf("Obrigado por usar o programa!\n");
			
		} else {
			printf("Por favor, digite alguma opção valida.\n");
		}
		
	}
	return 0;
}


void exibir_menu() {
	printf("\nEscolha uma das opções abaixo:\n");
	printf("[1] - Cadastrar nova música\n");
	printf("[2] - Imprimir todas as músicas na coleção\n");
	printf("[3] - Criar nova playlist\n");
	printf("[4] - Shuffle uma playlist\n");
	printf("[5] - Imprimir todas as músicas numa playlist\n");
	printf("[6] - Remover uma música da coleção\n");
	printf("[0] - Sair do programa\n");
	
	printf(">>> ");
}


musica_no* create_collection() {
	musica_no* new_collection = malloc(sizeof(musica_no));
	
	new_collection->musica = NULL;
	new_collection->ant = NULL;
	new_collection->prox = NULL;
	
	return new_collection;
}


musica* create_song() {
	musica* new_song = malloc(sizeof(musica));
	char duration[9], hour_string[3], minute_string[3], second_string[3];
	int hour, minute, second;
	
	hour_string[2] = minute_string[2] = second_string[2] = '\0';
	
	new_song->id = cont_musicas++;
	
	printf("Digite o nome da nova música: ");
	gets(new_song->titulo);
	
	printf("Digite o nome do artista da nova música: ");
	gets(new_song->artista);
	
	printf("Digite o tempo da música no formato HH:MM:SS: ");
	gets(duration);
	
	strncpy(hour_string, duration, 2);
	strncpy(minute_string, duration+3, 2);
	strncpy(second_string, duration+6, 2);
	
	hour = atoi(hour_string);
	minute = atoi(minute_string);
	second = atoi(second_string);
	
	minute += hour * 60;
	second += minute * 60;
	
	new_song->duracao = second;
	
	return new_song;
}


void add_first_to_collection(musica* song) {
	musica_no* p = malloc(sizeof(musica_no));
	p->musica = song;
	
	musica_no* q = colecao->prox;
	
	p->ant = colecao;
	colecao->prox = p;
	p->prox = q;
	if(q) {
		q->ant = p;
	}
}


void print_collection() {
	musica_no* p = colecao->prox;
	int cont = 1;
	
	while(p) {
		printf("\n\nMúsica #%d\n\n", cont++);
		print_song(p->musica);
		
		p = p->prox;
	}
}


void print_song(musica* song) {
	int horas, minutos, segundos;
	
	printf("Id: %d\n", song->id);
	printf("Nome: %s\n", song->titulo);
	printf("Artista: %s\n", song->artista);
	segundos = song->duracao % 60;
	minutos = (song->duracao / 60) % 60;
	horas = song->duracao / 60 / 60;
	printf("Duração: %02d:%02d:%02d\n", horas, minutos, segundos);
}


lplaylists_no* create_list_playlist() {
	lplaylists_no* new_list = malloc(sizeof(lplaylists_no));
	
	new_list->musicas = NULL;
	new_list->prox = NULL;
	new_list->qtd_musicas = 0;
	
	return new_list;
}


playlist_no* create_playlist_no() {
	playlist_no* playlist = malloc(sizeof(playlist_no));
	playlist->musica = NULL;
	playlist->prox = playlist;
	
	return playlist;
}


void add_to_playlist(lplaylists_no* playlist, musica* musica) {
	if(musica && playlist) {
		playlist_no* new_no = malloc(sizeof(playlist_no));
		playlist_no* p = playlist->musicas;
		new_no->musica = musica;
		new_no->prox = playlist->musicas;
		
		while(p->prox != playlist->musicas) {
			p = p->prox;
		}
		
		p->prox = new_no;
		
		playlist->qtd_musicas++;
	}
}


musica* search_collection(int id) {
	musica_no* p = colecao->prox;
	
	while(p && p->musica->id != id) {
		p = p->prox;
	}
	
	if(p) {
		return p->musica;
	}
	
	return NULL;
}


lplaylists_no* create_new_playlist() {
	lplaylists_no* new_playlist = malloc(sizeof(lplaylists_no));
	char musicas[200], *song;
	int song_id;
	
	new_playlist->id = cont_playlists++;
	
	printf("Digite o nome da nova playlist: ");
	gets(new_playlist->nome);
	
	printf("Digite os ids das músicas dessa playlist: ");
	gets(musicas);
	
	new_playlist->musicas = create_playlist_no();
	
	song = strtok(musicas, " ");
	
	while(song != NULL) {
		song_id = atoi(song);
		
		musica* musica = search_collection(song_id);
		add_to_playlist(new_playlist, musica);
		
		song = strtok(NULL, " ");
    }
	
	new_playlist->prox = NULL;
	
	return new_playlist;
}


void add_to_lista_playlist(lplaylists_no* new_playlist) {
	new_playlist->prox = lista_playlist->prox;
	lista_playlist->prox = new_playlist;
}


void print_playlist(lplaylists_no* playlist) {
	playlist_no* p = playlist->musicas->prox;
	int cont = 1;
	
	while(p != playlist->musicas) {
		printf("\n\nMúsica #%d\n\n", cont++);
		print_song(p->musica);
		
		p = p->prox;
	}
}

lplaylists_no* search_playlist(int id) {
	lplaylists_no* p = lista_playlist->prox;
	
	while(p && p->id != id) {
		p = p->prox;
	}
	
	if(p) {
		return p;
	}
	
	return NULL;
}


void imprimir_playlist() {
	int id;
	
	printf("Digite o id da playlist: ");
	scanf("%d", &id);
	fflush(stdin);
	
	lplaylists_no* playlist = search_playlist(id);
	
	if(playlist) {
		printf("\nId: %d\n", playlist->id);
		printf("Nome da playlist: %s\n", playlist->nome);
		printf("Quantidade de músicas: %d\n", playlist->qtd_musicas);
		
		print_playlist(playlist);
	} else {
		printf("Playlist não encontrada.\n");
	}
}


void remove_from_playlist(lplaylists_no* playlist, int id) {
	playlist_no* p = playlist->musicas;
	playlist_no* q = playlist->musicas->prox;
	
	while(q != playlist->musicas) {
		if(q->musica->id == id) {
			p->prox = q->prox;
			playlist->qtd_musicas--;
		}
		
		p = p->prox;
		q = q->prox;
	}
}


void remove_song() {
	int id;
	
	printf("Digite o id da música a ser removida: ");
	scanf("%d", &id);
	fflush(stdin);
	
	lplaylists_no* p = lista_playlist->prox;
	
	if(p) {
		while(p) {
			remove_from_playlist(p, id);
	
			p = p->prox;
		}
		
		musica_no* q = colecao->prox, *r;
		
		while(q) {
			if(q->musica->id == id) {
				if(q->prox) {
					q->prox->ant = q->ant;
				}
				q->ant->prox = q->prox;
				
				r = q->prox;
				free(q->musica);
				free(q);
				q = r;
			} else {
				q = q->prox;
			}
		}
		
		printf("Música removida com sucesso!\n");
	} else {
		printf("Música não encontrada.\n");
	}
}


void clear_playlist(lplaylists_no* playlist) {
	playlist_no* p = playlist->musicas;
	playlist_no* q = playlist->musicas->prox;
	
	while(q != playlist->musicas) {
		p = q;
		q = q->prox;
		free(p);
	}
	
	playlist->qtd_musicas = 0;
	playlist->musicas->prox = playlist->musicas;
}


void swap_items(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


void shuffle_array(int *array, int n) {
	srand(time(NULL));
	int i, j;
	
	for(i = n-1; i > 0; i--) {
		j = rand() % (i + 1);
		
		swap_items(&array[i], &array[j]);
	}
}


void shuffle_playlist(lplaylists_no* playlist) {
	int qtd_inicial_musicas = playlist->qtd_musicas;
	
	int *ids = malloc(sizeof(int) * qtd_inicial_musicas);
	playlist_no *p = playlist->musicas->prox;
	int x = 0;
	
	while(p != playlist->musicas) {
		ids[x++] = p->musica->id;
		
		p = p->prox;
	}
	
	shuffle_array(ids, qtd_inicial_musicas);
	
	clear_playlist(playlist);
	
	for(x = 0; x < qtd_inicial_musicas; x++) {
		musica* musica = search_collection(ids[x]);
		add_to_playlist(playlist, musica);
	}
}


void option_shuffle_playlist() {
	int id;
	
	printf("Digite o id da playlist a ser aleatorizada: ");
	scanf("%d", &id);
	fflush(stdin);
	
	lplaylists_no* playlist = search_playlist(id);
	
	if(playlist) {
		shuffle_playlist(playlist);
		
		printf("Playlist aleatorizada com sucesso!\n");
	} else {
		printf("Playlist não encontrada.\n");
	}
	
}
