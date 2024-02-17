#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int narg, char *argv[])
{
    int *bin;
    int decNumber = 0;
    int method = 1;
    printf("Prosze podac liczbe, ktora zostanie zamieniona na system binarny");
    scanf("%d", &decNumber);
    printf("Prosze podae metode, ktora zostanie uzyta: 1) dzielenie modulo 2) przesuniecie bitowe");
    scanf("%d", &method);
    int numberOfBits = 0;
    bin = (int *)calloc(100, sizeof(int));
    if (bin == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
        while (pow(2, numberOfBits) < decNumber)
        {
            bin[numberOfBits] = 0;
            numberOfBits++;
        }
    int *temp = bin;
    bin = realloc(bin, numberOfBits * sizeof(int));
    if (!bin)
    {
        bin = temp;
    }
    if (method == 1)
    {
        Konwersja_Dec_Bin(decNumber, bin, numberOfBits);
    }
    else if (method == 2)
    {
        Konwersja_Dec_Bin_BitwiseOperator(decNumber, bin, numberOfBits);
    }
    else
    {
        printf("Podana metoda nie została zaimplementowana!");
    }
    return 0;
}

int Konwersja_Dec_Bin(unsigned dec, int *bin[], int numOfBits)
{
    // dzielenie %2
    int i = 0;
    while (dec > 0)
    {
        bin[i] = dec % 2;
        dec = dec / 2;
        i++;
    }
    int start = 0;
    int end = numOfBits - 1;
    int temp;
    while (start < end)
    {
        temp = bin[start];
        bin[start] = bin[end];
        bin[end] = temp;
        start++;
        end--;
    }
    printf("Liczba binarna za pomoca metody bruteforce:");
    for (int i = 0; i < numOfBits; i++)
    {
        printf("%d", bin[i]);
    }
    return 0;
}

int Konwersja_Dec_Bin_BitwiseOperator(unsigned dec, int *bin[], int numOfBits)
{
    // operator bitowy
    int index = numOfBits - 1;
    while (index >= 0)
    {
        bin[index] = dec & 1; //& AND
        index--;
        dec >>= 1; // przesunięcie bitowe w prawo
    }
    printf("\nLiczba binarna z przesunieciem bitowym: ");
    for (int x = 0; x < numOfBits; x++)
    {
        printf("%d", bin[x]);
    }
    return 0;
}