#include <stdio.h>
#include <string.h>
typedef struct{
	int matricula;
	char nome[30];
	float nota01;
	float nota02;
	float nota03;
	int aprovado;
}aluno;
int qtd=0; // controlar a posicao de cadastro no vetor

//---------------------------

void CadastrarAluno(aluno a[]) {
	printf("Nome da aluno:");
	fflush(stdin);// limpa o buffer do teclado
	gets(a[qtd].nome);
	printf("Matricula:");
	fflush(stdin);// limpa o buffer do teclado
	scanf("%d",&a[qtd].matricula);
	printf("Nota 1:");
	scanf("%f",&a[qtd].nota01);
	printf("Nota 2:");
	scanf("%f",&a[qtd].nota02);
	printf("Nota 3:");
	scanf("%f",&a[qtd].nota03);
	if (a[qtd].nota01+a[qtd].nota02+a[qtd].nota03 >= 18) a[qtd].aprovado = 1;
	else a[qtd].aprovado = 0;
	qtd++;
}

void BuscaNome(aluno a[], char nomeBusca[]){
	int i;
	char nomeAux[30];
	for(i=0;i<qtd;i++){
		strcpy(nomeAux,a[i].nome); // copiando do vetor para aux
		strupr(nomeAux);// uppercase
		if(strcmp(nomeBusca,nomeAux)==0){
				printf("** aluno %d **\n",i+1);
			printf("Nome da aluno:");
			printf("%s\n",a[i].nome);
			printf("Matricula:\n");
			printf("%d\n",a[i].matricula);
			printf("Nota 1:\n");
			printf("%f\n",a[i].nota01);
			printf("Nota 2:\n");
			printf("%f\n",a[i].nota02);
			printf("Nota 3:\n");
			printf("%f\n",a[i].nota03);
			printf("Aprovado: %s\n", a[i].aprovado == 1 ? "Sim" : "Nao");
			printf("------------------------\n");
		}// fim if
	}// fim for
}

void BuscaMatricula(aluno a[], int matricula){
	int i;
	for(i=0;i<qtd;i++){
		if(matricula==a[i].matricula){
			printf("** aluno %d **\n",i+1);
			printf("Nome da aluno:");
			printf("%s\n",a[i].nome);
			printf("Matricula:\n");
			printf("%d\n",a[i].matricula);
			printf("Nota 1:\n");
			printf("%f\n",a[qtd].nota01);
			printf("Nota 2:\n");
			printf("%f\n",a[i].nota02);
			printf("Nota 3:\n");
			printf("%f\n",a[i].nota03);
			printf("Aprovado: %s\n", a[i].aprovado == 1 ? "Sim" : "Nao");
			printf("------------------------\n");
		}// fim if
	}// fim for
}
void BuscaMaiorMedia(aluno a[]){
	int i;
	int posAux=0;
	for(i=0;i<qtd;i++){
		if(a[posAux].nota01+a[posAux].nota02+a[posAux].nota03 < a[i].nota01+a[i].nota02+a[i].nota03){
			posAux = i;
		}// fim if
	}// fim for
}
	
void ListaAlunos(aluno a[]){
	int i;
	for(i=0;i<qtd;i++){
		printf("** aluno %d **\n",i+1);
		printf("Nome da aluno:");
		printf("%s\n",a[i].nome);
		printf("Matricula:\n");
		printf("%d\n",a[i].matricula);
		printf("Nota 1:\n");
		printf("%f\n",a[i].nota01);
		printf("Nota 2:");
		printf("%f\n",a[i].nota02);
		printf("Nota 3:\n");
		printf("%f\n",a[i].nota03);
		printf("Aprovado: %s\n", a[i].aprovado == 1 ? "Sim" : "Nao");
			
		printf("------------------------\n");
	}// fim for
}

void salvaArquivo(aluno alunos[]){
	FILE *arq;
	int i=0;
	arq=fopen("dadosAlunos.txt","wb");
	fwrite(&alunos[i],sizeof(aluno),qtd,arq);
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}
//-----------------------------
void carregaArquivo(aluno jogos[]){
	FILE *arq;
	arq=fopen("dadosAlunos.txt","rb");
	if(arq==NULL){
	  printf("Arquivo nao encontrado :(\n");
	  return;
	  }// fim if
	 while(fread(&alunos[qtd],sizeof(aluno),1,arq) >0 )
	      qtd++;  
	 printf("Dados carregados com sucesso !\n");
	fclose(arq);
}
int menu(){
	int opcao;
	printf("*** Sistema de Cadastro de Alunos ***\n");
	printf("1- Cadastrar\n");
	printf("2- Listar\n");
	printf("3- Filtro por nome\n");
	printf("4- Filtro por matricula\n");
	printf("5- Filtro por maior media\n");
	printf("0 - Sair\n");
	fflush(stdin);
	scanf("%d",&opcao);
	return opcao;
}// fim menu
//------------------

int main (void){
	aluno alunos[100];
	int opcao, buscaMatricula;
	carregaArquivo(alunos);
	char nomeBusca[30];
	do{
		opcao= menu();
		switch(opcao){
			case 1:  CadastrarAluno(alunos);
			 break;
			case 2: ListaAlunos(alunos);
			 break;
			case 3: printf("Filtro nome:");
				scanf("%s",&nomeBusca);
				strupr(nomeBusca);
				BuscaNome(alunos,nomeBusca);
			 break;
			case 4: printf("Filtro matricula:");
				scanf("%d",&buscaMatricula);
				BuscaMatricula(alunos,buscaMatricula);
			 break;
			case 5: printf("Busca maior media:");
				BuscaMaiorMedia(alunos);
			 break;	
			case 0: printf("Saindo...\n");
				salvaArquivo(alunos);
			 break;
			default: printf("Opcao invalida\n");  
		}// fim switch
	  getch(); // pausa
	  system("cls"); // limpa tela	
	}while(opcao!=0);
	return 0;
	
} //fim menu

