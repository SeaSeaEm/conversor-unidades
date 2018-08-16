#include <stdlib.h>
#include <stdio.h>

enum {
    Binary = 0,
    Octal,
    Hexa,

    MAX_COUNT = 3
};

#define         BINARIO 2;
#define         OCTAL   8;
#define         HEXA    16;

char* HandleHexa(int Left) {
    switch(Left) {
        case 10:
            return "A";
        break;
        case 11:
            return "B";
        break;
        case 12:
            return "C";
        break;
        case 13:
            return "D";
        break;
        case 14:
            return "E";
        break;
        case 15:
            return "F";
        break;
        default:
            return NULL;
        break;
    }
}

void Convert(int Decimal, int Divisor) {
    char* Result = NULL;
    int Exit = 0;

    // printf ("Decimal: %d - Divisor: %d\n", Decimal, Divisor);
    
    while (Decimal > 0) {
        int Left = Decimal % Divisor;
        // printf ("Left: %d\n", Left);

        if (Result == NULL) {
            // printf ("Malloc\n");
            Result = (char*)calloc(2, 2);
        } else {
            // printf ("Realloc\n");
            int ResultSize = sizeof(Result) + sizeof(char) * 1;
            // printf ("ResultSize: %d\n", ResultSize);
            Result = (char*)realloc(Result, ResultSize);
        }
        // printf ("SizeOfResult: %zd\n", sizeof(Result));

        char* Aux = malloc(sizeof(char) + 1);

        if (Divisor == 16 && Left >= 10) {
            Aux = HandleHexa(Left);
        } else if (Decimal > 1) {
            itoa(Left, Aux, Divisor);
        } else {
            itoa(Decimal, Aux, Divisor);
            Exit = 1;
        }

        // printf("Aux:", Aux);
        // puts(Aux);

        strcat(Result, Aux);
        // printf("\nResult:");
        // puts(Result);

        if (Exit) {
            break;
        }

        Decimal /= Divisor; 
        // printf ("\nDecimal/: %d\n", Decimal);
    }
    strrev(Result);

    if (Divisor == 16) { //hexa, do upper case
        strupr(Result);
    }
    printf("Resultado: %s\n", Result);

    free(Result);
    Result = NULL;
}

void HandleOption(int Decimal, int Option) {
    char* Result = NULL;
    int Divisor = 0;

    // printf ("Decimal: %d - Option: %d\n", Decimal, Option);
    
    switch(Option) {
        case Binary:
            printf ("DecimalToBinary Begin\n");
            Divisor = BINARIO;
            break;
        
        case Octal:
            printf ("DecimalToOctal Begin\n");
            Divisor = OCTAL;
            break;
        
        case Hexa:
            printf ("DecimalToHexa Begin\n");
            Divisor = HEXA;
            break;
        
        default:
            int Aux = BINARIO;
            Convert(Decimal, Aux);

            Aux = OCTAL;
            Convert(Decimal, Aux);

            Aux = HEXA;
            Convert(Decimal, Aux);
            return;
    }

    Convert(Decimal, Divisor);
}

int main() {
    int Decimal = 0;
    int Option;
    int Index = 1;

    printf ("********************\n");
    while (Decimal >= 0) {
        printf ("Digite um numero maior que 0:\n");
        scanf ("%d", &Decimal);

        printf ("Digite:\n[1] - Binario\n[2] - Octal\n[3] - Hexadecimal\n[4] - Todos\n\n");
        printf ("Opcao: ");
        scanf ("%d", &Option);
        printf ("\n");

        HandleOption(Decimal, Option - Index);
        printf ("\n");
    }
    printf ("********************\n");

    return 0;
}