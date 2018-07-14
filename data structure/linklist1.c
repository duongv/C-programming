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
int main()
{
    island v = {"v", "2:00","3:00",NULL};
    island t = {"t", "3:00", "4:00",NULL};
    island f = {"f", "4:00", "5:00", NULL};
    v.next = &t;
    t.next = &f;
    display(&v);
    printf("--------------------------- \n");
    island m = {"m","4:00","7:00",NULL};
    t.next=&m;
    m.next=&f;
    display(&v);
}
