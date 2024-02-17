
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 1000
#define LINE_LENGTH 1000

int compare(const void *a, const void *b)
{
    char *str_a = *(char **)a;
    char *str_b = *(char **)b;
    return strcmp(str_a, str_b);
}

int main()
{
    char *Tekst[NMAX];
    char savedStr[LINE_LENGTH];
    int len = 0;

    while (fgets(savedStr, LINE_LENGTH, stdin) != NULL)
    {
        if (strcmp(savedStr, "\n") != 0 && strcmp(savedStr, "\r\n") != 0)
        {
            Tekst[len] = malloc(strlen(savedStr) + 1);
            strcpy(Tekst[len], savedStr);
            len++;
        }
        else
        {
            break;
        }
    }

    qsort(Tekst, len, sizeof(char *), compare);
    printf("Ciag: \n");
    for (int i = 0; i < len; i++)
    {
        printf("%s,", Tekst[i]);
    }

    return 0;
}