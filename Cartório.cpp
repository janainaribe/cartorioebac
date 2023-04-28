#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informa��o do usu�rio
	scanf("%s", CPF); //%s refere-se a string
	
	strcpy(arquivo, CPF); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, CPF); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,","); //separa com virgula as informa��es
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:"); //coletando informa��o do usu�rio
	scanf("%s", Nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,Nome);
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:"); //coletando informa��o do usu�rio
	scanf("%s",Sobrenome);
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,Sobrenome);
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:"); //coletando informa��o do usu�rio
	scanf("%s",Cargo);
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,Cargo);
	fclose(file); //fecha o arquivo
	
	system("pause");
	
	}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
		
	//in�cio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("\t ### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf ("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
						
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
				
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
						
		}
	
		//Fim da sele��o
			
	}					
}
