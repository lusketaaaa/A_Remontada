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

void Empilhar(TpPilha &p, char n)
{
    p.Vetor[++p.Topo] = n;
}

char Desempilhar(TpPilha &p)
{
    return p.Vetor[p.Topo--];
}

int Vazia(int topo)
{
    return topo == -1;
}

int main(void)
{
    TpPilha Pilha;
    char expressao[100];
    int erro = 0;

    Inicializar(Pilha);

    printf("Digite uma expressao numerica: ");
    scanf("%s", expressao);

    for(int i = 0; expressao[i] != '\0'; i++)
    {
        if(expressao[i] == '(')
        {
            Empilhar(Pilha, '(');
        }

        if(expressao[i] == ')')
        {
            if(Vazia(Pilha.Topo))
            {
                erro = 1;
            }
            else
            {
                Desempilhar(Pilha);
            }
        }
    }

    if(erro == 1 || !Vazia(Pilha.Topo))
        printf("Incorreta\n");
    else
        printf("Correta\n");

    return 0;
}
