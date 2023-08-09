#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //resp. por alocar espaço na memória
#include <locale.h> // biblioceta de texto por região
#include <string.h>// biclioteca resp. por cuidar das string

int registro()//função resp. por cadastrar os usuários sistema
{
	//inicio criação de variáveis/ string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/ string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf);//resp. por copiar os valores da string
	
	FILE *file;//cria o arquivo no banco de dados
	file = fopen(arquivo, "w");//cria o arquivo no banco de dados, "w" significa escrever, sempre em minusculo
	fprintf(file,cpf);// salva o valor da variável
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo p atualizar, "a" significa atualizar, sempre em minusculo
	fprintf(file,",");//atualiza o arquivo com a vírgula para separar
	fclose(file);// fecha o arquivo
	
	printf("Digite o Nome a ser cadastrado: ");//vai pedir ao usuário para digitar um nome
	scanf("%s", nome);// scanf é responsável por ler as informações passadas pelo usuário, que nesse caso é uma string, e vai ler o nome
	
	file = fopen(arquivo, "a");//abre o arquivo p atualizar, "a" significa atualizar, sempre em minusculo
	fprintf(file, nome);//atualiza o arquivo com o nome que foi colocado
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo p atualizar, "a" significa atualizar, sempre em minusculo
	fprintf(file,",");//atualiza o arquivo com a vírgula para separar
	fclose(file);// fecha o arquivo

	printf("Digite o Sobrenome a ser cadastrado: ");//vai pedir ao usuário para digitar um Sobrenome
	scanf("%s", sobrenome);// scanf é responsável por ler as informações passadas pelo usuário, que nesse caso é uma string, e vai ler o Sobrenome
	
	file = fopen(arquivo, "a");//abre o arquivo p atualizar, "a" significa atualizar, sempre em minusculo
	fprintf(file,sobrenome);//atualiza o arquivo com o sobrenome que foi colocado
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo p atualizar, "a" significa atualizar, sempre em minusculo
	fprintf(file,",");//atualiza o arquivo com a vírgula para separar
	fclose(file);// fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//vai pedir ao usuário para digitar um cargo
	scanf("%s", cargo);// scanf é responsável por ler as informações passadas pelo usuário, que nesse caso é uma string, e vai ler o cargo
	
	file = fopen(arquivo, "a");//abre o arquivo p atualizar, "a" significa atualizar, sempre em minusculo
	fprintf(file, cargo);//atualiza o arquivo com o cargo que foi colocado
	fclose(file);// fecha o arquivo
	
	system("pause");//pausa o sistema para permiter que o usuário tome uma nova ação
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
		printf("Não foi possível abrir o arquivo, não localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssa são as informações do usuário: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n\n");
		system("pause");
	}
	
}


int main ()
{
	int opcao=0;// definindo as variáveis
	int laco=1;//laço de repetição
	
	for(laco=1;laco=1;)
	{
		
		system("cls");// resp. por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//definindo a linguagem para funcionar caracteres esp.
	
		printf("### Cartório da EBAC ###\n\n");//é o início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção desejada: ");//final do menu
	
		scanf("%d", &opcao);// armazenando a escolha do usuário
	
		system("cls");// resp. por limpar a tela
		
		switch(opcao)
		{
			case 1:
			registro();//chamda de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
					
			default:
			printf("Atenção! Essa opção não etá disponível\n\n");
			system("pause");
			break;
			
		}// final sa seleção de retorno ao usuário
	}
}
	
