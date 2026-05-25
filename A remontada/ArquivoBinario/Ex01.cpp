#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>

struct TpPessoa
{
	char Nome[20];
	int Idade;
};

void CadastrarPessoa(char Arq[30])
{
	TpPessoa Pessoa;
	FILE *Arquivo = fopen(Arq, "ab");
	if(Arquivo == NULL)
		printf("Erro de abertura!\n");
	else
	{
		printf("Digite o nome: ");
		scanf("%s", Pessoa.Nome;
		printf("Digite a idade: ");
		scanf("%d", Pessoa.Idade);
		fwrite(&Pessoa, sizeof(TpPessoa),1,Arquivo);
	}
	fclose(Arquivo);
}

void ExibirPessoas(char Arq[30])
{
	TpPessoa Pessoa;
	FILE *Arquivo = fopen(Arq, "rb");
	if(Arquivo == NULL)
		printf("Erro de abertura!\n");
	else
	{
		fread(&Pessoa, sizeof(TpPessoa), 1, Arquivo);
		while(!feof(Arquivo))
		{
			printf("Nome: %s Idade: %d\n", Pessoa.Nome,Pessoa.Idade);
			fread(&Pessoa, sizeof(TpPessoa), 1, Arquivo);
		}
			
	}
	fclose(Arquivo);
}
