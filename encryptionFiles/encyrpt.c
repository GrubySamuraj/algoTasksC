#include <stdio.h>
#include <string.h>
#define NMAX 2000

int main(int narg, char *argv[])
{
    if (narg == 2)
    {
        char plik[NMAX] = "";
        FILE *file1, *file2;
        char *tmp;
        char character;
        char password[NMAX];
        int j = 0;
        sscanf(argv[narg - 1], "%s", &plik);
        tmp = tmpnam(NULL);
        file1 = fopen(plik, "rb");
        file2 = fopen(tmp, "wb");
        if (NULL == file1)
        {
            return 1;
        }
        if (NULL == file2)
        {
            return 1;
        }
        printf("Prosze podac haslo do zaszyfrowania: \n");
        scanf("%s", &password);
        while (EOF != (character = getc(file1)))
        {
            putc(character ^ password[j % strlen(password)], file2);
            j++;
        }
        fclose(file1);
        fclose(file2);
        unlink(plik);
        rename(tmp, plik);
    }
    else
    {
        printf("Podano niepoprawna ilosc argumentow\n");
        printf("Jak to powinno wygladac:\n");
        printf("./a.exe <nazwa pliku>");
    }
    return 0;
}