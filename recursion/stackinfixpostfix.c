#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct stack
{
    int top ;
    int data[MAX];
}stack;

int empty(stack * s)
{
    if (s->top == -1)
        return (1);
    else
        return (0);
}

int full(stack * s)
{
    if (s->top == MAX -1)
        return (1);
    else
        return (0);
}

void push (stack * s,char c )
{
    if (!full(s))
    {
        s->top = s->top + 1 ;
        s->data[s->top] = c ;
    }
    else
        printf("IT is full sorry");
}
char pop(stack * s )
{
    char  x ;
    x = s->data[s->top];
    s->top = s->top -1 ;
    return x ;
}

int priority (char c)
{   if ( c =='(')
        return (0);
    else if (c =='+' || c =='-')
        return (1);
    else if ( c =='*' || c == '/' || c == '%')
        return (2);
     else
        return (3);

}



void initial(stack * s )
{
    s->top = -1 ;
}


int main ()
{
    stack c ;
    char x ;
    int token ;
    initial(&c);
    printf("Enter a infix expression : ");
    while ((token=getchar()) !='n')
    {
        if (isalnum(token))
        {
            printf("%c",token);
        }
        else
        {
            if( token =='(')
                push(&c,'(');
            else
            {
                if (token == ')')
                    while((x=pop(&c)) != '(')
                {
                    printf("%c",x);
                }
                else
                {
                    while(priority(token) <= priority(c.data[c.top]) && ! empty(&c))
                        x = pop(&c);
                        printf("%c",x);
                }
                push(&c,token);
            }
        }


    }
    while(!empty(&c))
    {
        x = pop(&c);
        printf("%c",x);
    }
}


















