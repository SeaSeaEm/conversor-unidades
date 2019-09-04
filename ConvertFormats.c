#include "ConvertFormats.h"

#include <stdlib.h>
#include <stdio.h>

char* ConvertDecimalToOthers(int Decimal, int Divisor) {
  char *Result = NULL;
  int Exit = 0;

  if (Decimal == 0) {
    Result = "0";
    goto FINISH;
  }

  while (Decimal > 0) {
    int Left = Decimal % Divisor;

    if (Result == NULL) {
        Result = (char*)calloc(2, sizeof(char));
    } else {
        int ResultSize = sizeof(Result) + sizeof(char) * 1;

        Result = (char*)realloc(Result, ResultSize);
    }
    char *Aux = malloc(sizeof(char) + 1);

    if (Divisor == 16 && Left >= 10) {
        Aux = HandleHex(Left);
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

  if (Result != NULL) {
    strrev(Result);
  }

  if (Divisor == 16 && Result != NULL) { //hexa, do upper case
      strupr(Result);
  }

FINISH:
  return Result;
}

int HandleHexToDecimal(char *Value) {
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

int ConvertOtherToDecimal(char *Aux, int Multiply) {
    int Decimal = 0;
    strrev(Aux);

    for(int Index = 0; Index < strlen(Aux); ++Index) {
        int CurrentValue = HandleHexToDecimal(&Aux[Index]);
        Decimal += (int)CurrentValue * (int)pow((double)Multiply, (double)Index);
    }

    return Decimal;
}

char* HandleHex(int Left) {
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
