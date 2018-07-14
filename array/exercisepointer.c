/* |astr.c|: pointer-exercising code */

#include <stdio.h>

void  astr(const char ** s4);



void
astr( const char** s4 )
{
    printf("invocation of %s \n", *s4);
}

int
main()
{
    const char * s1 = "zero";
    const char * s2 = "infinity";
    astr(&s1);
    astr(&s2);

}
