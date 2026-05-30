#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct TpFila
{
	int Inicio;
	int Fim;
	int Vetor[MAX];
};

void Inicializar(TpFila &f)
{
	f.Inicio = 0;
	f.Fim = -1;
}

void Enfileirar(TpFila &f, int e)
{
	f.Vetor[++f.Fim] = e;
}

int Desenfileirar(TpFila &f)
{
	return f.Vetor[f.Inicio++];
}

int Cheia(int fim)
{
	return fim == MAX - 1;
}

int Vazia(int inicio, int fim)
{
	return inicio > fim;
}

//int Quantidade(TpFila f)
//{
//	int contador = 0;
//	while(!Vazia(f.Inicio, f.Fim))
//	{
//		contador++;
//		Desenfileirar(f);
//	}
//	return contador;
//}

int Quantidade(TpFila f)
{
    if(Vazia(f.Inicio, f.Fim))
        return 0;

    return f.Fim - f.Inicio + 1;
}

int main(void)
{
	TpFila Fila;
	Inicializar(Fila);
	int qtd = Quantidade(Fila);
	printf("%d", qtd);
	
	return 0;
}
