#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{
    char* str;
    str = malloc(20);
    strcpy(str,"vietdsfas");
    printf("%s, %u",str,str);
    free(str);



}
