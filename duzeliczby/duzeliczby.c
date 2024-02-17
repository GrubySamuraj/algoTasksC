#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NMAX 1000
void printArray(char arr[])
{
    printf("liczba:\n");
    for (int i = 0; i < strlen(arr); i++)
    {
        printf("%c", arr[i]);
    }
}

void fillZeros(char arr[], char longerArray[])
{
    char arr2[NMAX];
    for (int i = 0; i < strlen(longerArray); i++)
    {
        arr2[i] = '0';
    }
    for (int i = 0; i < strlen(longerArray); i++)
    {
        // printf("strlen: %d \n", strlen(arr) - strlen(longerArray) + i);
        if ((strlen(arr) - strlen(longerArray) + i) >= 0)
        {
            // printf("%d jest wieksze od 0 ", strlen(arr) - strlen(longerArray) + i);
            arr2[i] = arr[strlen(arr) - strlen(longerArray) + i];
        }
        else
        {
            arr2[i] = '0';
        }
    }
    // printArray(arr2);
}
int main()
{
    printf("----------------------------------------------\n");
    char bigNumber1[NMAX];
    char bigNumber2[NMAX];
    char iloczyn[NMAX] = "";
    printf("Prosze podac liczbe do przemnozenia:\n ");
    scanf("%s", &bigNumber1);
    printf("Prosze podac druga liczbe do przemnozenia:\n ");
    scanf("%s", &bigNumber2);
    // iloczyn = malloc(((strlen(bigNumber1) + strlen(bigNumber2)) * sizeof(int)));
    int przeniesienie = 0;
    int temp = 0;
    for (int i = 0; i < strlen(bigNumber1) + strlen(bigNumber2); i++)
    {
        iloczyn[i] = '0';
    }
    for (int i = 0; i < strlen(bigNumber1); i++)
    {
        char tempNumber[NMAX] = {};
        for (int j = 0; j < strlen(bigNumber2) + i; j++)
        {
            if (j < strlen(bigNumber2))
            {
                temp = (bigNumber1[strlen(bigNumber1) - j - 1] - '0') * (bigNumber2[strlen(bigNumber2) - i - 1] - '0');

                char tempString = temp + '0';
                tempNumber[strlen(tempNumber)] = tempString;
            }
            else
            {
                tempNumber[strlen(tempNumber)] = '0';
            }
        }
        printArray(iloczyn);
        fillZeros(tempNumber, iloczyn);
        for (int k = 0; k < strlen(tempNumber); k++)
        {
            int iloczynInt = iloczyn[k] - '0';
            int tempNumberInt = tempNumber[k] - '0';
            if ((iloczynInt + tempNumberInt + przeniesienie) > 9)
            // przeniesienie
            {
                int wynikTemp = iloczynInt + tempNumberInt + przeniesienie;
                char liczba[20];
                sprintf(liczba, "%d", wynikTemp);
                char cyfra = liczba[strlen(liczba) - 1];
                iloczyn[k] = cyfra;
                przeniesienie = 1;
            }
            else
            // brak przeniesienia
            {
                // printf("brak przeniensienia: %d\n ", iloczynInt + tempNumberInt);
                int wynikTemp = iloczynInt + tempNumberInt + przeniesienie;
                char wynikString = wynikTemp + '0';
                // printf("wynikTemp: %c\n", wynikString);
                iloczyn[k] = wynikString;
                przeniesienie = 0;
            }
        }
        // printArray(iloczyn);
    }
    printArray(iloczyn);
    return 1;
}