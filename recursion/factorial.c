#include <stdlib.h>
#include <stdio.h>

// prototype
int factorial(int n);

int main()
{
    printf("Enter a number : ");
    int m ,n ;
    scanf("%d",&m);
    n = factorial(4);
    printf("%d ! is %d",m,n) ;

}


int factorial(int n)
{
    if(n == 0) return 0 ;
    if(n == 1) return 1 ;
    else return ( factorial(n-1)* n);
}


