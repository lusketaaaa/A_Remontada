#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct TpPilha
{
	int topo;
	int vetor[MAX];
};

void InicializarPilha(TpPilha &p)
{
	p.topo = -1;
}

void Empilhar(TpPilha &p, int elemento)
{
	p.vetor[++p.topo] = elemento;
}

int Desempilhar(TpPilha &p)
{
	return p.vetor[p.topo--];
}

int main(void)
{
	TpPilha Pilha;
	InicializarPilha(Pilha);
	int vetor[MAX];
	for(int i = 0; i < MAX; i++)
	{
		printf("Digite um numero: ");
    	scanf("%d", &vetor[i]);
	}
	
	// empilhar:
	for(int i = 0; i < MAX; i++)
		Empilhar(Pilha, vetor[i]);
	//desempilhar:
	for(int i = 0; i < MAX; i++)
		printf("\n%d", Desempilhar(Pilha));
	
	return 0;
}
