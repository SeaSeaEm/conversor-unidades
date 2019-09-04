#include "ConvertFormats.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void HandleFirstOption(int Decimal, int Option);
void HandleSecondOption(char* Aux, int Option);

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

void HandleFirstOption(int Decimal, int Option) {
    int Divisor = 0;

    switch(Option) {
        case Binary:
            Divisor = BINARY;
            break;

        case Octal:
            Divisor = OCTAL;
            break;

        case Hex:
            Divisor = HEX;
            break;

        default:
            int Aux = BINARY;
            ConvertDecimalToOthers(Decimal, Aux);

            Aux = OCTAL;
            ConvertDecimalToOthers(Decimal, Aux);

            Aux = HEX;
            ConvertDecimalToOthers(Decimal, Aux);
            return;
    }

    ConvertDecimalToOthers(Decimal, Divisor);
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
        case Hex:
            Decimal = ConvertOtherToDecimal(Aux, 16);
            break;
        default:
            return;
    }

    printf ("Resultado: %d\n", Decimal);
}
