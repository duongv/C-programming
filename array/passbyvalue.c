#include <stdlib.h>
#include <stdio.h>

int i ;
int a[2];

int p (int *x , int *y)

{
   x = x + 1 ;
   y = y + 1 ;
}

int main()
{
    a[0] = 1 ;
    a[1] = 2 ;
    i = 0 ;
    p(&a[i],&a[i]);

}
