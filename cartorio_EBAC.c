#include <stdio.h> //biblioteca de comunica??o com o usu?rio
#include <stdlib.h> // biblioteca de aloca??o de espa?o em mem?ria
#include <locale.h> //biblioteca de aloca??es de texxto por regi?o
#include <string.h> //biblioteca respons?vel pelas string (malha de informa??es)


int registro() //fun??o voltada para o registro
{

	char arquivo[50]; //? uma vari?vel que serve para a pessoa alocar um determinado n?mero de caracteres
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	
	printf("Digite o CPF a ser cadastrado: "); // mostrar para o usu?rio
	scanf("%s", cpf); //criando uma malha de informa??es para o cpf
	
	strcpy(arquivo, cpf); //Respons?vel por copiar o valor das string
	strcat(arquivo,".txt"); //Fun??o respons?vel por alterar o tipo do arquivo
	
	FILE *file; //acessar o FILE e cria um file
	file = fopen(arquivo, "w"); // vai abrir a vari?vel arquivo e reescrever no arquivo
	fprintf(file,cpf); //? para armazenar para o arquivo
	fclose(file); //fecha arquivo
	
	file = fopen (arquivo, "a"); // para atualizar a vari?vel
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file=fopen(arquivo, "a");
	fprintf(file, nome); // vai escrever o nome j? escrito pelo usu?rio no arquivo
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ","); //atualizando o aquivo de forma autom?tica com a , e o paragrafo
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file=fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	
	file=fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system ("pause");
		
}

int consulta() //fun??o voltada para o consulta
{
	
	setlocale(LC_ALL, "portuguese");
	
	char cpf[50];
	char conteudo[400];
	
	printf("Digite o CPF a ser consultado");
	scanf("%s",cpf);
	strcat(cpf,".txt");
	FILE *file;
	file = fopen(cpf,"r"); // ele ir? ler o arquivo
	
	if(file == NULL)
	
{
	printf ("N?o foi poss?vel abrir o arquivo, n?o localizado!\n");
}
	while(fgets(conteudo, 400, file) != NULL) // fun??o que vai buscar o conte?do, tamanho m?ximo do conte?do, enquanto ele rodar dentro do arquivo parando caso seja nulo
{
	printf ("\nEssas s?o as informa??es do usu?rio: ");
	printf ("%s", conteudo);
	printf ("\n\n");
}
	system("pause");

}

int deletar() //fun??o voltada para o deletar
{
	
	setlocale(LC_ALL, "portuguese");
	
	char cpf[50];
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	
	remove(cpf);
	
	FILE *file; //* ? um tipo de ponteiro
	file = fopen(cpf,"r");
	
		if(file == NULL) 
		{
	
		printf("O usu?rio localizado foi exclu?do!\n");
		system("pause");
		
		}
		

}
int main() //Fun??o na qual d? in?cio
{
	int opcao=0; //definindo vari?veis
	int laco=1;
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	char senhadigitada[10]="a"; //string para conter toda a informa??o da senha que o usu?rio digitar
	printf("### Cart?rio da EBAC ### \n\n");
	printf("Login de administrador!\n\nDigite sua senha \n\n");
	scanf("%s", senhadigitada);
	
	// recomenda??o para valida??o de senha do professor seria como nas seguintes linhas
	// int comparacao ap?s a char senhadigitada[] = "a";
	
	// comparacao = strcmp(senhadigitada,"admin");
	// +
	// if (comparcao == 0);
	

	if (strcmp(senhadigitada, "admin") == 0) //fun??o para validar a senha
	
			for ( laco = 1; laco = 1; ) // criar um ciclo de in?cio e fim
			{
		
			system ("cls");
		
				
			printf("### Cart?rio da EBAC ### \n\n"); //in?cio do menu
			printf("Escolha a op??o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("\top??o (digite somente o n?mero): "); //fim do menu
		
			scanf("%d", &opcao); //armazenando a escolha do usu?rio, & ? um tipo de ponteiro
		
			system("cls"); //limpar p?gina cabe?alho final da p?gina
		
			switch(opcao) // condi??es
			{
			case 1:
			registro();
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
			printf("Voc? n?o escolheu uma op??o existente!\n");
			system("pause");
			break;
			
		}
		} //Fim da sele??o
			else
			printf("senha incorreta!");
			
}

