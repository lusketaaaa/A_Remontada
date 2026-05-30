#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct TpFilaCircular
{
    int Inicio;
    int Fim;
    int Vetor[MAX];
};

void Inicializar(TpFilaCircular &f)
{
    f.Inicio = -1;
    f.Fim = -1;
}

int Vazia(int inicio, int fim)
{
    return inicio == -1 && fim == -1;
}

int Cheia(int inicio, int fim)
{
    return (fim + 1) % MAX == inicio;
}

void Enfileirar(TpFilaCircular &f, int elemento)
{
    if(Cheia(f.Inicio, f.Fim))
    {
        printf("Fila cheia!\n");
    }
    else
    {
        if(Vazia(f.Inicio, f.Fim))
        {
            f.Inicio = 0;
            f.Fim = 0;
        }
        else
        {
            f.Fim = (f.Fim + 1) % MAX;
        }

        f.Vetor[f.Fim] = elemento;
    }
}

int Desenfileirar(TpFilaCircular &f)
{
    int elemento;

    if(Vazia(f.Inicio, f.Fim))
    {
        printf("Fila vazia!\n");
        return -1;
    }

    elemento = f.Vetor[f.Inicio];

    if(f.Inicio == f.Fim)
    {
        f.Inicio = -1;
        f.Fim = -1;
    }
    else
    {
        f.Inicio = (f.Inicio + 1) % MAX;
    }

    return elemento;
}

int Primeiro(TpFilaCircular f)
{
    if(Vazia(f.Inicio, f.Fim))
        return -1;

    return f.Vetor[f.Inicio];
}

int Ultimo(TpFilaCircular f)
{
    if(Vazia(f.Inicio, f.Fim))
        return -1;

    return f.Vetor[f.Fim];
}

void Exibir(TpFilaCircular f)
{
    if(Vazia(f.Inicio, f.Fim))
    {
        printf("Fila vazia!\n");
    }
    else
    {
        int i = f.Inicio;

        while(1)
        {
            printf("%d\n", f.Vetor[i]);

            if(i == f.Fim)
                break;

            i = (i + 1) % MAX;
        }
    }
}

int main(void)
{
    TpFilaCircular Fila;

    Inicializar(Fila);

    Enfileirar(Fila, 10);
    Enfileirar(Fila, 20);
    Enfileirar(Fila, 30);

    printf("Fila atual:\n");
    Exibir(Fila);

    printf("\nRemovido: %d\n", Desenfileirar(Fila));

    printf("\nFila apos remocao:\n");
    Exibir(Fila);

    Enfileirar(Fila, 40);
    Enfileirar(Fila, 50);

    printf("\nFila final:\n");
    Exibir(Fila);

    return 0;
}
