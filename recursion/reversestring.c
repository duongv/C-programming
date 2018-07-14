#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reversestr ( char * s)
{

    int l = strlen(s);
    int i ;
    for ( i = l -1 ; i >= 0 ; i--)
    {
    printf("%c",s[i]);
    }

}

int main ()
{   char* p  = "cute" ;
    reversestr(p);
    //printf(s);
}
