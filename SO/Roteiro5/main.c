#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo
#define MAX_PROCESS 20
#define QUANTUM 5
#define BUFFER_SIZE 255

const char SEPARATOR[2] = ";";

typedef int FLAG_TYPE;
#define NOT_CONSUMED 0 // Processo que não foi finalizado
#define CONSUMED 1     // Processo finalizado

// Processo
typedef struct
{
    char ID[5];
    int DURATION;
    FLAG_TYPE FLAG;

} Process;

Process processList[MAX_PROCESS];

// Organizando a lista para colocar o processo no final
void reorganizeList(Process *processList, int finalP, int size)
{
    Process aux = processList[finalP];
    for (int i = finalP; i < size - 1; i++)
    {
        processList[i] = processList[i + 1];
    }
    processList[size - 1] = aux;
}

int main(int argc, char const *argv[])
{
    // Acessando o arquivo e populando a lista...
    FILE *file;

    Process p;
    char buffer[BUFFER_SIZE];
    char *value;
    int count = 0;

    file = fopen("./processList.txt", "r");

    while (fgets(buffer, BUFFER_SIZE, file))
    {
        value = strtok(buffer, SEPARATOR);
        strcpy(p.ID, value);
        value = strtok(NULL, SEPARATOR);
        p.DURATION = atoi(value);
        p.FLAG = NOT_CONSUMED;
        processList[count] = p;
        count++;
    }

    fclose(file);

    int notProcessed = count;
    int currentProcIndex = 0;

    Process *currentProc;

    // Verificação da duração dos processos
    while (notProcessed > 0)
    {
        currentProc = &processList[currentProcIndex];
        printf("%s processo atual\n", currentProc->ID);
        if (currentProc->FLAG == NOT_CONSUMED)
        {
            if (currentProc->DURATION <= QUANTUM)
            {
                printf("%s finalizado!\n\n", currentProc->ID);
                notProcessed--;
                currentProcIndex = (currentProcIndex + 1) % count;
                currentProc->FLAG = CONSUMED;
                currentProc->DURATION = 0;
            }
            else
            {
                // Caso em que o processo precisa ser rechaveado, rodar novamente
                printf("Nao completou %s, chaveando novo processo...\n", currentProc->ID);
                currentProc->DURATION -= QUANTUM;
                reorganizeList(processList, currentProcIndex, count);
            }
        }
        else
        {
            // Índice da lista circular
            currentProcIndex = (currentProcIndex + 1) % count;
        }
    }
    return 0;
}