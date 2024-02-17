#include <stdio.h>
#include <math.h>

int main()
{
    float a = 0;
    float b = 0;
    float c = 0;
    printf("Prosze podac wspolczynnik a, znajdujacy sie przy x^2\n");
    scanf("%f", &a);
    printf("Prosze podac wspolczynnik b, znajdujacy sie przy x\n");
    scanf("%f", &b);
    printf("Prosze podac wspolczynnik c, znajdujacy sie przy znaku wolnym\n");
    scanf("%f", &c);
    if (a == 0)
    {
        printf("Podana funkcja nie jest funkcja kwadratowa");
    }
    else
    {
        float delta = (pow(b, 2) - (4 * a * c));
        if (delta == 0.0)
        {
            float x = (-b) / (2 * a);
            printf("Podana funkcja ma jedno rozwiazanie rzeczywiste: %.2f", x);
        }
        else if (delta > 0.0)
        {
            float x1 = (-b + sqrt(delta)) / (2 * a);
            float x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Podana funkcja ma 2 rozwiazania rzeczywiste: %.2f i %.2f", x1, x2);
        }
        else
        {
            printf("Podana funkcja nie ma rozwiazan rzeczywistych");
        }
    }
    return 1;
}