#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct TpPilha
{
	int Topo;
	int Vetor[MAX];
};

// estruturas basicas da pilha
void Inicializar(TpPilha &p)
{
	p.Topo = -1;
}

void Empilhar(TpPilha &p, int n)
{
	p.Vetor[++p.Topo] = n;
}

int Desempilhar(TpPilha &p)
{
	return p.Vetor[p.Topo--];
}

int main(void)
{
	TpPilha Pilha;
	Inicializar(Pilha);
	int numero, resto;
	printf("Digite um numero decimal para converter para binario: ");
	scanf("%d", &numero);
	while(numero >= 1)
	{
		resto = numero % 2;
		numero = numero / 2;
		Empilhar(Pilha, resto);
	}
	while(Pilha.Topo != -1)
	{
		printf("%d", Desempilhar(Pilha));
	}
	return 0;
}


