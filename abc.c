#include <stdio.h>
#include <string.h>
typedef struct tripleaddresscode{
       char* op;
       char* arg1;
       char* arg2;
       char* result;
        }icg[30];
char * b= "abc";
icg[0].op=strdup(b);

int main()
{
printf("%s",icg[1].op);
}
