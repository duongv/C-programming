#include <stdlib.h>
#include <stdio.h>


typedef struct island {
    char *names ;
    char *opens ;
    char *closes;
    struct island *next;
} island ;

void display(island *start)

{
    island *i = start;
    for(; i != NULL ; i = i->next)
    {
        printf("%s, %s, %s \n",i->names, i->opens,i->closes);
    }

}

island* create (char *name)
{
    island *i = malloc(sizeof(island));
    i->names = name ;
    i->opens = "9.00";
    i->closes = "12:00";
    i->next = NULL ;
    return i ;
}


int main()
{
    island *p0 = create("Viet");
    island *p1 = create("viet1");
    island *p2 = create ("viet2");
    p0->next = p1 ;
    p1 -> next = p2 ;
    display(p0);
}
