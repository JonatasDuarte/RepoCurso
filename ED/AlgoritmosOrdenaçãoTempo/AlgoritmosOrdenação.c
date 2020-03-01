#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define SIZE 1000 //tamanho do vetor
void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}
int intcmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

void printArray(int *v, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void preencheArray(int *v, int *v2, int *v3, int *v4, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        v[i] = rand() % 100; //sorteia valor entre 0 e 99 e atribui ao elemento do vetor
        v2[i] = v[i];
        v3[i] = v[i];
    }
}

int checkSort(int *v, int n)
{
    if (n <= 0)
        return -1;
    int ant = v[0];
    int i;
    for (i = 1; i < n; i++)
    {
        if (v[i] < ant)
            return 0;
        ant = v[i];
    }
    return 1;
}

int insertionsort(int *vet, int n)
{
    int anterior, atual, i;
    for (i = 1; i < n; i++)
    {
        atual = vet[i];
        anterior = i - 1;
        while (anterior >= 0 && vet[anterior] > atual)
        {
            vet[anterior + 1] = vet[anterior];
            anterior--;
        }
        vet[anterior + 1] = atual;
    }
}

void merge(int *vet, int i, int f)
{
    int m = (i + f) / 2, aux[f - i + 1], e = i, d = m + 1, k = 0;

    while (e <= m || d <= f)
    {
        if (e > m)
            aux[k++] = vet[d++];

        else if (d > f)
            aux[k++] = vet[e++];

        else if (vet[e] < vet[d])
            aux[k++] = vet[e++];

        else
            aux[k++] = vet[d++];
    }
    for (k = i; k <= f; k++)
    {
        vet[k] = aux[k - i];
    }
}

void mergeSort(int *vet, int i, int f)
{
    if (f > i)
    {
        int m = (i + f) / 2;
        mergeSort(vet, i, m);
        mergeSort(vet, m + 1, f);
        merge(vet, i, f);
    }
}

int partition(int vet[], int i, int f)
{
    int d = i - 1, p = vet[f], j;
    for (j = i; j <= f - 1; j++)
    {
        if (vet[j] <= p)
        {
            d = d + 1;
            swap(&vet[j], &vet[d]);
        }
    }
    d = d + 1;
    swap(&vet[f], &vet[d]);
    return d;
}

void quicksort(int *vet, int i, int f)
{
    if (f > i)
    {
        int p = partition(vet, i, f);
        quicksort(vet, i, p - 1);
        quicksort(vet, p + 1, f);
    }
}

int main()
{
    int SIZE;

    printf("Informe o tamanho do array:\n");
    scanf("%d", &SIZE);

    srand(time(NULL)); //inicializa semente aleatoria

    //declara e preenche os arrays de forma aleatória
    int *v = (int *)malloc(SIZE * sizeof(int));
    int *v2 = (int *)malloc(SIZE * sizeof(int));
    int *v3 = (int *)malloc(SIZE * sizeof(int));
    int *v4 = (int *)malloc(SIZE * sizeof(int));
    preencheArray(v, v2, v3, v4, SIZE);

    clock_t ticks[2];

    ticks[0] = clock();
    mergeSort(v, 0, SIZE - 1);
    ticks[1] = clock();
    double tempo1 = (double)(ticks[1] - ticks[0]) / CLOCKS_PER_SEC;
    // printf("Tempo gasto - merge: %lf s.\n", tempo1);

    ticks[0] = clock();
    insertionsort(v2, SIZE);
    ticks[1] = clock();
    double tempo2 = (double)(ticks[1] - ticks[0]) / CLOCKS_PER_SEC;
    //  printf("Tempo gasto - insertion: %lf s.\n", tempo2);

    ticks[0] = clock();
    quicksort(v3, 0, SIZE - 1);
    // qsort(v3, SIZE, sizeof(int), intcmp);
    ticks[1] = clock();
    double tempo3 = (double)(ticks[1] - ticks[0]) / CLOCKS_PER_SEC;

    ticks[0] = clock();
    qsort(v4, SIZE, sizeof(int), &intcmp);
    ticks[1] = clock();
    double tempo4 = (double)(ticks[1] - ticks[0]) / CLOCKS_PER_SEC;

    printf("Merge: %lf\nInsertion: %lf\nQuick: %lf\nqSort: %lf.\n\n", tempo1, tempo2, tempo3, tempo4);

    //Verifica se o array final ficou ordenado
    int r = checkSort(v, SIZE);
    printf("Check merge: %d\n", r);
    r = checkSort(v2, SIZE);
    printf("Check insertion: %d\n", r);
    r = checkSort(v3, SIZE);
    printf("Check quick: %d\n", r);
    r = checkSort(v4, SIZE);
    printf("Check qsort: %d\n", r);

    return 0;
}
