#include <stdio.h>
#include <string.h>

typedef struct{

	char titulo[30];    
	char autor[15];
	int ano;
	int prateleira;

}tlivro;
int qtd=0;

void addLivro(tlivro l[]){
	printf("Titulo do Livro: ");
	fflush(stdin);// limpa o buffer do teclado
	gets(l[qtd].titulo);
	printf("Autor: ");
	fflush(stdin);// limpa o buffer do teclado
	gets(l[qtd].autor);
	printf("Ano de lancamento: ");
	scanf("%d",&l[qtd].ano);
	printf("Prateleira: ");
	scanf("%d",&l[qtd].prateleira);
	qtd++;
}

void listaLivros(tlivro l[]){
	int i;
	for(i=0;i<qtd;i++){
		printf("** Livros %d **\n",i+1);
		printf("Titulo:%s\n",l[i].titulo);
		printf("Autor:%s\n",l[i].autor);
		printf("Ano:%d\n",l[i].ano);
		printf("Prateleira:%d\n",l[i].prateleira);
		printf("------------------------\n");
	}
}

int listaAno(tlivro l[], int anodeConsulta){
	int i, res = -1;
	for(i=0;i<qtd;i++){
	if(l[i].ano >= anodeConsulta)
		{
			printf("* Livro %d *\n", i + 1);
			printf("Titulo: %s\n", l[i].titulo);
			printf("Nome do autor: %s\n", l[i].autor);
			printf("Ano de publicacao: %d\n", l[i].ano);
			printf("Prateleira: %d\n", l[i].prateleira);
			printf("------------------------\n");
			res = 0;
		}
	}
	
	return res;
}
	

int menu(){
	int opcao;
	printf("*** Sistema de Cadastro de Livros ***\n");
	printf("1- Cadastrar livro\n");
	printf("2- Listar livros\n");
	printf("3- Listar por ano\n");
	scanf("%d",&opcao);
	return opcao;
}

int main(){
	tlivro livro[100];
	int opcao,res, anoBusca;
	char generoBusca[40], nomeBusca[40];
	
	do{
		opcao= menu();
		switch(opcao){
			case 1: addLivro(livro);
			break;
			case 2: listaLivros(livro);
			break;
			case 3: printf("Insira o ano da publicacao: ");
				scanf("%d", &anoBusca);
				res = listaAno(livro, anoBusca);
				if(res == -1)
				{
					printf("Nao existem livros desse ano...");
				}
				break;
		}
		getch(); 
	  	system("cls"); 
	}while(opcao!=0);
	return 0;
}



