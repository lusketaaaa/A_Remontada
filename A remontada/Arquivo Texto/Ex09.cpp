#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio2.h>

int main(void)
{
	// ideia: receber um arquivo texto e contar quantas palavras iniciam por vogal
	// fica facil de realizarmos a leitura palavra por palavra ao inves de ler a linha inteira
	char palavra[50];
	int contador = 0;
	char vogais[] = "aeiou";
	FILE *Arquivo = fopen("arquivo.txt", "r");
	if(Arquivo == NULL)
		printf("Erro de abertura de arquivo!\n");
	else
	{
		while(fscanf(Arquivo, "%s", palavra) != EOF)
		{
			for(int i = 0; i < 5; i++)
			{
				if(tolower(palavra[0]) == vogais[i])
					contador++;
			}
		}
	}
	fclose(Arquivo);
	printf("Quantidade de palavras iniciadas por vogal: %d\n", contador);
	return 0;
}
