#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informação do usuário
	scanf("%s", CPF); //%s refere-se a string
	
	strcpy(arquivo, CPF); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, CPF); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,","); //separa com virgula as informações
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:"); //coletando informação do usuário
	scanf("%s", Nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,Nome);
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:"); //coletando informação do usuário
	scanf("%s",Sobrenome);
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,Sobrenome);
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:"); //coletando informação do usuário
	scanf("%s",Cargo);
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,Cargo);
	fclose(file); //fecha o arquivo
	
	system("pause");
	
	}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
		
	//início criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:");
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
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("\t ### Cartório da EBAC ###\n\n"); //Início do menu
		printf ("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //início da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
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
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
						
		}
	
		//Fim da seleção
			
	}					
}
