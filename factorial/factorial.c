#include <time.h>
#include <stdio.h>

int main(int narg, char *argv[]) // narg - ilość argumentów
{
    int n, c, metoda;
    double silnia;
    metoda = 1; // Domyslna metoda rekurencyjna //
    while (--narg > 0 && (*++argv)[0] == '-')
    {
        if (c = *++argv[0])
        {
            switch (c)
            {
            case 'M':
                sscanf(++argv[0], "%d", &metoda);
                break;
            default:
                printf("Nieznana opcja: -%c\n", c);
                return 1;
            }
        }
    }
    // Zakladamy, ze <n> jest argumentem obowiazkowym //
    if (narg < 1)
    {
        printf("> ./silnia [-Mmetoda] <n>\n");
        return 2;
    }
    sscanf(argv[0], "%d", &n);
    if (metoda == 1)
    {
        time_t timer0 = time(NULL);
        silnia = silnia_rekurencyjnie(n);
        time_t timer1 = time(NULL);
        // time
        long timer = timer1 - timer0;
        printf("silnia rekurencyjnie wykonala sie w czasie: %f\n", timer);
    }
    else if (metoda == 2)
    {
        time_t timer0 = time(NULL);
        silnia = silnia_iteracyjnie(n);
        long timer = timer0 - time(NULL);
        printf("silnia iteracyjnie wykonala sie w czasie: %f\n", timer);
    }
    else
    {
        printf("Nieznana metoda: %d\n", metoda);
        return 3;
    }
    printf("Wynik: %d! = %g\n", n, silnia);
    return 0;
}

int silnia_iteracyjnie(int n)
{
    int silnia = 1;
    int pom = 1;
    while (pom <= n)
    {
        silnia = silnia * pom;
        pom++;
    }
    printf("silnia: %d\n", silnia);
    time_t timer2 = time(NULL);
    return silnia;
}

int silnia_rekurencyjnie(int n)
{
    if (n < 2)
    {
        return 1;
    }
    else
    {
        return n * silnia_rekurencyjnie(n - 1);
    }
}