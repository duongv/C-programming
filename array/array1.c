#include<stdio.h>
#include<stdlib.h>

int main()
{
    int balance [] = {1,2,3,4,5};

    int * v  ;
    int i ;
    v = balance ;
    printf("the first element is %i \n", *v);



    for(i= 0 ; i < 5 ; i++)
    {

        printf("the number %d is %d \n",i,*(balance + i));
    }
int a = sizeof(balance)/sizeof(*balance) ;
    printf ("size of array is %d",a);
}
