#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct TpPilha
{
    int Topo;
    char Vetor[MAX];
};

void Inicializar(TpPilha &p)
{
    p.Topo = -1;
}

void Empilhar(TpPilha &p, char e)
{
    p.Vetor[++p.Topo] = e;
}

char Desempilhar(TpPilha &p)
{
    return p.Vetor[p.Topo--];
}

char Vazia(int topo)
{
    return topo == -1;
}

int main(void)
{
    TpPilha Pilha;
    Inicializar(Pilha);

    char expressao[MAX];
    char topo;
    int erro = 0;

    printf("Digite a expressao: ");
    scanf("%s", expressao);

    for(int i = 0; expressao[i] != '\0'; i++)
    {
        if(expressao[i] == '(' ||
           expressao[i] == '[' ||
           expressao[i] == '{')
        {
            Empilhar(Pilha, expressao[i]);
        }

        if(expressao[i] == ')' ||
           expressao[i] == ']' ||
           expressao[i] == '}')
        {
            if(Vazia(Pilha.Topo))
            {
                erro = 1;
            }
            else
            {
                topo = Desempilhar(Pilha);

                if(expressao[i] == ')' && topo != '(')
                    erro = 1;

                if(expressao[i] == ']' && topo != '[')
                    erro = 1;

                if(expressao[i] == '}' && topo != '{')
                    erro = 1;
            }
        }
    }

    if(erro == 0 && Vazia(Pilha.Topo))
        printf("Expressao correta!\n");
    else
        printf("Expressao incorreta!\n");

    return 0;
}
