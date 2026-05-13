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
	FILE *NovoArquivo = fopen("novoarquivo.txt", "w");
	
	if(Arquivo == NULL)
	{
		printf("Nao foi possivel abrir o arquivo!\n");
		return 1;
	}
	
	//agora: abrir um while para percorrer o arquivo original
	// e converter para maiusculo tudo (o toupper so vai converter se for alpha...)
	while(fgets(linha,100,Arquivo) != NULL)
	{
		// agora, preciso percorrer a linha 1 por 1:
		for(int i = 0; linha[i] != '\0'; i++)
			linha[i] = toupper(linha[i]);
		// agora que os caracteres da linha ficaram maiusculos, basta grava-los no NovoArquivo
		fprintf(NovoArquivo,"%s",linha);
	}
	fclose(Arquivo);
	fclose(NovoArquivo);
	return 0;
}
