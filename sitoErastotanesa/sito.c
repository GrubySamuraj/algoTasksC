#include <stdio.h>
#include <math.h>

int printArray(int array[], int n)
{
    for (int x = 0; x < n; x++)
    {
        printf("[%d],", array[x]);
    }
    return 0;
}
int printPrimes(int array[], int n)
{
    for (int x = 0; x < n; x++)
    {
        if (array[x] == 1)
        {
            printf("Liczba pierwsza: %d\n", x);
        }
    }
    return 0;
}
int main()
{
    int n = 0;
    printf("Prosze podac dlugosc tablicy z ktorej beda znajdowane liczby pierwsze: ");
    scanf("%d", &n);
    int primenumbers[n];
    primenumbers[0] = 0;
    primenumbers[1] = 0;
    int primenumber = 2;
    for (int x = 2; x < n; x++)
    {
        primenumbers[x] = 1;
    }
    for (int i = 2; i < sqrt(n); i++)
    {
        for (int j = 2; j < n; j++)
        {
            int pom = j * i;
            if (pom < n)
            {
                primenumbers[pom] = 0;
            }
        }
    }
    // printArray(primenumbers, n);
    printPrimes(primenumbers, n);
    return 0;
}