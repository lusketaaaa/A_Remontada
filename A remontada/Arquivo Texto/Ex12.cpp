#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>

// Exercício 12 — receber um arquivo e uma letra, retornar a linha que mais tem essa letra.

int Solucao(char Arquivo[30], char letra)
{
	char linha[100];
	int maior_contador = 0;
	int contador = 0;
	int contador_linha = 1;
	int maior_contador_linha = 0;	
	FILE *Ponteiro = fopen(Arquivo, "r");
	if(Ponteiro == NULL)
		printf("Erro de abertura!\n");
	else
	{
		//pegar a linha:
		while(fgets(linha, sizeof(linha), Ponteiro) != NULL)
		{
			// percorrer a linha:
			for(int i = 0; linha[i] != '\0'; i++)
			{
				if(tolower(linha[i]) == tolower(letra))
					contador++;
			}
			if(contador > maior_contador)
			{
				maior_contador = contador;
				maior_contador_linha = contador_linha;
			}
			contador = 0;
			contador_linha++;
		}
	}
	fclose(Ponteiro);
	return maior_contador_linha;
}

int main(void)
{
	int linha = Solucao("arquivo.txt", 'b');
	printf("%d\n", linha);
	return 0;
}
