#include <stdio.h>
#include <string.h>
typedef struct data_t{
	int dia;
	int mes;
	int ano;
}data;

typedef struct emprestimo_t{ //tipo de dado
	data dt;
	char nome[30];
    char emprestado;
}emprestimo;//definicao da struct

typedef struct jogos_t{ //tipo de dado
	char titulo[30];
    char console[15];
    int ranking;
    emprestimo emp;
}jogo;//definicao da struct
int qtd = 0;

void CadastrarJogo (jogo j[]) {
	printf("titulo do jogo:\n");
	scanf("%s",&j[qtd].titulo);
	printf("console:\n");
	scanf("%s",&j[qtd].console);
	printf("ranking:\n");
	scanf("%d",&j[qtd].ranking);
	j[qtd].emp.emprestado = 'N';
	qtd++;
}
void EmprestarJogo (jogo j[], int posicao){
	printf("Emprestimo:\n");
		printf("\b Nome:\n");
		scanf("%s",&j[posicao].emp.nome);
		printf("\b Data (dia):\n\b");
		scanf("%d",&j[posicao].emp.dt.dia);
		printf("\b Data (mes):\n\b");
		scanf("%d",&j[posicao].emp.dt.mes);
		printf("\b Data (ano):\n\b");
		scanf("%d",&j[posicao].emp.dt.ano);
	j[posicao].emp.emprestado = 'S';
}
void DevolverJogo (jogo j[], int posicao){
	strcpy(j[posicao].emp.nome, "\0");
	j[posicao].emp.dt.dia = 0;
	j[posicao].emp.dt.mes = 0;
	j[posicao].emp.dt.ano = 0;
	j[posicao].emp.emprestado = 'N';
}
void ListaJogos(jogo j[], char consoleBusca[]){
	int i;
	char consoleAux[15];
	for(i=0;i<qtd;i++){
		strcpy(consoleAux,j[i].console); // copiando do vetor para aux
		strupr(consoleAux);// uppercase
		if (strcmp(consoleBusca, consoleAux) == 0){
			printf("** jogo %d **\n",i);
			printf("titulo do jogo:");
			printf("%s\n",j[i].titulo);
			printf("console:\n");
			printf("%s\n",j[i].console);
			printf("ranking:");
			printf("%d\n",j[i].ranking);
			printf("Emprestado: %c\n", j[i].emp.emprestado);
			printf("------------------------\n");
		}
	}// fim for
}
void BuscaTitulo (jogo j[], char tituloBusca[]){
	int i;
	char tituloAux[30];
	for(i=0;i<qtd;i++){
		strcpy(tituloAux,j[i].titulo); // copiando do vetor para aux
		strupr(tituloAux);// uppercase
		if(strcmp(tituloAux, tituloBusca) == 0){
			printf("** jogo %d **\n",i);
			printf("titulo do jogo:");
			printf("%s\n",j[i].titulo);
			printf("console:\n");
			printf("%s\n",j[i].console);
			printf("ranking:");
			printf("%d\n",j[i].ranking);
			printf("Emprestado: %c\n", j[i].emp.emprestado);
			printf("------------------------\n");
		}// fim if
	}// fim for
}
void ListaEmprestimo (jogo j[]){
	int i;
	for(i=0;i<qtd;i++){
		if(j[i].emp.emprestado == 'S'){
			printf("** jogo %d **\n",i);
			printf("titulo do jogo:");
			printf("%s\n",j[i].titulo);
			printf("console:\n");
			printf("%s\n",j[i].console);
			printf("ranking:");
			printf("%d\n",j[i].ranking);
			printf("Emprestado para: %s\n", j[i].emp.nome);
			printf("------------------------\n");
		}// fim if
	}// fim for
}
int menu(){
	int opcao;
	printf("*** Sistema de Cadastro de Emprestimos ***\n");
	printf("1- Cadastrar\n");
	printf("2- Listar por console\n");
	printf("3- Filtro por nome\n");
	printf("4- Busca emprestimos\n");
	printf("5- Cadastrar emprestimo\n");
	printf("6- Cadastrar devolucao\n");
	printf("0 - Sair\n");
	fflush(stdin);
	scanf("%d",&opcao);
	return opcao;
}// fim menu

int main (void){
	jogo jogos[100];
	int opcao;
	char tituloBusca[30];
	do{
		opcao= menu();
		switch(opcao){
			case 1:  CadastrarJogo(jogos);
			 break;
			case 2: printf("Listar por console:\n");
				scanf("%s",&tituloBusca);
				strupr(tituloBusca);
				ListaJogos(jogos, tituloBusca);
			 break;
			case 3: printf("Filtro titulo:\n");
				scanf("%s",&tituloBusca);
				strupr(tituloBusca);
				BuscaTitulo(jogos, tituloBusca);
			 break;
			case 4: printf("Busca emprestimos:");
				ListaEmprestimo(jogos);
			 break;
			case 5: printf("Cadastrar emprestimo:\n");
			{
				int pos = 0;
				printf("Posicao:");
				scanf("%d", &pos);
				EmprestarJogo(jogos, pos);
			};
			 break;
			case 6: 
			{
				printf("Cadastrar devolucao:\n");
				int pos = 0;
				printf("Posicao:");
				scanf("%d", &pos);
				DevolverJogo(jogos, pos);
			}
			 break;
			case 0: printf("Saindo...\n");
			 break;
			default: printf("Opcao invalida\n");  
		}// fim switch
	  getch(); // pausa
	  system("cls"); // limpa tela	
	}while(opcao!=0);
	return 0;
	
} //fim menu
