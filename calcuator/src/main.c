#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"
extern unsigned int add(unsigned int a, unsigned int b);
extern unsigned int sub(unsigned int a, unsigned int b);
extern unsigned int mul(unsigned int a, unsigned int b);
extern unsigned int div(unsigned int a, unsigned int b);
int main(){
    printf("input two numbers: ");
    unsigned int x, y;
    scanf("%u %u", &x, &y);
    printf("add: %u\n", add(x, y));
    printf("sub: %u\n", sub(x, y));
    printf("mul: %u\n", mul(x, y));
    printf("div: %u\n", div(x, y));
    return 0;
}