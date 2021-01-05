#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAMNOME 50
#define TAMSOBRENOME 50

typedef struct data {       // definição de classe tipo data
	int dia;                // dia
	int mes;                // mes
	int ano;                // ano
} data;

typedef struct registro {          // definição da classe tipo aluno
	char nome[TAMNOME];            // nome
	char sobrenome[TAMSOBRENOME];  // sobrenome
	data nasci;                    // data de nascimento
	int prontuario;                // prontuario
	char curso[4];                 // sigla do curso
} aluno;


// ===================== DEFINIÇÃO DE FUNÇÕES =====================

int exibir_menu();                        // exibe o menu e retorna a opção desejada

void cadastrar_aluno();                   // cadastra um aluno
int chk_data(data);                       // checa se uma data é válida
data get_date();                          // pede uma data válida para o usuário

void menu_mtd_ordenacao();                // escolhe o método de ordenação;
void menu_ordernar();                     // printa o menu de ordenação
int compare_attr(aluno, aluno, int);      // compara um atributo de dois alunos, retorna 1 se o primeiro for maior, 0 se o segundo for maior

void trocar(aluno*, aluno*);              // troca duas variáveis de lugar em uma lista

void ordernar_lista();                    // ordena a lista com bubblesort -- NÃO UTILIZADO
int partition(int, int, int);             // pariticiona a lista em elementos maiores e menores
void quick_sort(int, int, int);	          // ordena a lista com quick_sort
void merge(int, int, int, int);           // intercala dois vetores
void merge_sort(int, int, int);           // ordena a lista com merge sort
void insertion_sort(int);                 // ordena a lista com insertion sort
void selection_sort(int);                 // ordena a lista com selection sort

aluno criar_aluno_desejado(int);          // função que retorna um aluno com o atributo desejado

void busca_aluno();                       // função que busca um aluno na lista alunos, decide entre usar busca binária ou linear
int busca_linear(aluno, int);             // busca na lista alunos um atributo, busca linear
int busca_binaria(aluno, int);            // busca na lista alunos um atributo, busca binária

void remover_aluno();                     // função que remove um aluno da lista de alunos

void listar_all_alunos();                 // lista todos os alunos de acordo com a ordenação atual
void listar_alunos();                     // lista todos os alunos de acordo com algum parâmetro

void carregar_alunos();			    	  // função que carrega todos os alunos salvos em um arquivo
void salvar_alunos();			    	  // função que salva todos os alunos em um arquivo

// ================= DEFINIÇÃO DE VARIÁVEIS GLOBAIS =================

aluno alunos[1000];  // lista de todos os alunos
int qtd_aluno=0;     // qtd de alunos atualmente cadastrados
int mtd_ordenacao=0; /* ----- método de ordenação escolhido ------
					 0 = nenhum método escolhido
					 1 = Quick Sort
					 2 = Merge Sort
					 3 = Insertion Sort
					 4 = Selection Sort 
					 TODAS AS INSTÂNCIAS DE VARÍAVEIS DE TIPO DE ORDENAÇÃO USAM ESSE MESMO FORMATO */
int ord_atual=0;     /* ----- ordenação atual dos alunos ------
					 0 = sem ordenação
					 1 = ordenado por nome e sobrenome
					 2 = ordenado por sobrenome e nome
					 3 = ordenado por data de nascimento
					 4 = ordenado por prontuario
					 5 = ordenado por curso
					 6 = ordenado por nome
					 7 = ordenado por sobrenome
					 TODAS AS INSTÂNCIAS DE VARÍAVEIS PARA ORDENAÇÃO USAM ESSE MESMO FORMATO */

int main() {
	int op=-1;
	
	setlocale(LC_ALL, "portuguese");
	
	while(op != 0) {
		op = exibir_menu();
		
		switch(op) {
			case 1:
				carregar_alunos();
				break;

			case 2:
				salvar_alunos();
				break;
			
			case 3:
				cadastrar_aluno();
				break;
			
			case 4:
				remover_aluno();
				break;
			
			case 5:
				listar_all_alunos();
				break;
			
			case 6:
				listar_alunos();
				break;
				
			case 7:
				menu_mtd_ordenacao();
				break;
				
			case 8:
				menu_ordernar();
				break;
				
			case 9:
				busca_aluno();
				break;
			
			case 0:
				break;
			
			default:
				printf("Por favor, digite uma opção válida");
				break;
		}
		
	}
	
	printf("\nObrigado por utilizar o programa.\n");
	system("PAUSE");
	
	return 0;
}

/* função para printar o menu
retorno --> a opção digitada */
int exibir_menu() {
	int opcao;
	
	printf("\n\n============================ MENU ============================\n");
	printf("Digite uma das opções abaixo: \n");
	printf("[1] - Importar alunos salvos\n");
	printf("[2] - Salvar lista de alunos\n");
	printf("[3] - Cadastrar novo aluno\n");
	printf("[4] - Remover aluno\n");
	printf("[5] - Listar todos os alunos\n");
	printf("[6] - Listar todos os alunos de acordo com um requisito\n");
	printf("[7] - Escolher o modo de ordenação\n");
	printf("[8] - Ordernar lista de alunos\n");
	printf("[9] - Procurar aluno\n");
	printf("[0] - Sair do programa\n");
	printf("\n>>> ");
	
	scanf("%d", &opcao);
	fflush(stdin);
	
	return opcao;
}

// função para cadastrar um aluno novo
void cadastrar_aluno() {
	aluno novo_aluno;
	
	printf("\nDigite o nome do novo aluno: ");
	gets(novo_aluno.nome);
	
	printf("Digite o sobrenome do novo aluno: ");
	gets(novo_aluno.sobrenome);
	
	novo_aluno.nasci = get_date();
	
	printf("Digite o prontuário do novo aluno: ");
	scanf("%d", &novo_aluno.prontuario);
	fflush(stdin);
	
	printf("Digite a sigla do curso do novo aluno: ");
	gets(novo_aluno.curso);
	
	alunos[qtd_aluno] = novo_aluno;
	qtd_aluno++;
	ord_atual = 0;
	
	printf("\nCadastro realizado com sucesso!");
}

// pede uma data válida para o usuário
data get_date() {
	char nova_data[11], dia[3], mes[3], ano[5];
	int flag=1;
	data result;
	
	dia[2] = mes[2] = ano[4] = '\0';
	
	while(flag) {
		printf("Digite a data de nascimento do novo aluno: ");
		gets(nova_data);
	
		strncpy(dia, nova_data, 2);
		strncpy(mes, nova_data+3, 2);
		strncpy(ano, nova_data+6, 4);
		
		result.dia = atoi(dia);
		result.mes = atoi(mes);
		result.ano = atoi(ano);
		
		if(chk_data(result)) {
			flag = 0;
		} else {
			printf("\nPor favor, digite uma data válida.\n");
		}
	}
	
	return result;
}

/* função para checar se uma data é válida
check --> data a ser checada
retorno --> 1 caso a data seja válida, 0 caso não seja*/
int chk_data(data check){
	if(check.dia > 0 && check.dia < 32 && check.mes > 0 && check.mes < 13) {
		return 1;
	} else {
		return 0;
	}
}

// função que printa o menu de método de ordenação
void menu_mtd_ordenacao() {
	int opcao;
	
	printf("======== ESCOLHER MÉTODO DE ORDENAÇÃO ========\n");
	printf("Digite uma dos métodos de ordenação abaixo: \n");
	printf("[1] - Quick Sort\n");
	printf("[2] - Merge Sort\n");
	printf("[3] - Insertion Sort\n");
	printf("[4] - Selection Sort\n");
	printf("[0] - Sair do menu de escolha de método de ordenação\n");
	printf("\n>>> ");
	
	scanf("%d", &opcao);
	fflush(stdin);
	
	if(opcao != 0) {
		mtd_ordenacao = opcao;
		printf("Método de ordenação escolhido com sucesso!");
	}
}

// função que printa o menu para ordenar alunos, e chama a função de ordenação
void menu_ordernar() {
	int opcao, flag;
	
	if(mtd_ordenacao != 0) {
		printf("Deseja modificar o método de ordenação da lista? (1 - sim, 0 - não): ");
		scanf("%d", &flag);
		fflush(stdin);
		
		if(flag){	
			menu_mtd_ordenacao();
			printf("\n");
		}
	}
	
	while(mtd_ordenacao == 0) {
		menu_mtd_ordenacao();
		
		if(mtd_ordenacao == 0) {
			printf("\nPara ordenar os alunos, é necessário escolher um método de ordenação.\n");
			printf("Por favor, digite uma opção válida.\n");
		}
	}
	
	printf("\n======== ORDERNAR ALUNOS ========\n");
	printf("Digite uma das opções de ordenação abaixo: \n");
	printf("[1] - Nome e sobrenome\n");
	printf("[2] - Sobrenome e nome\n");
	printf("[3] - Data de nascimento\n");
	printf("[4] - Prontuário\n");
	printf("[5] - Curso\n");
	printf("[0] - Sair da ordenação\n");
	printf("\n>>> ");
	
	scanf("%d", &opcao);
	fflush(stdin);
	
	if(opcao != 0) {
		switch(mtd_ordenacao) {
			case 1:
				quick_sort(0, qtd_aluno - 1, opcao);
				ord_atual = 1;
				break;
				
			case 2:
				merge_sort(0, qtd_aluno, opcao);
				ord_atual = 2;
				break;
				
			case 3:
				insertion_sort(opcao);
				ord_atual = 3;
				break;
				
			case 4:
				selection_sort(opcao);
				ord_atual = 4;
				break;
				
			default:
				printf("Algo deu errado, me desculpa\n");
				break;
		}
		printf("Alunos ordenados com sucesso.");
	}
}

// troca dois alunos de posição
void trocar(aluno *item1, aluno *item2) {
	aluno aux = *item1;
	*item1 = *item2;
	*item2 = aux;
}

/* função que ordena a lista de alunos
ordem --> ordem desejada (referência a linha 49)*/
void ordernar_lista(int ordem) {
	aluno temp;
	int i, j, idx, flag;
	
	for(i = 0; i < qtd_aluno; i++) {
		temp = alunos[i];
		flag = 0;
		
		for(j = i+1; j < qtd_aluno; j++) {
			if(compare_attr(temp, alunos[j], ordem) > 0) {
				idx = j;
				flag = 1;
			}
		}
		
		if(flag) {
			trocar(&alunos[idx], &alunos[i]);
		}
	}
	
	ord_atual = ordem;
}

/* função que particiona a em elementos menores e maiores
ini   --> índex do começo do vetor
fim   --> índex do final do vetor
ordem --> ordem desejada (referência a linha 49)*/
int partition(int ini, int fim, int ordem) {
	aluno pivo;
	pivo = alunos[fim];
	
	while (ini < fim) {
		//while (ini < fim && alunos[ini] <= alunos[pivo]) {
		while (ini < fim && (compare_attr(alunos[ini], pivo, ordem) < 1)) {
			ini++;
		}
		
		//while (ini < fim && alunos[fim] > alunos[pivo]) {
		while (ini < fim && (compare_attr(alunos[fim], pivo, ordem) == 1)) {
			fim--;
		}
		
		trocar(&alunos[ini], &alunos[fim]);
	}
	return ini;
}

/* função que ordena a lista por quick_sort
ini   --> índex do começo do vetor
fim   --> índex do final do vetor
ordem --> ordem desejada (referência a linha 49)*/
void quick_sort(int ini, int fim, int ordem) {
	int pos;
	
	if (ini < fim){
		pos = partition(ini, fim, ordem);
		quick_sort(ini, pos - 1, ordem);
		quick_sort(pos, fim, ordem);
	}
}

/* função que intercala dois vetores
ini   --> índice inicial do primeiro vetor
meio  --> índice do final do primeiro vetor e começo do segundo
fim   --> índice final do segundo vetor
ordem --> ordem desejada (referência a linha 49) */
void merge(int ini, int meio, int fim, int ordem) {
	int i = ini, j = meio + 1, k = 0;
	aluno *aux;
	
	aux = calloc(sizeof(aluno), 1000);
	
	while(i <= meio && j <= fim) {
		if(compare_attr(alunos[i], alunos[j], ordem) == 1) {
			aux[k++] = alunos[j++];
		} else {
			aux[k++] = alunos[i++];
		}
	}
	
	while(i <= meio) {
		aux[k++] = alunos[i++];
	}
	
	while(j <= fim) {
		aux[k++] = alunos[j++];
	}
	
	for(i=0, j=ini; j <= fim; i++, j++) {
		alunos[j] = aux[i];
	}
	
	free(aux);
	
}

/* função que ordena a lista por merge_sort
ini   --> índice inicial do vetor
fim   --> índice final do vetor
ordem --> ordem desejada (referência a linha 49) */
void merge_sort(int ini, int fim, int ordem) {
	if(ini < fim) {
		int meio = (ini + fim) / 2;
		merge_sort(ini, meio, ordem);
		merge_sort(meio+1, fim, ordem);
		merge(ini, meio, fim, ordem);
	}
}

/* função que ordena a lista por insertion_sort
ordem --> ordem desejada (referência a linha 49)*/
void insertion_sort(int ordem) {
	int i, j, k;
	
	for(i = 1; i < qtd_aluno; i++) {
		for(j = 0; j < i; j++) {
			if(compare_attr(alunos[i], alunos[j], ordem) == -1) {
				for(k = j; k < i; k++) {
					trocar(&alunos[k], &alunos[i]);
				}
				break;
			}
		}
		
	}
}

/* função que ordena a lista por selection_sort
ordem --> ordem desejada (referência a linha 49)*/
void selection_sort(int ordem) {
	int i, j, temp;
	
	for(i = 0; i < qtd_aluno; i++) {
		temp = i;
		for(j = i+1; j < qtd_aluno; j++) {
			if(compare_attr(alunos[temp], alunos[j], ordem) == 1) {
				temp = j;
			}
		}
		
		trocar(&alunos[i], &alunos[temp]);
	}
}

// função que lista todos os alunos
void listar_all_alunos() {
	int i, flag;
	
	if(ord_atual != 0) {
		printf("Deseja modificar a ordenação da lista? (1 - sim, 0 - não): ");
		scanf("%d", &flag);
		fflush(stdin);
		
		if(flag){	
			menu_ordernar();
			printf("\n");
		}	
	}
	
	while(ord_atual == 0) {
		menu_ordernar();
		
		if(ord_atual == 0) {
			printf("\nPara listar todos os alunos, é necessário ordená-los.\n");
			printf("Por favor, digite uma opção válida.\n");
		}
	}
	
	for(i = 0; i < qtd_aluno; i++) {
		printf("\n ====== Aluno nro %d ======\n", i+1);
		printf("Nome completo: %s %s\n", alunos[i].nome, alunos[i].sobrenome);
		printf("Data de nascimento: %d/%d/%d\n", alunos[i].nasci.dia, alunos[i].nasci.mes, alunos[i].nasci.ano);
		printf("Prontuário: %d\n", alunos[i].prontuario);
		printf("Curso: %s\n", alunos[i].curso);
	}
}

/* função que compara os atributos de dois alunos
aluno1 --> primeiro aluno a ser comparado
aluno2 --> segundo aluno a ser comparado
attribute --> atributo desejado para comparação (referência a linha 49)
retorno --> -1 caso 2ndo seja maior, 0 caso abos sejam iguais, 1 caso 1ro seja maior */
int compare_attr(aluno aluno1, aluno aluno2, int attribute) {
	int flag, nasci1, nasci2;
	
	switch(attribute) {
		case 1:
			flag = compare_attr(aluno1, aluno2, 6);
			if(flag == 0) {
				flag = compare_attr(aluno1, aluno2, 7);
				if(flag == 0) {
					return 0;
				} else if(flag > 0) {
					return 1;
				} else {
					return -1;
				}
				
			} else if(flag > 0) {
				return 1;
			} else {
				return -1;
			}
			
		case 2:
			flag = compare_attr(aluno1, aluno2, 7);
			if(flag == 0) {
				flag = compare_attr(aluno1, aluno2, 6);
				if(flag == 0) {
					return 0;
				} else if(flag > 0) {
					return 1;
				} else {
					return -1;
				}
			} else if(flag > 0) {
				return 1;
			} else {
				return -1;
			}

		case 3:
			nasci1 = ((aluno1.nasci.ano * 365) + (aluno1.nasci.mes * 30) + aluno1.nasci.dia);
			nasci2 = ((aluno2.nasci.ano * 365) + (aluno2.nasci.mes * 30) + aluno2.nasci.dia);
			if(nasci1 > nasci2) {
				return 1;
			} else if(nasci1 == nasci2) {
				return 0;
			} else {
				return -1;
			}
		
		case 4:
			if(aluno1.prontuario > aluno2.prontuario) {
				return 1;
			} else if (aluno1.prontuario == aluno2.prontuario){
				return 0;
			} else {
				return -1;
			}
			
		case 5:
			flag = strcmp(aluno1.curso, aluno2.curso);
			
			if(flag > 0) {
				return 1;
			} else if(flag == 0) {
				return 0;
			} else {
				return -1;
			}
			
		case 6:
			flag = strcmp(aluno1.nome, aluno2.nome);
			if(flag == 0) {
				return 0;
			} else if(flag > 0) {
				return 1;
			} else {
				return -1;
			}
		
		case 7:
			flag = strcmp(aluno1.sobrenome, aluno2.sobrenome);
			if(flag == 0) {
				return 0;
			} else if(flag > 0) {
				return 1;
			} else {
				return -1;
			}
			
		default:
			printf("Algo deu errado, desculpa\n");
			return 0;
	}
	
}

// função que busca um aluno na lista alunos, decide entre usar busca binária ou linear
void busca_aluno() {
	aluno desejado;
	int opcao, resultado, flag=0;
	
	printf("\n======== BUSCAR ALUNO ========\n");
	printf("Digite uma das opções de busca abaixo: \n");
	printf("[1] - Nome e sobrenome\n");
	printf("[2] - Prontuário\n");
	printf("[0] - Sair da busca\n");
	printf("\n>>> ");
	
	scanf("%d", &opcao);
	fflush(stdin);
	
	switch(opcao) {
		case 1:
			printf("\nDigite o nome do aluno a ser encontrado: ");
			gets(desejado.nome);
			
			printf("Digite o sobrenome do aluno a ser encontrado: ");
			gets(desejado.sobrenome);
			flag = 1;
			break;
		case 2:
			printf("Digite o prontuário do aluno a ser encontrado: ");
			scanf("%d", &desejado.prontuario);
			fflush(stdin);
			opcao = 4; // seta a opção para a variável de acordo com a linha 42
			flag = 1;
			break;
		default:
			printf("Você não digitou uma opção válida.");
			break;
	}
	
	if(flag) {
		if(opcao == ord_atual) {
			resultado = busca_binaria(desejado, opcao);
		} else {
			resultado = busca_linear(desejado, opcao);
		}
		
		if(resultado != -1) {
			printf("\n ====== Aluno encontrado ======\n");
			printf("Nome completo: %s %s\n", alunos[resultado].nome, alunos[resultado].sobrenome);
			printf("Data de nascimento: %d/%d/%d\n", alunos[resultado].nasci.dia, alunos[resultado].nasci.mes, alunos[resultado].nasci.ano);
			printf("Prontuário: %d\n", alunos[resultado].prontuario);
			printf("Curso: %s\n", alunos[resultado].curso);
		} else {
			printf("\nAluno não encontrado.\n");
		}
	}
}

/* função que busca um aluno na lista alunos, de forma binária
desejado --> aluno temporário com o atributo desejado a busca
attribute --> atributo desejado a procura
retorno --> índex do aluno se ele foi encontrado, caso não encontrado, retorna -1 */
int busca_binaria(aluno desejado, int attribute) {
	int inicio, fim, meio, flag, idx=-1;
	
	inicio = 0;
	fim = qtd_aluno - 1;
	meio = (inicio + fim) / 2;
	while(inicio <= fim && flag != 1) {
		
		switch(compare_attr(desejado, alunos[meio], attribute)) {
			case 0:
				idx = meio;
				flag = 1;
				break;
			case 1:
				inicio = meio + 1;
				break;
			case -1:
				fim = meio - 1;
				break;
			default:
				printf("Algo deu errado, desculpa\n");
				break;
		}
		
		meio = (inicio + fim) / 2;
	}
	
	return idx;
}

/* função que busca um aluno na lista alunos, de forma linear
desejado --> aluno temporário com o atributo desejado a busca
attribute --> atributo desejado a procura
retorno --> índex do aluno se ele foi encontrado, caso não encontrado, retorna -1 */
int busca_linear(aluno desejado, int attribute) {
	int idx=-1, i;
	
	for(i=0; i<qtd_aluno; i++) {
		if(compare_attr(desejado, alunos[i], attribute) == 0) {
			idx = i;
			break;
		}
	}
	
	return idx;
}

/* função que retorna um aluno com o atributo desejado
attribute --> atributo desejado (ref a linha 49)
retorno --> um aluno temporário com um único atributo definido */
aluno criar_aluno_desejado(int attribute) {
	aluno result;
	
	switch(attribute) {
		case 1:
		
		case 2:
			printf("\nDigite o nome do aluno a ser removido: ");
			gets(result.nome);
			
			printf("Digite o sobrenome do aluno a ser removido: ");
			gets(result.sobrenome);
			break;
		
		case 3:
			result.nasci = get_date();
			break;
		
		case 4:
			printf("\nDigite o prontuário do aluno a ser removido: ");
			scanf("%d", &result.prontuario);
			fflush(stdin);
			break;
		
		case 5:	
			printf("Digite o curso do aluno a ser removido: ");
			gets(result.curso);
			break;
		
		case 6:
			printf("\nDigite o nome do aluno a ser removido: ");
			gets(result.nome);
			break;
		
		case 7:
			printf("Digite o sobrenome do aluno a ser removido: ");
			gets(result.sobrenome);
			break;
		
		case 0:
			break;
		
		default:
			printf("Algo deu errado, desculpa.\n");
	}
	
	return result;
}

// função que remove um aluno da lista de alunos
void remover_aluno() {
	aluno desejado;
	int opcao, idx=-1, flag, cont_deletados;
	
	printf("\n======== REMOVER ALUNO ========\n");
	printf("Digite uma das opções de remoção abaixo: \n");
	printf("[1] - Nome e sobrenome\n");
	printf("[2] - Sobrenome e nome\n");
	printf("[3] - Data de nascimento\n");
	printf("[4] - Prontuário\n");
	printf("[5] - Curso\n");
	printf("[6] - Nome\n");
	printf("[7] - Sobrenome\n");
	printf("[0] - Sair da remoção\n");
	printf("\n>>> ");
	
	scanf("%d", &opcao);
	fflush(stdin);
	
	if(opcao != 0) {
	   	desejado = criar_aluno_desejado(opcao);
	   	flag = 1;
	   	cont_deletados = 0;
		   
		while(flag) {
		   	if(opcao == ord_atual) {
				idx = busca_binaria(desejado, opcao);
			} else {
				idx = busca_linear(desejado, opcao);
			}
			
			if(idx == -1) {
				flag = 0;
			} else {
				qtd_aluno--;
				cont_deletados++;
				alunos[idx] = alunos[qtd_aluno];
				ordernar_lista(ord_atual);
			}
			
		}

		if(cont_deletados != 0) {
			printf("%d alunos removidos com sucesso.", cont_deletados);
		} else {
			printf("\nNenhum aluno com esses parâmetros encontrado\n");
		}
	}
}

// lista todos os alunos de acordo com algum parâmetro
void listar_alunos() {
	int opcao, i, cont=1;
	aluno desejado;
	
	printf("\n======== LISTAR ALUNOS ========\n");
	printf("Digite uma das opções de lista seletiva abaixo: \n");
	printf("[1] - Nome e sobrenome\n");
	printf("[2] - Sobrenome e nome\n");
	printf("[3] - Data de nascimento\n");
	printf("[4] - Prontuário\n");
	printf("[5] - Curso\n");
	printf("[6] - Nome\n");
	printf("[7] - Sobrenome\n");
	printf("[0] - Sair da lista por parâmetro\n");
	printf("\n>>> ");
	
	scanf("%d", &opcao);
	fflush(stdin);
	
	if(opcao != 0) {
		desejado = criar_aluno_desejado(opcao);
		
		for(i = 0; i < qtd_aluno; i++) {
			if(compare_attr(desejado, alunos[i], opcao) == 0) {
				printf("\n ====== Aluno nro %d ======\n", cont);
				printf("Nome completo: %s %s\n", alunos[i].nome, alunos[i].sobrenome);
				printf("Data de nascimento: %d/%d/%d\n", alunos[i].nasci.dia, alunos[i].nasci.mes, alunos[i].nasci.ano);
				printf("Prontuário: %d\n", alunos[i].prontuario);
				printf("Curso: %s\n", alunos[i].curso);
				
				cont++;
			}
		}
		
		if(cont == 1){
			printf("Nenhum aluno com esses parâmetros foi encontrado.");
		}
	}
}

// função para carregar alunos de um arquivo
void carregar_alunos() {
	FILE *arquivo;
	
	arquivo = fopen("alunos.bin", "rb");
	
	if(arquivo != 0) {
		fread(&qtd_aluno, sizeof(int), 1, arquivo);
		fread(&alunos, sizeof(aluno), qtd_aluno, arquivo);
		
		fclose(arquivo);
		
		ord_atual = 0;
		
		printf("%d alunos carregados com sucesso.", qtd_aluno);
	} else {
		printf("Ocorreu algum erro no carregamento de alunos.\n");
		printf("Cheque se algum aluno já foi salvo anteriormente.");
	}
}

// função para salvar alunos num arquivo
void salvar_alunos() {
	FILE *arquivo;
	
	arquivo = fopen("alunos.bin", "wb");
	if(arquivo != 0) {
		fwrite(&qtd_aluno, sizeof(int), 1, arquivo);
		fwrite(&alunos, sizeof(aluno), qtd_aluno, arquivo);
		
		fclose(arquivo);
		
		printf("Alunos salvos com sucesso.");
	} else {
		printf("Ocorreu um erro na criação do arquivo.");
	}
}
