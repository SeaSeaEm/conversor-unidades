#include <stdlib.h>
#include <stdio.h>

void DecimalToBinary(int* Decimal) {
    printf ("DecimalToBinary Begin\n");
    printf ("Decimal: %d\n", *Decimal);

    char* Result = NULL;
    int Exit = 0;
    printf ("*Result: %zd - sizeof(char): %zd\n", sizeof(Result), sizeof(char));

    while (Decimal > 0) {
        int Left = *Decimal % 2;
        printf ("Left: %d\n", Left);

        if (Result == NULL) {
            printf ("Malloc\n");
            Result = (char*)calloc(2, sizeof(char)); // \0
        } else {
            printf ("Realloc\n");
            int ResultSize = strlen(Result) * sizeof(char);
            printf ("ResultSize: %d\n", ResultSize);
            Result = (char*)realloc(Result, ResultSize);
        }
        printf ("SizeOfResult: %zd\n", sizeof(Result));

        char* Aux = malloc(sizeof(char) + 1);

        if (*Decimal > 1) {
            itoa(Left, Aux, 2);
        } else {
            itoa(*Decimal, Aux, 2);
            Exit = 1;
        }
        printf("Aux:", Aux);
        puts(Aux);

        strcat(Result, Aux);
        printf("\nResult:");
        puts(Result);

        if (Exit) {
            printf ("Exiting...\n");
            break;
        }

        *Decimal /= 2; 
        printf ("\nDecimal/: %d\n", *Decimal);
    }
    strrev(Result);
    printf("Result: %s", Result);

    free(Result);
    Result = NULL;
}

int main() {
    int Decimal;

    printf ("Digite um numero:\n");
    scanf ("%d", &Decimal);

    DecimalToBinary(&Decimal);

    return 0;
}