#include <stdlib.h>
#include <stdio.h>
#include <math.h>

enum {
    Binary = 0,
    Octal,
    Hexa,

    MAX_COUNT = 3
} CONVERT_TYPES;

#define         BINARIO     2
#define         OCTAL       8
#define         HEXA        16
#define         MAX_CHAR    100

void HandleFirstOption(int Decimal, int Option);
void HandleSecondOption(char* Aux, int Option);
char* HandleHexa(int Left);
void ConvertDecimalToOthers(int Decimal, int Divisor);
int ConvertOtherToDecimal(char* Aux, int Multiply);

int main() {
    system("cls");
    int FirstOption = 0;
    int SecondOption = 0;
    int Index = 1;

    while (FirstOption >= 0) {
        int Decimal = 0;
        
        printf ("********************\n");
        printf ("[1] - Decimal para os demais formatos\n");
        printf ("[2] - Demais formatos para decimal\n");
        printf ("[3] - Limpar a tela\n");
        printf ("Opcao: ");
        scanf ("%d", &FirstOption);
        printf ("********************\n");

        switch(FirstOption) {
            case 1:
                while (Decimal <= 0) {
                    printf ("Digite um numero maior que 0:\n");
                    scanf ("%d", &Decimal);
                }

                printf ("Digite:\n[1] - Binario\n[2] - Octal\n[3] - Hexadecimal\n[4] - Todos\n\n");
                printf ("Opcao: ");
                scanf ("%d", &SecondOption);
                printf ("\n");

                HandleFirstOption(Decimal, SecondOption - Index);
                printf ("\n\n");
            break;
            case 2:
                char* Aux = (char*)calloc(MAX_CHAR, sizeof(char));

                printf ("Digite um valor:\n");
                scanf ("%s", Aux);
                fflush(stdin);
                printf ("********************\n");

                printf ("Selecione uma opcao:\n[1] - Binario\n[2] - Octal\n[3] - Hexadecimal\n\n\n");
                printf ("Opcao: ");
                scanf ("%d", &SecondOption);
                printf ("********************\n");

                HandleSecondOption(Aux, SecondOption - Index);

                printf ("\n\n");

                free(Aux);
                Aux = NULL;
            break;
            case 3:
                system("cls");
                break;
            default:
                printf ("Opcao Invalida !");
                system("cls");
            break;
        }
    }
    printf ("********************\n");

    return 0;
}

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

void ConvertDecimalToOthers(int Decimal, int Divisor) {
    char* Result = NULL;
    int Exit = 0;

    while (Decimal > 0) {
        int Left = Decimal % Divisor;

        if (Result == NULL) {
            Result = (char*)calloc(2, sizeof(char));
        } else {
            int ResultSize = sizeof(Result) + sizeof(char) * 1;

            Result = (char*)realloc(Result, ResultSize);
        }
        char* Aux = malloc(sizeof(char) + 1);

        if (Divisor == 16 && Left >= 10) {
            Aux = HandleHexa(Left);
        } else if (Decimal > 1) {
            itoa(Left, Aux, Divisor);
        } else {
            itoa(Decimal, Aux, Divisor);
            Exit = 1;
        }

        strcat(Result, Aux);

        if (Exit) {
            break;
        }

        Decimal /= Divisor; 
    }
    strrev(Result);

    if (Divisor == 16) { //hexa, do upper case
        strupr(Result);
    }
    printf("Resultado: %s\n", Result);

    free(Result);
    Result = NULL;
}

void HandleFirstOption(int Decimal, int Option) {
    int Divisor = 0;
    
    switch(Option) {
        case Binary:
            Divisor = BINARIO;
            break;
        
        case Octal:
            Divisor = OCTAL;
            break;
        
        case Hexa:
            Divisor = HEXA;
            break;
        
        default:
            int Aux = BINARIO;
            ConvertDecimalToOthers(Decimal, Aux);

            Aux = OCTAL;
            ConvertDecimalToOthers(Decimal, Aux);

            Aux = HEXA;
            ConvertDecimalToOthers(Decimal, Aux);
            return;
    }

    ConvertDecimalToOthers(Decimal, Divisor);
}

int HandleHexaToDecimal(char* Value) {
    int Decimal = 0;

    switch (*Value) {
        case 'A':
        Decimal = 10;
        break;
        case 'B':
        Decimal = 11;
        break;
        case 'C':
        Decimal = 12;
        break;
        case 'D':
        Decimal = 13;
        break;
        case 'E':
        Decimal = 14;
        break;
        case 'F':
        Decimal = 15;
        break;
        default:
            Decimal = (int)*Value - 48; //ASCII
        break;
    }
    
    return Decimal;
}

void HandleSecondOption(char* Aux, int Option) {
    int Decimal = 0;

    switch(Option) {
        case Binary:
            Decimal = ConvertOtherToDecimal(Aux, 2);
            break;

        case Octal:
            Decimal = ConvertOtherToDecimal(Aux, 8);
            break;
        
        case Hexa:
            Decimal = ConvertOtherToDecimal(Aux, 16);
            break;
        
        default:
            return;
    }

    printf ("Resultado: %d\n", Decimal);
}

int ConvertOtherToDecimal(char* Aux, int Multiply) {
    int Decimal = 0;
    strrev(Aux);

    for(int Index = 0; Index < strlen(Aux); ++Index) {
        int CurrentValue = HandleHexaToDecimal(&Aux[Index]);
        Decimal += (int)CurrentValue * (int)pow((double)Multiply, (double)Index);
    }

    return Decimal;
}