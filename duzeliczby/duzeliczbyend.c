#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 1000

int main()
{
    printf("----------------------------------------------\n");
    char bigNumber1[NMAX];
    char bigNumber2[NMAX];
    int *iloczyn;
    printf("Prosze podac liczbe do przemnozenia:\n ");
    scanf("%s", &bigNumber1);
    printf("Prosze podac druga liczbe do przemnozenia:\n ");
    scanf("%s", &bigNumber2);
    iloczyn = malloc((strlen(bigNumber1) + strlen(bigNumber2)) * sizeof(int));

    for (int i = 0; i < (strlen(bigNumber1) + strlen(bigNumber2)); i++)
    {
        iloczyn[i] = 0;
    }
    for (int i = strlen(bigNumber1) - 1; i >= 0; i--)
    {
        for (int j = strlen(bigNumber2) - 1; j >= 0; j--)
        {
            int cyfra1 = bigNumber1[i] - '0';
            int cyfra2 = bigNumber2[j] - '0';

            int wynik = cyfra1 * cyfra2;

            wynik += iloczyn[i + j + 1];
            printf("wynik: %d \n", wynik);
            iloczyn[i + j] += wynik / 10;
            iloczyn[i + j + 1] = wynik % 10;
        }
    }
    char *wynik2;
    wynik2 = malloc((strlen(bigNumber1) + strlen(bigNumber2)) * sizeof(char));
    int index = 0;

    int x = 0;

    for (int i = 0; i < (strlen(bigNumber1) + strlen(bigNumber2)); i++)
    {
        wynik2[x] = iloczyn[i] + '0';
        x++;
    }

    wynik2 + '\0';

    printf("Iloczyn: %s\n", wynik2);
    return 1;
}