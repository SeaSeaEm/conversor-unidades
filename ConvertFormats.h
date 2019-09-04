#ifndef __CONVERT_FORMATS_H__
#define __CONVERT_FORMATS_H__

#define  BINARY      2
#define  OCTAL       8
#define  HEX         16
#define  MAX_CHAR    100

enum {
    Binary = 0,
    Octal,
    Hex,

    MAX_COUNT = 3
} CONVERT_TYPES;

char* HandleHex(int Left);

char* ConvertDecimalToOthers(int Decimal, int Divisor);

int ConvertOtherToDecimal(char* Aux, int Multiply);

#endif