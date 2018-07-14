#include <stdio.h>

int main()
{
    char b ;
    printf("Enter your grade : \n");
    scanf("%s",&b);

    switch(b)
    {
    case 'A':
        printf("Good job");
        break;
    case 'B':
        printf("OK");
        break;
    case 'C':
        printf("alright");
        break;
    default :
        printf("Unacceptable");

    }
}
