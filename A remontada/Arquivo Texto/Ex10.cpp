#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio2.h>
#include <ctype.h>
#include <windows.h>

int main(void)
{
	char linha[100];
	// Primeiro passo: criar o arquivo texto:
	FILE *Arquivo = fopen("contagem.txt", "w");
	// fazer um loop para percorrer o arquivo e ir escrevendo a cada incremento da variavel de controle
	for(int i = 1; i <= 1000; i++)
		fprintf(Arquivo, "%d\n",i);
	// teoricamente, aqui o arquivo ja esta escrito ate a linha 1000
	// agora, preciso escrever meu nome depois do numero 1000
	fprintf(Arquivo,"Lucas\n");
	fclose(Arquivo);
	
	FILE *LeituraArquivo = fopen("contagem.txt", "r");
	while(fgets(linha,100,LeituraArquivo) != NULL)
		fgets(linha,100,LeituraArquivo);
	
	fclose(LeituraArquivo);
	
	return 0;
}
