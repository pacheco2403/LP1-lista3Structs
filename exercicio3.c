#include <stdio.h>
#include <string.h>
typedef struct{
	char nome[40];
	int primeiraprova;
	int segundaprova;
	int terceiraprova;
}tAlunos;
int qtd=0; 
//-------------------------
void addAluno(tAlunos a[100]){
	
	printf("Nome do aluno:");
	fflush(stdin);// limpa o buffer do teclado
    	gets(a[qtd].nome);
	printf("Nota1:");
	fflush(stdin);
     	scanf("%d",&a[qtd].primeiraprova);
	printf("Nota2:");
	fflush(stdin);
    	scanf("%d",&a[qtd].segundaprova);
	printf("Nota3:");
	fflush(stdin);
    	scanf("%d",&a[qtd].terceiraprova);
	qtd++;
}
//--------------------------

void salvaArquivo(tAlunos aluno[]){
	FILE *arq;
	int i=0;
	arq=fopen("dadosAlunos.txt","wb");
	fwrite(&aluno[i],sizeof(tAlunos),qtd,arq);
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}

void carregaArquivo(tAlunos aluno[]){
	FILE *arq;
	arq=fopen("dadosAlunos.txt","rb");
	if(arq==NULL){
	  printf("Arquivo nao encontrado :(\n");
	  return;
	  }// fim if
	 while(fread(&aluno[qtd],sizeof(tAlunos),1,arq) >0 )
	      qtd++;  
	 printf("Dados carregados com sucesso !\n");
	fclose(arq);
}

//--------------------------

int menu(){
	int opcao;
	printf("*** Sistema de Cadastro de Alunos ***\n");
	printf("1- Cadastrar alunos\n");
	printf("0- Saindo...\n");
	scanf("%d",&opcao);
	return opcao;
}

//--------------------------

int main(){
	tAlunos aluno[100];
	int opcao,res, anoBusca;
	char generoBusca[40], nomeBusca[40];
	carregaArquivo(aluno);
	do{
		opcao= menu();
		switch(opcao){
			case 1: addAluno(aluno);
			break;
			case 0: printf("Saindo...\n");
					salvaArquivo(aluno);
			 break;
			default: printf("Opcao invalida\n");  
		}
			getch(); 
	  	system("cls"); 
	
	}while(opcao!=0);
return 0;
}
			
			
			
			
			
			
			


