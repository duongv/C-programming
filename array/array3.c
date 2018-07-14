#include <stdio.h>
#include <stdlib.h>

int main()
{
    char names [] = { 'a','b','c','d','e','f'} ;
    int i ;
    int l = sizeof(names)/sizeof(*names);
    for ( i = 0 ; i < l ; i++)
        {
        printf("%c \n", *(names + i)) ;
    }

}
