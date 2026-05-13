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
		printf("Erro ao abrir arquivo!\n");
		return 1;
	}
	int contador = 1;
	// Com o arquivo aberto, devo iniciar o while
	while(fgets(linha,100,Arquivo) != NULL)
	{
		printf("%d %s\n", contador, linha);
		contador++;
	}
	
	fclose(Arquivo);
	
	return 0;
}
