#include <stdlib.h>
#include <stdio.h>

typedef struct viet
{
    const char* name ;
    const char* species ;
    int age ;

}turtle;

void change(turtle* f)
{
    f->age = f->age + 1 ;
    printf("turtle is %d",f->age);
}


int main()
{
turtle t = {"viet","v",5};
change(&t);

printf("turtle is %d",t.age);


}
