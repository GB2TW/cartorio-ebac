#include <stdio.h> // biblioteca de comunica��o com o usuario 
#include <stdlib.h> // biblioteca de aloca��o de espa�o em memoria 
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca responsavel pelas strings

int registro() //fun��o responsavel por cadastrar usarios no sistema
{
	//inicio cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/strings
	
	printf("digite o CPF a ser cadastrado: ");// coletando informa��es do usuario 
	scanf("%s", cpf); //"%s" se refere as strings
	
	strcpy(arquivo , cpf); //responsavel por copiar os valores das strings
	
	FILE *file;//cria um arquivo
	file = fopen(arquivo, "w");// "w" cria um arquivo
	fprintf(file,"\nCPF: ");
	fprintf(file,cpf);//salva o valor da variavel cpf
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");//"a" atualiza informa�oes no arquivo criado 
	fprintf(file, " \nNOME: ");
	fclose(file);
	
	printf(" digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," \nSOBRENOME: ");
	fclose(file);
	
	printf(" digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," \nCARGO: ");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file);
	
	system("pause");
	
}
int consutar()
{
	setlocale(LC_ALL, "portuguese");// definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s", cpf);//l� a string cpf
	
	FILE *file;
	file = fopen(cpf, "r");// abre e le as informa��es na pasta cpf
	
	if(file == NULL)// se n�o encontrar o cpf
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}

	printf("\nEssas s�o as informa��es do usuario:\n");// se encontrar o cpf
	
	while (fgets( conteudo, 200, file) != NULL)// busca e mostra as informa��es de dentro da pasta
	{
		printf("%s" , conteudo);
	}
	system ("pause");
}
int deletar()
{
	char cpf[40];
	
	printf("digite o cpf do usuario a ser deletado: ");
	scanf("%s", cpf);
	
	system("cls");//limpando a vis�o do usuario para uma menssagem clara
	
	FILE *file;
	file = fopen(cpf, "r");//abre l� as informa��es da pasta depois a fecha 
	fclose(file);
	
	if(file == NULL)// se n�o encrota o cpf
	{
		printf("\n o usuario n�o se encontra no sistema\n\n");
		system("pause");
	}
	
	remove (cpf);// remove o cpf usando o comando "se"
	
	if(file != NULL)
	{
	
		printf("\n usuario deletado com sucesso\n\n");
		system("pause");
	}
}
int main() //INICIO DO PROGRAMA!!!
{	
	int opcao=0;// referenciando numero de variavel
	int laco=1;
	
	for(laco=1;laco=1;)//come�o do laco(for)
	{
	
		system("cls");

		setlocale(LC_ALL, "portuguese");// definindo linguagem 
	
		printf("<3 Cartorio da EBAC <3\n\n");// inicio do menu
		printf("Escolha a op��o desejada no menu abaixo:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");//final do menu
		printf("op��o:");
	
		scanf("%d" , &opcao); // armazenando a escolha do usuario
	
		system("cls"); // limpeza da tela
	
	switch(opcao) //inicio de sele��o do menu
	 	{ 
	 	case 1:
		registro(); //chamada de fun��es
		break;
		
		case 2:
		consutar();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("este comando n�o esta disponivel\n");
		system("pause");
		break;
		}
	}//fim da sele��o
		
}
