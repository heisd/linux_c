#include <stdio.h>
#include "head.h"
int add(int a,int b){
    return a+b;
}
void fun1(void) {
    printf("Hello from fun1!\n");
    int a=add(3,4);
    printf("3+4=%d\n",a);
}
