#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct stack
{
    int top ;
    char data [MAX];
}stack;

int empty(stack *s)
{
    if (s->top == -1)
        return (1);
    else
        return(0);
}

int full(stack *s)
{
    if (s->top==MAX-1)
        return (1);
    else
        return(0);
}

void push(stack *s,char c)
{   if (!full(s))
    {
        s->top = s->top + 1 ;
        s->data[s->top] = c ;
    }
    else
    {
        printf("stack over flow1 \n");

    }
}

char pop(stack *s)
{   char x ;
    if (!empty(s))
    {
    x = s->data[s->top] ;
    s->top = s->top - 1 ;

      return x ;
    }
    else
    {
         printf("stack is empty");
    }


}

int main ()
{   stack d ;
    char e [10] ;
    d.top = -1 ;
    scanf("%s",e);
    int len ;
    len = strlen(e);
    int i ;

    for (i = 0 ; i < len ; i++)
    {   if (!full(&d))
        {
            push(&d,e[i]);
        }
        else
        {
            printf("stack over flow \n");
        }

    }
    while (!empty(&d))
    {
      m = pop(&d)  ;
      printf("%c",m);
    }
}
