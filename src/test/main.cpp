#include "breakpadlite.h"

void crash() { volatile int* a = (int*)(0); *a = 1; }

int main(int argc, char* argv[]) {
  regExceptionHandler();
  crash();
  return 0;
}