#include <stdlib.h>
#include <stdio.h>

struct fish
{
    char* name ;
    int age ;
    int teeth ;
};

void print_out(struct fish v[],int length)
{
    int i ;
    for(i = 1 ; i < length + 1 ; i ++)
    {
          printf("fish %d is : %s , %d , %d \n",i - 1,v[i].name,v[i].age,v[i].teeth);
    }



}


int main ()
{
struct fish f1 =  {"viet",12,12};
struct fish f2 =  {"viet1",13,13};
struct fish f3 =  {"viet2",14,14};
struct fish f4 =  {"viet3",15,15};

//print_out(f1);
//print_out(f2);
//print_out(f3);
struct fish v [] = {f1,f2,f3,f4};
int length = sizeof v / sizeof v[0] ;
print_out(v,length);
}
