#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define NMAX 2000

char stos[NMAX][20];
double domain[NMAX];
int n, domainlen = 0;

const char *pop()
{
    if (n > 0)
    {
        n--;
        return stos[n];
    }
    else
    {
        printf("Stos jest pusty!\n");
    }
}

void push(char string[])
{
    if (n < NMAX)
    {
        strcpy(stos[n], string);
        n++;
    }
    else
    {
        printf("Stos jest pełny!\n");
    }
    printf("stos:[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%s,", stos[i]);
    }
    printf("]\n");
}

int isNumber(char num[])
{
    for (int i = 0; i < strlen(num); i++)
    {
        if (isdigit(num[i]) || num[i] == '.')
        {
            return 1;
        }
    }
    return 0;
}

void evalFunction(char operator[], double number)
{
    if (!strcmp(operator, "+"))
    {
        for (int i = 0; i < domainlen; i++)
        {
            domain[i] = domain[i] + number;
        }
    }
    else if (!strcmp(operator, "-"))
    {
        for (int i = 0; i < domainlen; i++)
        {
            domain[i] = number - domain[i];
        }
    }
    else if (!strcmp(operator, "*"))
    {
        for (int i = 0; i < domainlen; i++)
        {
            domain[i] = domain[i] * number;
        }
    }
    else if (!strcmp(operator, "/"))
    {

        for (int i = 0; i < domainlen; i++)
        {
            if (domain[i] != 0)
            {
                domain[i] = number / domain[i];
            }
            else
            {
                printf("Nie mozna dzielic przez 0!");
            }
        }
    }
    else if (!strcmp(operator, "^"))
    {
        for (int i = 0; i < domainlen; i++)
        {
            domain[i] = pow(domain[i], number);
        }
    }
    else
    {
        printf("Nieobslugiwany operator!");
    }
}

int main()
{
    char input[NMAX];
    double xstart, xend, xstep;
    printf("Witaj, prosze podawac liczby i operatory pojedynczo, aby sprawdzic komendy mozna wpisac help\n");
    printf("Prosze podac wartosc poczatkowa: \n");
    scanf("%lf", &xstart);
    printf("Prosze podac wartosc koncowa: \n");
    scanf("%lf", &xend);
    printf("Prosze podac co ile ma liczyc wartosc funkcji: \n");
    scanf("%lf", &xstep);
    for (double i = xstart; i < xend; i += xstep)
    {
        domain[domainlen] = i;
        domainlen++;
    }
    printf("Prosze podac funkcje w postaci ONP: \n");

    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';
        if (!strcmp(input, "="))
        {
            break;
        }
        else if (!strcmp(input, "q"))
        {
            break;
        }
        else
        {
            if (isNumber(input) || !strcmp(input, "x"))
            {
                printf("number: %s", input);
                push(input);
            }
            else if (!strcmp(input, "+"))
            {
                if (n > 1)
                {
                    printf("Dodawanie:\n");
                    const char *x = pop();
                    const char *y = pop();
                    char *eptr;
                    if (!strcmp(x, "x"))
                    {
                        printf("num: %s", y);
                        double num = strtod(y, &eptr);
                        evalFunction("+", num);
                    }
                    else if (!strcmp(y, "x"))
                    {
                        double num = strtod(x, &eptr);
                        evalFunction("+", num);
                    }
                    push("x");
                }
                else
                {
                    printf("Na stosie jest mniej niż 2 argumenty!");
                }
            }
            else if (!strcmp(input, "-"))
            {
                if (n > 1)
                {
                    printf("Odejmowanie:\n");
                    const char *x = pop();
                    const char *y = pop();
                    char *eptr;
                    if (!strcmp(x, "x"))
                    {
                        double num = strtod(y, &eptr);
                        evalFunction("-", num);
                    }
                    else if (!strcmp(y, "x"))
                    {
                        double num = strtod(x, &eptr);
                        evalFunction("-", num);
                    }
                    push("x");
                }
                else
                {
                    printf("Na stosie jest mniej niż 2 argumenty!");
                }
            }
            else if (!strcmp(input, "*"))
            {
                if (n > 1)
                {
                    printf("Mnozenie:\n");
                    const char *x = pop();
                    const char *y = pop();
                    char *eptr;
                    if (!strcmp(x, "x"))
                    {
                        double num = strtod(y, &eptr);
                        evalFunction("*", num);
                    }
                    else if (!strcmp(y, "x"))
                    {
                        double num = strtod(x, &eptr);
                        evalFunction("*", num);
                    }
                    push("x");
                }
                else
                {
                    printf("Na stosie jest mniej niż 2 argumenty!");
                }
            }
            else if (!strcmp(input, "/"))
            {
                if (n > 1)
                {
                    printf("Dzielenie:\n");
                    const char *x = pop();
                    const char *y = pop();
                    char *eptr;
                    if (!strcmp(x, "x"))
                    {
                        double num = strtod(y, &eptr);
                        evalFunction("/", num);
                    }
                    else if (!strcmp(y, "x"))
                    {
                        double num = strtod(x, &eptr);
                        evalFunction("/", num);
                    }
                    push("x");
                }
                else
                {
                    printf("Na stosie jest mniej niż 2 argumenty!");
                }
            }
            else if (!strcmp(input, "^"))
            {
                if (n > 1)
                {
                    printf("Dzielenie:\n");
                    const char *x = pop();
                    const char *y = pop();
                    char *eptr;
                    if (!strcmp(x, "x"))
                    {
                        double num = strtod(y, &eptr);
                        evalFunction("^", num);
                    }
                    else if (!strcmp(y, "x"))
                    {
                        double num = strtod(x, &eptr);
                        evalFunction("^", num);
                    }
                    push("x");
                }
                else
                {
                    printf("Na stosie jest mniej niż 2 argumenty!");
                }
            }
        }
    }
    printf("liczby: [\n");
    for (int i = 0; i < domainlen; i++)
    {
        printf("%lf,", domain[i]);
    }
    printf("\n]");

    return 0;
}