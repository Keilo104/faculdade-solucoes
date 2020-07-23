#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void           add_to_playlist         (playlist_no*, musica*);
musica*        search_collection       (int);
void           add_to_lista_playlist   (lplaylists_no*);
void           print_playlist          (lplaylists_no*);
void           imprimir_playlist       ();
lplaylists_no* search_playlist         (int);
void           remove_song             ();


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
	
	while(resposta != 0) {
		exibir_menu();
		scanf("%d", &resposta);
		fflush(stdin);
		
		if(resposta == 1) {
			musica* new_musica = create_song();
			add_first_to_collection(new_musica);
			
			printf("Musica inserida com sucesso!\n");
			
		} else if(resposta == 2) {
			print_collection();
			
		} else if(resposta == 3) {
			lplaylistsprintf("Obrigado por usar o programa!\n");_no* new_playlist = create_new_playlist();
			add_to_lista_playlist(new_playlist);
			
			printf("Playlist criada com sucesso!\n");
			
		} else if(resposta == 4) {
			printf("how do that\n\n");
			
		} else if(resposta == 5) {
			imprimir_playlist();
			
		} else if(resposta == 6) {
			remove_song();
			printf("Música removida com sucesso!\n");
			
		} else if(resposta == 0){
			printf("Obrigado por usar o programa!\n");
			
		} else {
			printf("Por favor, digite alguma opção valida.\n");
		}
		
	}
	return 0;
}


void exibir_menu() {
	printf("\nEscolha uma das opcoes abaixo:\n");
	printf("[1] - Cadastrar nova musica\n");
	printf("[2] - Imprimir todas as musicas na colecao\n");
	printf("[3] - Criar nova playlist\n");
	printf("[4] - Shuffle uma playlist\n");
	printf("[5] - Imprimir todas as musicas numa playlist\n");
	printf("[6] - Remover uma musica da colecao\n");
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
	
	printf("Digite o nome da nova musica: ");
	gets(new_song->titulo);
	
	printf("Digite o nome do artista da nova musica: ");
	gets(new_song->artista);
	
	printf("Digite o tempo da musica no formato HH:MM:SS: ");
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
		printf("\n\nMusica #%d\n\n", cont++);
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
	printf("Duracao: %02d:%02d:%02d\n", horas, minutos, segundos);
}


lplaylists_no* create_list_playlist() {
	lplaylists_no* new_list = malloc(sizeof(lplaylists_no));
	
	new_list->musicas = NULL;
	new_list->prox = NULL;
	
	return new_list;
}


playlist_no* create_playlist_no() {
	playlist_no* playlist = malloc(sizeof(playlist_no));
	playlist->musica = NULL;
	playlist->prox = playlist;
	
	return playlist;
}


void add_to_playlist(playlist_no* playlist, musica* musica) {
	if(musica && playlist) {
		playlist_no* new_no = malloc(sizeof(playlist_no));
		playlist_no* p = playlist;
		new_no->musica = musica;
		new_no->prox = playlist;
		
		while(p->prox != playlist) {
			p = p->prox;
		}
		
		p->prox = new_no;
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
	
	printf("Digite os ids das musicas dessa playlist: ");
	gets(musicas);
	
	playlist_no* playlist = create_playlist_no();
	new_playlist->musicas = playlist;
	
	song = strtok(musicas, " ");
	
	while(song != NULL) {
		song_id = atoi(song);
		
		musica* musica = search_collection(song_id);
		add_to_playlist(playlist, musica);
		
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
		printf("\n\nMusica #%d\n\n", cont++);
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
	print_playlist(playlist);
}


void remove_from_playlist(lplaylists_no* playlist, int id) {
	playlist_no* p = playlist->musicas;
	playlist_no* q = playlist->musicas->prox;
	
	while(q != playlist->musicas) {
		if(q->musica->id == id) {
			p->prox = q->prox;
		}
		
		p = p->prox;
		q = q->prox;
	}
}


void remove_song() {
	int id;
	
	printf("Digite o id da musica a ser removida: ");
	scanf("%d", &id);
	fflush(stdin);
	
	lplaylists_no* p = lista_playlist->prox;
	
	while(p) {
		remove_from_playlist(p, id);

		p = p->prox;
	}
	
	musica_no* q = colecao->prox;
	
	while(q) {
		if(q->musica->id == id) {
			q->prox->ant = q->ant;
			q->ant->prox = q->prox;

			free(q->musica);
			free(q);
		}
		q = q->prox;
	}
}