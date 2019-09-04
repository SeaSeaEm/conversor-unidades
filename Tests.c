#include "ConvertFormats.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// maybe move this to a different file
#define ASSERT(condition, failmsg) \
  if (!(condition)) { \
    printf("......ASSERT FAILED - %s (%s line %d)\n", failmsg, __FILE__, __LINE__); \
    return 0; \
  }

void DecimalToBinary(int Decimal, char* Expected) {
  char *Result = ConvertDecimalToOthers(Decimal, BINARY);

  ASSERT(strcmp(Expected, Result) == 0, "Assertion failed for Decimal to Binary");
}

void DecimalToOctal(int Decimal, char* Expected) {
  char *Result = ConvertDecimalToOthers(Decimal, OCTAL);

  ASSERT(strcmp(Expected, Result) == 0, "Assertion failed for Decimal to Octal");
}

void DecimalToHex(int Decimal, char* Expected) {
  char *Result = ConvertDecimalToOthers(Decimal, HEX);

  ASSERT(strcmp(Expected, Result) == 0, "Assertion failed for Decimal to Hex");
}

void EvaluateDecimalToBinary() {
  printf("Evaluating Decimal to Binary\n\n");

  DecimalToBinary(10, "1010");
  DecimalToBinary(9999, "10011100001111");
  DecimalToBinary(99, "1100011");
  DecimalToBinary(2, "10");

  // TODO: fix these scenarios
  DecimalToBinary(0, "0");
  // DecimalToBinary(-1, "1111111111111111");
}

void EvaluateDecimalToOctal() {
  printf("Evaluating Decimal to Octal\n\n");

  DecimalToOctal(10, "12");
  DecimalToOctal(9999, "23417");
  DecimalToOctal(99, "143");
  DecimalToOctal(2, "2");

  // TODO: fix these scenarios
  DecimalToOctal(0, "0");
  // DecimalToOctal(-1, "177777");
}

void EvaluateDecimalToHex() {
  printf("Evaluating Decimal to Hex\n\n");

  DecimalToHex(10, "A");
  DecimalToHex(9999, "270F");
  DecimalToHex(99, "63");
  DecimalToHex(2, "2");

  // TODO: fix these scenarios
  DecimalToHex(0, "0");
  // DecimalToHex(-1, "FFFF");
}

void main() {
  EvaluateDecimalToBinary();
  EvaluateDecimalToOctal();
  EvaluateDecimalToHex();
}
