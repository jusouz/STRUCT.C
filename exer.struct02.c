#include<stdio.h>
#include <string.h>
	
typedef struct livro_t{ //tipo de dado
	char titulo [30];
	char autor [15];
	int ano;
	int prateleira;
}livro;//definicao da struct
int qtd = 0;

void CadastrarLivro(livro l[]) {
	printf("Nome da livro:");
	fflush(stdin);// limpa o buffer do teclado
	gets(l[qtd].titulo);
	printf("Autor:");
	fflush(stdin);// limpa o buffer do teclado
	gets(l[qtd].autor);
	printf("Ano:");
	scanf("%d",&l[qtd].ano);
	printf("Prateleira:");
	scanf("%d",&l[qtd].prateleira);
	qtd++;
}

void BuscaLivros(livro l[], char tituloBusca[]){
	int i;
	char tituloAux[30];
	for(i=0;i<qtd;i++){
		strcpy(tituloAux,l[i].titulo); // copiando do vetor para aux
		strupr(tituloAux);// uppercase
		if(strcmp(tituloBusca,tituloAux)==0){
			printf("** livro %d **\n",i+1);
			printf("titulo:%s\n",l[i].titulo);
			printf("autor:%s\n",l[i].autor);
			printf("ano:%d\n",l[i].ano);
			printf("prateleira:%d\n",l[i].prateleira);
			printf("------------------------\n");
		}// fim if
	}// fim for
}

void BuscaAno(livro l[], int ano){
	int i;
	for(i=0;i<qtd;i++){
		if(ano<l[i].ano){
			printf("** livro %d **\n",i+1);
			printf("titulo:%s\n",l[i].titulo);
			printf("autor:%s\n",l[i].autor);
			printf("ano:%d\n",l[i].ano);
			printf("prateleira:%d\n",l[i].prateleira);
			printf("------------------------\n");
		}// fim if
	}// fim for
}
void ListaLivros(livro l[]){
	int i;
	for(i=0;i<qtd;i++){
		printf("** livro %d **\n",i+1);
		printf("titulo:%s\n",l[i].titulo);
		printf("autor:%s\n",l[i].autor);
		printf("ano:%d\n",l[i].ano);
		printf("prateleira:%d\n",l[i].prateleira);
		printf("------------------------\n");
	}// fim for
}
int menu(){
	int opcao;
	printf("*** Sistema de Cadastro de Livros ***\n");
	printf("1- Cadastrar\n");
	printf("2- Listar\n");
	printf("3- Filtro por nome\n");
	printf("4- Filtro por ano mais novo\n");
	printf("0 - Sair\n");
	scanf("%d",&opcao);
	return opcao;
}// fim menu
//------------------

int main (void){
	livro livros[100];
	int opcao, buscaAno;
	char nomeBusca[30];
	do{
		opcao= menu();
		switch(opcao){
			case 1:  CadastrarLivro(livros);
			 break;
			case 2: ListaLivros(livros);
			 break;
			case 3: printf("Filtro nome:");
					scanf("%s",&nomeBusca);
					strupr(nomeBusca);
					BuscaLivros(livros,nomeBusca);
			 break;
			case 4: printf("Ano:");
					fflush(stdin);//limpa buffer
					scanf("%d",&buscaAno);
					BuscaAno(livros,buscaAno);
			 break;
			case 0: printf("Saindo...\n");
			default: printf("Opcao invalida\n");  
		}// fim switch
	  getch(); // pausa
	  system("cls"); // limpa tela	
	}while(opcao!=0);
	return 0;
	
}
