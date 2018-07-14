#include <stdio.h>
#include <stdlib.h>

void swap (int* a , int* b)
{
    int temp ;
    temp = *a;
    *a = *b;
    *b = temp ;
}


int main()
{

int a = 10 ;
int b = 20 ;
printf("Before swap : %d and %d\n",a,b);
swap(&a,&b);
printf("After swap: %d and %d",a,b);

}


