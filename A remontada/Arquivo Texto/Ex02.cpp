#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio2.h>
#include <ctype.h>
#include <windows.h>

int main(void)
{
	// Abrindo arquivo: 
	char linha[100];
	FILE *Arquivo = fopen("arquivo.txt", "r");
	
	if(Arquivo == NULL)
	{
		printf("Nao foi possivel abrir o arquivo!\n");
		return 1;
	}
	
	// criar os contadores:
	int linhas = 0;
	int espacos = 0;
	int letras = 0;
	
	// rodar o while:
	while(fgets(linha,100,Arquivo) != NULL)
	{
		linhas++;
		// agora, percorrer a linha procurando letras ou espacos:
		for(int i = 0; linha[i] != '\0'; i++)
		{
			if(linha[i] == ' ')
				espacos++;
			if(isalpha(linha[i]))
				letras++;
		}
	}
	
	// fechar o arquivo
	fclose(Arquivo);
	
	//exibir a quantidade de cada um:
	printf("Quantidades:\n");
	printf("Letras: %d\nEspacos: %d\nLinhas: %d\n", letras, espacos, linhas);
	
	
	return 0;
}
