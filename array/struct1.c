#include<stdlib.h>
#include<stdio.h>

typedef struct viet
{
    int m ;
    char* d ;
} v;

int main()
{
   v u1 ;
   v u2 ;

    u1.m = 10 ;
    u1.d = "jjj";

    u2.m = 11 ;
    u2.d = "kkk";

    v uni [] = {u1,u2};
    int i ;
    for ( i = 0 ; i < 2 ; i++)
    {
       printf("%d , %s \n",uni[i].m,uni[i].d);
    }



}
