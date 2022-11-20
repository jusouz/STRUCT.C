#include <stdio.h>
#include <string.h>
typedef struct eletrodomestico_t{ //tipo de dado
	char nome[30];
    float potencial;
    float tempoAtivo;
}eletrodomestico;//definicao da struct
int qtd = 0;
float precoKW = 0;
void CadastrarEletrodomestico(eletrodomestico e[]) {
	printf("Nome da Eletrodomestico:");
	fflush(stdin);// limpa o buffer do teclado
	gets(e[qtd].nome);
	printf("Potencial:");
	fflush(stdin);// limpa o buffer do teclado
	scanf("%f",&e[qtd].potencial);
	printf("Tempo Ativo:");
	scanf("%f",&e[qtd].tempoAtivo);
	qtd++;
}
void ListaEletrodomestico(eletrodomestico e[]){
	int i;
	float consumoDiario = 0;
	for(i=0;i<qtd;i++){
		printf("** eletrodomestico %d **\n",i+1);
		printf("Nome de Eletrodomestico:");
		printf("%s\n",e[i].nome);
		printf("Potencial:\n");
		printf("%f\n",e[i].potencial);
		printf("Tempo Ativo:\n");
		printf("%f h\n",e[i].tempoAtivo);	
		consumoDiario += e[i].potencial*e[i].tempoAtivo;
		printf("------------------------\n");
	}// fim for
	printf("Gasto diario (kW/h - R$): %f kW/h - %f R$\n", consumoDiario, consumoDiario * precoKW);
	printf("Gasto mensal (kW/h - R$): %f kW/h - %f R$\n", consumoDiario * 30, consumoDiario * 30 * precoKW);
}
void salvaArquivo(eletrodomestico e[]){
	FILE *arq;
	int i=0;
	arq=fopen("dadosEletrodomestico.txt","wb");
	fwrite(&e[i],sizeof(eletrodomestico),qtd,arq);
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}
void carregaArquivo(eletrodomestico e[]){
	FILE *arq;
	arq=fopen("dadosEletrodomestico.txt","rb");
	if(arq==NULL){
	  printf("Arquivo nao encontrado :(\n");
	  return;
	  }// fim if
	 while(fread(&e[qtd],sizeof(eletrodomestico),1,arq) >0 )
	      qtd++;  
	 printf("Dados carregados com sucesso !\n");
	fclose(arq);
}
void BuscaNome(eletrodomestico e[], char nomeBusca[]){
	int i;
	char nomeAux[30];
	for(i=0;i<qtd;i++){
		strcpy(nomeAux,e[i].nome); // copiando do vetor para aux
		strupr(nomeAux);// uppercase
		if(strcmp(nomeBusca,nomeAux)==0){
			printf("** Eletrodomestico %d **\n",i+1);
			printf("Nome do Eletrodomestico:");
			printf("%s\n",e[i].nome);
			printf("Potencial:\n");
			printf("%f\n",e[i].potencial);
			printf("Tempo Ativo:\n");
			printf("%f h\n",e[i].tempoAtivo);
			printf("------------------------\n");
		}// fim if
	}// fim for
}
void BuscaConsumoDiario(eletrodomestico e[], float potencialBusca){
	int i;
	int posAux=0;
	for(i=0;i<qtd;i++){
		if(e[posAux].potencial > potencialBusca){
			printf("** Eletrodomestico %d **\n",i+1);
			printf("Nome do Eletrodomestico:");
			printf("%s\n",e[i].nome);
			printf("Potencial:\n");
			printf("%f\n",e[i].potencial);
			printf("Tempo Ativo:\n");
			printf("%f h\n",e[i].tempoAtivo);
			printf("------------------------\n");
		}// fim if
	}// fim for
}

int menu(){
	int opcao;
	printf("*** Sistema de Cadastro de Eletrodomesticos ***\n");
	printf("1- Cadastrar\n");
	printf("2- Listar\n");
	printf("3- Filtro por nome\n");
	printf("4- Filtro por gasto (maior que um valor)\n");
	printf("5- Salvar\n");
	printf("0 - Sair\n");
	fflush(stdin);
	scanf("%d",&opcao);
	return opcao;
}// fim menu

int main (void){
	eletrodomestico eletrodomestico[100];
	int opcao;
	float buscaGasto;
	carregaArquivo(eletrodomestico);
	printf("Preco do kiloWatt:");
	scanf("%f",&precoKW);
	char nomeBusca[30];
	do{
		opcao= menu();
		switch(opcao){
			case 1: CadastrarEletrodomestico(eletrodomestico);
			 break;
			case 2: ListaEletrodomestico(eletrodomestico);
			 break;
			case 3: printf("Filtro nome:");
				scanf("%s",&nomeBusca);
				strupr(nomeBusca);
				BuscaNome(eletrodomestico,nomeBusca);
			 break;
			case 4: printf("Filtro por gasto (maior que um valor):");
				scanf("%f",&buscaGasto);
				BuscaConsumoDiario(eletrodomestico,buscaGasto);
			 break;
			case 5: printf("Salvando...\n");
				salvaArquivo(eletrodomestico);
			 break;	
			case 0: printf("Saindo...\n");
				salvaArquivo(eletrodomestico);
			 break;
			default: printf("Opcao invalida\n");  
		}// fim switch
	  getch(); // pausa
	  system("cls"); // limpa tela	
	}while(opcao!=0);
	return 0;
	
} //fim menu
