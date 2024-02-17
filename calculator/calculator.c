#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define NMAX 2000

double stos[NMAX];
int n = 0;
void push(double number)
{
    if (n < NMAX)
    {
        stos[n] = number;
        n++;
    }
    else
    {
        printf("Stos jest pełny!\n");
    }
}

double pop()
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

int main()
{
    char input[NMAX];
    double wynik = 0.0;
    printf("Witaj, prosze podawac liczby i operatory pojedynczo, aby sprawdzic komendy mozna wpisac help\n");
    printf("Prosze podac ciag do kalkulatora w postaci ONP: \n");

    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';
        if (isNumber(input))
        {
            char reszta[NMAX];
            double number = strtod(input, reszta);
            push(number);
        }
        else
        {
            if (!strcmp(input, "+"))
            {
                if (n > 1)
                {
                    printf("Dodawanie:\n");
                    double x = pop();
                    double y = pop();
                    push(x + y);
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
                    double x = pop();
                    double y = pop();
                    push(y - x);
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
                    double x = pop();
                    double y = pop();
                    push(x * y);
                }
                else
                {
                    printf("Na stosie jest mniej niż 2 argumenty!");
                }
            }
            else if (!strcmp(input, "/"))
            {
                printf("Dzielenie:\n");
                if (n > 1)
                {
                    double x = pop();
                    double y = pop();
                    if (x != 0)
                    {
                        push(y / x);
                    }
                    else
                    {
                        printf("Nie mozna dzielic przez 0!");
                    }
                }
                else
                {
                    printf("Na stosie jest mniej niż 2 argumenty!");
                }
            }
            else if (!strcmp(input, "^"))
            {
                printf("Potegowanie:\n");
                if (n > 1)
                {
                    double x = pop();
                    double y = pop();
                    push(pow(y, x));
                }
                else
                {
                    printf("Na stosie jest mniej niż 2 argumenty!");
                }
            }
            else if (!strcmp(input, "log"))
            {
                printf("Logarytmowanie:\n");
                double x = pop();
                push(log(x));
            }
            else if (!strcmp(input, "sin"))
            {
                printf("sinus:\n");
                double x = pop();
                push(sin(x));
            }
            else if (!strcmp(input, "cos"))
            {
                printf("cosinus:\n");
                double x = pop();
                push(cos(x));
            }
            else if (!strcmp(input, "tg"))
            {
                printf("tangens:\n");
                double x = pop();
                push(tan(x));
            }
            else if (!strcmp(input, "help"))
            {
                printf("Dane operatory:\n +, oznacza dodanie 2 liczb ze stosu, - oznacza odjecie 2 liczb ze stosu,\n * oznacza pomnozenie 2 liczb ze stosu, / oznacza podzielenie 2 liczb ze stosu, \n ^ oznacza wykonanie potegi 2 liczb ze stosu, log oznacza wykonanie logarytmu naturalnego z ostatniej liczby ze stosu, \n sin oznacza wykonanie sinusa z ostatniej liczby ze stosu, cos oznacza wynokanie cosinusa z ostatniej liczby ze stosu,\n tg oznacza wykonanie tangens z ostatniej liczby ze stosu, = oznacza sciagniecie ze stosu ostatniej liczby i wypisanie\n help oznacza wyswietlenie pomocy, q oznacza wyjscie z kalkulatora\n ");
            }
            else if (!strcmp(input, "="))
            {
                wynik = pop();
                printf("Podany wynik to: %f\n", wynik);
            }
            else if (!strcmp(input, "q"))
            {
                printf("Pomyslnie zakonczono dzialanie kalkulatora");
                break;
            }
            else
            {
                printf("Nie ma takiego operatora albo nie jest obslugiwany");
            }
        }
    }
    return 0;
}