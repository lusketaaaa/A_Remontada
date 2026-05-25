#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>

void TrocarVogais(char Arquivo[30])
{
    char linha[100];

    FILE *Ponteiro = fopen(Arquivo, "r");
    FILE *PonteiroNovo = fopen("arquivo_novo.txt", "w");

    if(Ponteiro == NULL)
    {
        printf("Erro de abertura\n");
    }
    else
    {
        while(fgets(linha, sizeof(linha), Ponteiro) != NULL)
        {
            for(int i = 0; linha[i] != '\0'; i++)
            {
                if(tolower(linha[i]) == 'a' ||
                   tolower(linha[i]) == 'e' ||
                   tolower(linha[i]) == 'i' ||
                   tolower(linha[i]) == 'o' ||
                   tolower(linha[i]) == 'u')
                {
                    fputc('@', PonteiroNovo);
                }
                else
                {
                    fputc(linha[i], PonteiroNovo);
                }
            }
        }
    }

    fclose(Ponteiro);
    fclose(PonteiroNovo);
}

int main(void)
{
    TrocarVogais("historia.txt");

    return 0;
}
