#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef union data1{
int a ;
char* b ;
}data;

typedef struct viet1{
int f ;
data d;
} viet ;


int main (){

viet v ;
v.f = 5 ;
v.d.b = "Viet";


printf("%d , %s",v.f, v.d.b);
}
