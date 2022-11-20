#include <stdio.h>
#include <string.h>
typedef struct data_t{
	int mes;
	int ano;
}data;
typedef struct gado_t{
	int codigo;
	int leite;
	int alim;
	data nasc;
	char abate;
}gado;
data dataAtual;
int qtd=0; // controlar a posicao de cadastro no vetor
int obterIdade (data inicial, data final){
	int result;
	result = final.ano - inicial.ano;
	if(final.mes < inicial.mes)	result--;
	return result;
};
void CadastrarGado (gado j[]) {
	printf("Codigo:\n");
	scanf("%d",&j[qtd].codigo);
	printf("Leite:\n");
	scanf("%d",&j[qtd].leite);
	printf("Alimento:\n");
	scanf("%d",&j[qtd].alim);
	printf("Data de nascimento:\n");
	
	printf("\b Data (mes):\n\b");
	scanf("%d", &j[qtd].nasc.mes);
	printf("\b Data (ano):\n\b");
	scanf("%d", &j[qtd].nasc.ano);
	
	if(obterIdade(j[qtd].nasc, dataAtual)>5 || j[qtd].leite < 40) j[qtd].abate = 'S';
	else j[qtd].abate = 'N';
	qtd++;
}
void ListaGado(gado g[]){
	int i, alimentoSemanal = 0, producaoSemanal = 0;
	for(i=0;i<qtd;i++){
		printf("** gado %d **\n",i+1);
		printf("codigo do gado:");
		printf("%d\n",g[i].codigo);
		printf("leite:\n");
		printf("%d\n",g[i].leite);
		printf("alim:\n");
		printf("%d\n",g[i].alim);
		printf("nasc:");
		printf("%d/%d\n",g[i].nasc.mes, g[i].nasc.ano);
		printf("abate:\n");
		printf("%c\n",g[i].abate);
		printf("------------------------\n");
		alimentoSemanal+=g[i].alim;
		producaoSemanal+=g[i].leite;
	}// fim for
	printf("Alimento Semanal (kg): %d\n", alimentoSemanal);
	printf("Producao Semanal (litros): %d\n", producaoSemanal);
}
void ListaAbate(gado g[]){
	int i;
	for(i=0;i<qtd;i++){
		if(g[i].abate == 'S'){
			printf("** gado %d **\n",i+1);
			printf("codigo do gado:");
			printf("%d\n",g[i].codigo);
			printf("leite:\n");
			printf("%d\n",g[i].leite);
			printf("alim:\n");
			printf("%d\n",g[i].alim);
			printf("nasc:");
			printf("%d/%d\n",g[i].nasc.mes, g[i].nasc.ano);

			printf("------------------------\n");
		}// fim if
	}// fim for
}
void salvaArquivo(gado gados[]){
	FILE *arq;
	int i=0;
	arq=fopen("dadosGados.txt","wb");
	fwrite(&gados[i],sizeof(gado),qtd,arq);
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}
void carregaArquivo(gado gados[]){
	FILE *arq;
	arq=fopen("dadosGados.txt","rb");
	if(arq==NULL){
	  printf("Arquivo nao encontrado :(\n");
	  return;
	}// fim if
	while(fread(&gados[qtd],sizeof(gado),1,arq) >0 )
	    qtd++;  
	printf("Dados carregados com sucesso !\n");
	fclose(arq);
}
int menu(){
	int opcao;
	printf("*** Sistema de Cadastro de cabecas de gado ***\n");
	printf("1- Cadastrar\n");
	printf("2- Listar animais\n");
	printf("3- Listar abate\n");
	printf("4- Salvar\n");
	printf("0 - Sair\n");
	scanf("%d",&opcao);
	return opcao;
}// fim menu

int main (void){
	printf("Data atual:");
	printf("\b Data (mes):\n\b");
	scanf("%d", &dataAtual.mes);
	printf("\b Data (ano):\n\b");
	scanf("%d", &dataAtual.ano);
	
	gado gados[100];
	int opcao, buscaGado;
	carregaArquivo(gados);
	char codigoBusca[30];
	do{
		opcao= menu();
		switch(opcao){
			case 1:  CadastrarGado(gados);
			 break;
			case 2: ListaGado(gados);
			 break;
			case 3: printf("Animais para abate:\n");
				ListaAbate(gados);
			 break;
			 case 4: printf("Salvando...\n");
				salvaArquivo(gados);
			 break;
			case 0: printf("Saindo...\n");
				salvaArquivo(gados);
			 break;
			default: printf("Opcao invalida\n");  
		}// fim switch
	  getch(); // pausa
	  system("cls"); // limpa tela	
	}while(opcao!=0);
	return 0;
	
} //fim menu
