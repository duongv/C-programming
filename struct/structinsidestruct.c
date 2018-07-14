#include <stdlib.h>
#include <stdio.h>

struct preferences
{
    const char* food ;
    float hours ;
};

struct fish
{
    const char* name ;
    int age ;
    int tooth ;
    struct preferences p  ;
};
void print_out(struct fish f){

printf("%s,  %d  ,%d , %s , %f",f.name,f.age,f.tooth,f.p.food,f.p.hours);

}
int main()
{
    struct fish f1 = {"viet",3,2,{"d",4}};
    struct fish f2 = {"viet1",2,2,{"d1",5}};
    print_out(f1);
    //print_out(f2);
}
