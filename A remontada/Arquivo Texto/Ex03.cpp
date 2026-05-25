#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio2.h>

int CompararArquivo(char NomeArq1[30], char NomeArq2[30])
	{
		char linha1[100], linha2[100];
		int iguais = 1;
		// temos que abrir os dois arquivos
		FILE *Arq1 = fopen(NomeArq1, "r");
		FILE *Arq2 = fopen(NomeArq2, "r");
		
		// quis fazer esse if, pois coloco o restante no else, evitando criar dois ifs, um para cada verificacao de arquivo
		// desnecessarios - otimizando e deixando o codigo mais limpo
		if(Arq1 == NULL || Arq2 == NULL)
			printf("Erro de abertura em algum dos arquivos");
		else
		{
			// ideia inicial: preciso rodar os dois arquivos do inicio ao fim - logo, dois whiles
			// ideia: ir pegando a linha deles, cada uma em uma variavel e comparar a "string" (linha)
			// percorrer linha: while (fgets(linha, sizeof(linha), arquivo) != NULL)
			while ((fgets(linha1, sizeof(linha1), Arq1) != NULL) && (fgets(linha2, sizeof(linha2), Arq2) != NULL)) // so vai funcionar se tiverem a mesma quantidade de linhas
			{
				if(strcmp(linha1, linha2) != 0)
					iguais = 0;
			}
		if(!(feof(Arq1) && feof(Arq2)))
    		iguais = 0;
		}
		fclose(Arq1);
		fclose(Arq2);
		return iguais;
	}

int main(void)
{		
	int resultado = CompararArquivo("arquivo1.txt", "arquivo2.txt");
	
	if(resultado == 0)
		printf("Arquivos diferentes\n");
	else
		printf("Arquivos iguais!\n");

	return 0;
}
