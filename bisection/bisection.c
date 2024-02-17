#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include <math.h>

#define NMAX 100

double stack[NMAX];

int stackIndex = 0, i = 0;

void push(double value)
{

    if (stackIndex < NMAX)
    {

        stack[stackIndex++] = value;
    }
    else
    {

        printf("Przepełnienie stosu\n");

        exit(EXIT_FAILURE);
    }
}

double pop(void)
{

    if (stackIndex > 0)
    {

        return stack[--stackIndex];
    }
    else
    {

        printf("Niedomiar stosu\n");

        exit(EXIT_FAILURE);
    }
}

int isOperator(char *token)
{

    return (strcmp(token, "+") == 0 ||

            strcmp(token, "-") == 0 ||

            strcmp(token, "*") == 0 ||

            strcmp(token, "/") == 0 ||

            strcmp(token, "^") == 0 ||

            strcmp(token, "log") == 0 ||

            strcmp(token, "sin") == 0 ||

            strcmp(token, "cos") == 0 ||

            strcmp(token, "tan") == 0 ||

            strcmp(token, "cot") == 0);
}

double calculate(double x, double y, char *operator)
{

    if (strcmp(operator, "+") == 0)
    {

        return x + y;
    }
    else if (strcmp(operator, "-") == 0)
    {

        return x - y;
    }
    else if (strcmp(operator, "*") == 0)
    {

        return x * y;
    }
    else if (strcmp(operator, "/") == 0)
    {

        if (y != 0)
        {

            return x / y;
        }
        else
        {

            printf("Dzielenie przez zero\n");

            exit(EXIT_FAILURE);
        }
    }
    else if (strcmp(operator, "^") == 0)
    {

        return pow(x, y);
    }
    else if (strcmp(operator, "log") == 0)
    {

        return log(x);
    }
    else if (strcmp(operator, "sin") == 0)
    {

        return sin(x);
    }
    else if (strcmp(operator, "cos") == 0)
    {

        return cos(x);
    }
    else if (strcmp(operator, "tan") == 0)
    {

        return tan(x);
    }
    else if (strcmp(operator, "cot") == 0)
    {

        return 1.0 / tan(x);
    }
    else
    {

        printf("Nieznany operator: %s\n", operator);

        exit(EXIT_FAILURE);
    }
}

double func(double x, char function[][20])
{

    int n = 0;

    while (n <= i)
    {

        if (isdigit(function[n][0]) || (function[n][0] == '-' && isdigit(function[n][1])))
        {

            push(atof(function[n]));
        }
        else if (strcmp(function[n], "x") == 0)
        {

            push(x);
        }
        else if (isOperator(function[n]))
        {

            if (stackIndex >= 2)
            {

                double y = pop();

                double x = pop();

                push(calculate(x, y, function[n]));
            }
            else
            {

                printf("Za mało operandów dla operatora %s\n", function[n]);

                exit(EXIT_FAILURE);
            }
        }
        else if (strcmp(function[n], "=") == 0)
        {

            if (stackIndex > 0)
            {

                return pop();
            }
            else
            {

                printf("Stos jest pusty\n");
            }
        }
        else
        {

            printf("Niepoprawne dane wejściowe\n");

            exit(EXIT_FAILURE);
        }

        n++;
    }
}

double bisection(double a, double b, double epsilon, char expression[][20])
{

    double c;

    if (func(a, expression) * func(b, expression) > 0)
    {

        printf("Niepoprawny przedział\n");

        exit(EXIT_FAILURE);
    }

    while ((b - a) >= epsilon)
    {

        c = (a + b) / 2;

        if (fabs(func(c, expression)) < epsilon)
        {

            break;
        }
        else if (func(c, expression) * func(a, expression) < 0)
        {

            b = c;
        }
        else
        {

            a = c;
        }
    }

    return c;
}

int main()
{

    char function[NMAX][20];

    int j = 0, last_input = 0;

    double a, b, epsilon;

    printf("Wprowadź funkcję w ONP i = na sam koniec np.('x x * 4 - =') albo 'q' jeżeli chcesz zakończyć program: \n");

    i = 0;

    while (1)
    {

        scanf("%s", &function[i][0]);

        if (strcmp(function[i], "q") == 0)
        {

            exit(EXIT_FAILURE);
        }

        if (!strcmp(function[i], "="))
        {

            break;
        }

        i++;
    }

    printf("Podaj przedział [a, b] (np. 1 3): ");

    scanf("%lf %lf", &a, &b);

    printf("Podaj epsilon: ");

    scanf("%lf", &epsilon);

    printf("Miejsce zerowe funkcji: %lf\n", bisection(a, b, epsilon, function));

    return 0;
}