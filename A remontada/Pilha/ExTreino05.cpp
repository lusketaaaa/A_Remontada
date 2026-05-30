#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct TpPilha
{
	int Topo1;
	int Topo2;
	int Vetor[MAX];
};

void Inicializar(TpPilha &p)
{
	p.Topo1 = -1;
	p.Topo2 = MAX;
}

void EmpilharT1(TpPilha &p, int e)
{
	p.Vetor[++p.Topo1] = e;
}

void EmpilharT2(TpPilha &p, int e)
{
	p.Vetor[--p.Topo2] = e;
}

int DesempilharT1(TpPilha &p)
{
	return p.Vetor[p.Topo1--];
}

int DesempilharT2(TpPilha &p)
{
	return p.Vetor[p.Topo2++];
}

int VaziaT1(int topo)
{
	return topo == -1;
}

int VaziaT2(int topo)
{
	return topo == MAX;
}

int cheia(int t1, int t2)
{
	return t1 + 1 == t2;
}

void Exibir(TpPilha &p)
{
	for(int i = p.Topo1; i >= 0; i--)
		printf("%d", p.Vetor[i]);
		
	for(int i = p.Topo2; i < MAX; i++)
		printf("%d", p.Vetor[i]);
}

