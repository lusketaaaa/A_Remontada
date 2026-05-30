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

int Vazia(int inicio, int fim)
{
    return inicio > fim;
}

int Cheia(int fim)
{
    return fim == MAX - 1;
}

void ExibirFila(TpFila f)
{
    for(int i = f.Inicio; i <= f.Fim; i++)
        printf("%d\n", f.Vetor[i]);
}

int main(void)
{
    TpFila Fila;
    Inicializar(Fila);

    int numeroPaciente = 1;
    int numeroPacienteAtendido;
    int op;

    do
    {
        printf("\nAtendimento\n");
        printf("1 - Entrar na fila\n");
        printf("2 - Atender cliente\n");
        printf("3 - Exibir fila\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        if(op == 1)
        {
            if(!Cheia(Fila.Fim))
            {
                Enfileirar(Fila, numeroPaciente);
                printf("Voce entrou na fila, numero da chamada: %d\n", numeroPaciente);
                numeroPaciente++;
            }
            else
                printf("Fila cheia!\n");
        }

        if(op == 2)
        {
            if(!Vazia(Fila.Inicio, Fila.Fim))
            {
                numeroPacienteAtendido = Desenfileirar(Fila);
                printf("Paciente de numero %d foi atendido!\n", numeroPacienteAtendido);
            }
            else
                printf("Fila vazia!\n");
        }

        if(op == 3)
        {
            if(!Vazia(Fila.Inicio, Fila.Fim))
                ExibirFila(Fila);
            else
                printf("Fila vazia!\n");
        }

    } while(op != 0);

    return 0;
}
