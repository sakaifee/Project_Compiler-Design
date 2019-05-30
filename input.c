
#include<stdio.h>

int main(int argc,char *argv[])
{
int y;
int a = 4;
int b = 2;
int x = a + b;
y = a * b;
if (y > a)
 {
 a= a + 1;
 x = a + b;
 }
 else{
 	a=1;
 }
 return 0;
 }
