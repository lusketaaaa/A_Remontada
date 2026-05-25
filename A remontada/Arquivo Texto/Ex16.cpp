#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>

// 16. Implemente uma função em C que seja capaz de verificar se um arquivo “.cpp” 
// possui inconsistências em relação aos parênteses existentes. Ou seja, para 
// cada parênteses aberto deve ter um fechado.

int Solucao(char Arquivo[30])
{
	char linha[100];
	int contador = 0;
	FILE *Arq = fopen(Arquivo, "r");
	if(Arq == NULL)
		printf("Erro de abertura!\n");
	else
	{
		while(fgets(linha,sizeof(linha),Arq) != NULL)
		{
			// percorrer a linha:
			for(int i = 0; linha[i] != '\0'; i++)
			{
				if(linha[i] == '(')
					contador++;
				if(linha[i] == ')')
					contador--;
				if(contador < 0)
					return -1;
			}
		}
	}
	fclose(Arq);
	return contador;
	// no main, se contador = 0 -> correto. Se nao, incorreto
}
