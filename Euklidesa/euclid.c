#include <stdio.h>

// input: m,n
// output: nwd
int main()
{
    int nwd = 0;
    int n = 0;
    int m = 1;
    printf("Prosze podac pierwsza liczbe m: ");
    scanf("%d", &m);
    printf("Prosze podac druga liczbe n: ");
    scanf("%d", &n);
    int firstm = m;
    int firstn = n;
    if (m % n == 0)
    {
        nwd = n;
    }
    while (m % n != 0)
    {
        int temp = m;
        m = n;
        n = temp % n;
        nwd = n;
    }
    printf("NWD liczb %d,%d wynosi %d", firstm, firstn, nwd);
    return 0;
}