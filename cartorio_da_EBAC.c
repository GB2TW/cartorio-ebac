#include <stdio.h> // biblioteca de comunicação com o usuario 
#include <stdlib.h> // biblioteca de alocação de espaço em memoria 
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsavel pelas strings

int registro() //função responsavel por cadastrar usarios no sistema
{
	//inicio criação de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/strings
	
	printf("digite o CPF a ser cadastrado: ");// coletando informações do usuario 
	scanf("%s", cpf); //"%s" se refere as strings
	
	strcpy(arquivo , cpf); //responsavel por copiar os valores das strings
	
	FILE *file;//cria um arquivo
	file = fopen(arquivo, "w");// "w" cria um arquivo
	fprintf(file,"\nCPF: ");
	fprintf(file,cpf);//salva o valor da variavel cpf
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");//"a" atualiza informaçoes no arquivo criado 
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
	scanf("%s", cpf);//lê a string cpf
	
	FILE *file;
	file = fopen(cpf, "r");// abre e le as informações na pasta cpf
	
	if(file == NULL)// se não encontrar o cpf
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}

	printf("\nEssas são as informações do usuario:\n");// se encontrar o cpf
	
	while (fgets( conteudo, 200, file) != NULL)// busca e mostra as informações de dentro da pasta
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
	
	system("cls");//limpando a visão do usuario para uma menssagem clara
	
	FILE *file;
	file = fopen(cpf, "r");//abre lê as informações da pasta depois a fecha 
	fclose(file);
	
	if(file == NULL)// se não encrota o cpf
	{
		printf("\n o usuario não se encontra no sistema\n\n");
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
	setlocale (LC_ALL, "Portuguese");

	int opcao =0; //Definindo variáveis
	int laco =1;
	char senha[20]="a";
	int comparacao;

	printf("Cartório da EBAC\n\n");
	printf("Login de administrador!\n\nDigite sua senha: ");
	scanf("%s", senha);

	comparacao = strcmp(senha, "adm123");
	
	if(comparacao == 0)
	
	{
		for(laco=1;laco=1;)//começo do laco(for)
		
		{
			system("cls");

			setlocale(LC_ALL, "portuguese");// definindo linguagem 
	
			printf("<3 Cartorio da EBAC <3\n\n");// inicio do menu
			printf("Escolha a opção desejada no menu abaixo:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");//final do menu
			printf("\t4 - Sair do sistema\n\n");
			printf("opção:");
	
			scanf("%d" , &opcao); // armazenando a escolha do usuario
	
			system("cls"); // limpeza da tela
	
			switch(opcao) //inicio de seleção do menu
	 		{ 
	 			case 1:
				registro(); //chamada de funções
				break;
		
				case 2:
				consutar();
				break;
		
				case 3:
				deletar();
				break;
			
				case 4:
				printf("obrigado por ultilizar o sistema\n");
				return 0;
				break;
		
				default:
				printf("este comando não esta disponivel\n");
				system("pause");
				break;
			}
		}//fim da seleção
	}
	else 
	printf("\nsenha esta incorreta!\n\n");
} 
