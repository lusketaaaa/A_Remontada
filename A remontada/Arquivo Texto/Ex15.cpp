#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>

//  Ao receber um arquivo texto, uma ‘letra’ e um ‘caractere especial’, todos via 
// parâmetro, retorne um novo arquivo com as devidas substituições dos 
// caracteres iguais a ‘letra’ pelo ‘caractere especial’ escolhido. 

void Solucao(char Arquivo[30], char letra, char caractere)
{
	char linha[100];
	FILE *Arq = fopen(Arquivo, "r");
	FILE *ArqNovo = fopen("novo_arquivo.txt", "w");
	
	if(Arq == NULL)
		printf("Erro de abertura de arquivo!\n");
	else
	{
		// pegar a linha:
		while(fgets(linha,sizeof(linha),Arq) != NULL)
		{
			// percorrer a linha caractere por caractere
			for(int i = 0; linha[i] != '\0'; i++)
			{
				if(tolower(linha[i]) == tolower(letra))
					fputc(caractere, ArqNovo);
				else
					fputc(linha[i], ArqNovo);
			}
		}
	}
	fclose(Arq);fclose(ArqNovo);
}

int main(void)
{
	Solucao("arquivo.txt", 'A', '*');
	return 0;
}
