#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //resp. por alocar espa�o na mem�ria
#include <locale.h> // biblioceta de texto por regi�o
#include <string.h>// biclioteca resp. por cuidar das string

int registro()//fun��o resp. por cadastrar os usu�rios sistema
{
	//inicio cria��o de vari�veis/ string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/ string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf);//resp. por copiar os valores da string
	
	FILE *file;//cria o arquivo no banco de dados
	file = fopen(arquivo, "w");//cria o arquivo no banco de dados, "w" significa escrever, sempre em minusculo
	fprintf(file,cpf);// salva o valor da vari�vel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo p atualizar, "a" significa atualizar, sempre em minusculo
	fprintf(file,",");//atualiza o arquivo com a v�rgula para separar
	fclose(file);// fecha o arquivo
	
	printf("Digite o Nome a ser cadastrado: ");//vai pedir ao usu�rio para digitar um nome
	scanf("%s", nome);// scanf � respons�vel por ler as informa��es passadas pelo usu�rio, que nesse caso � uma string, e vai ler o nome
	
	file = fopen(arquivo, "a");//abre o arquivo p atualizar, "a" significa atualizar, sempre em minusculo
	fprintf(file, nome);//atualiza o arquivo com o nome que foi colocado
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo p atualizar, "a" significa atualizar, sempre em minusculo
	fprintf(file,",");//atualiza o arquivo com a v�rgula para separar
	fclose(file);// fecha o arquivo

	printf("Digite o Sobrenome a ser cadastrado: ");//vai pedir ao usu�rio para digitar um Sobrenome
	scanf("%s", sobrenome);// scanf � respons�vel por ler as informa��es passadas pelo usu�rio, que nesse caso � uma string, e vai ler o Sobrenome
	
	file = fopen(arquivo, "a");//abre o arquivo p atualizar, "a" significa atualizar, sempre em minusculo
	fprintf(file,sobrenome);//atualiza o arquivo com o sobrenome que foi colocado
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo p atualizar, "a" significa atualizar, sempre em minusculo
	fprintf(file,",");//atualiza o arquivo com a v�rgula para separar
	fclose(file);// fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//vai pedir ao usu�rio para digitar um cargo
	scanf("%s", cargo);// scanf � respons�vel por ler as informa��es passadas pelo usu�rio, que nesse caso � uma string, e vai ler o cargo
	
	file = fopen(arquivo, "a");//abre o arquivo p atualizar, "a" significa atualizar, sempre em minusculo
	fprintf(file, cargo);//atualiza o arquivo com o cargo que foi colocado
	fclose(file);// fecha o arquivo
	
	system("pause");//pausa o sistema para permiter que o usu�rio tome uma nova a��o
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssa s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n\n");
		system("pause");
	}
	
}


int main ()
{
	int opcao=0;// definindo as vari�veis
	int laco=1;//la�o de repeti��o
	
	for(laco=1;laco=1;)
	{
		
		system("cls");// resp. por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//definindo a linguagem para funcionar caracteres esp.
	
		printf("### Cart�rio da EBAC ###\n\n");//� o in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o desejada: ");//final do menu
	
		scanf("%d", &opcao);// armazenando a escolha do usu�rio
	
		system("cls");// resp. por limpar a tela
		
		switch(opcao)
		{
			case 1:
			registro();//chamda de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
					
			default:
			printf("Aten��o! Essa op��o n�o et� dispon�vel\n\n");
			system("pause");
			break;
			
		}// final sa sele��o de retorno ao usu�rio
	}
}
	
