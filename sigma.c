#include <stdio.h>
#include <stdlib.h>

int sigma(int);


int main(void)
{
int m ;
printf("Enter an integer:\n");
scanf("%i",&m);
int answer = sigma(m);
printf("%i \n",answer);

}


int sigma(int n)
{
if(n == 0) return 0 ;
if(n == 1) return 1 ;
else return (n + sigma(n-1));
}
