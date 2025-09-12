#include <stdio.h>
#include <unistd.h>
int main(int argv,char *agrv[]){
   for (int i = 0; i < argv; i++)
   {
        printf("%d:%s\n",i,agrv[i]);
   }
   sleep(100);
   return 0;
}