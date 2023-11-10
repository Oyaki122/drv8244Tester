#include <mbed.h>

asm(".global _printf_float");
using ThisThread::sleep_for;

int main() {
  // put your setup code here, to run once:

  while (1) {
    // put your main code here, to run repeatedly:
    printf("Hello World!\n");
    sleep_for(1000);
  }
}