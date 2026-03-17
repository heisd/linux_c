#include "assert.h"
unsigned int div(unsigned int a,unsigned int b){
  assert(b != 0);
  return a / b;
}