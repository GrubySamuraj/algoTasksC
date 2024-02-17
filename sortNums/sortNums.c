#include <stdio.h>
#include <stdlib.h>

#define NMAX 2000

int compareElementsDec(int *a, int *b)
{
    return (*a - *b);
}

int compareElementsInc(int *b, int *a)
{
    return (*a - *b);
}

int main(int narg, char *argv[])
{
    int metoda = 1;
    int len = 0;
    int nums[NMAX];
    if (narg == 2 && argv[1][0] == '-' && argv[1][1] == 'M')
    {
        char row[NMAX] = {};
        while (fgets(row, NMAX, stdin) != NULL)
        {
            nums[len] = atoi(row);
            len++;
        }
        switch (argv[1][2] - '0')
        {
        case 0: // malejace
            qsort(nums, len, sizeof(int), compareElementsDec);
            break;
        case 1: // rosnace
            qsort(nums, len, sizeof(int), compareElementsInc);
            break;
        default:
            printf("Nie ma takiej metody:\n > ./a [-Mmetoda] (gdzie 1 to sortwanie malejace, a 0 rosnace)\n");
            break;
        }
        printf("Ciag: \n");
        for (int i = 0; i < len; i++)
        {
            printf("%d,", nums[i]);
        }
    }
    else
    {
        printf("> ./a [-Mmetoda] (gdzie 1 to sortwanie malejace, a 0 rosnace)\n");
        return 2;
    }
    return 0;
}