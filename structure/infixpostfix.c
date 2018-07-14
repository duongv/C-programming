#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 20


typedef struct stack
{
    int top ;
    char data [MAX];
}sstack;

// function
int empty(sstack * s);
int full(sstack * s);
void push(sstack* s,char c);
char pop(sstack * s);
int isOperand(sstack * s);
char peek (sstack * s);
void infixtopostfix(sstack b, char s[20]);
int pre(char c);
char topelement(sstack * s);

int main()
{   int i ;

    sstack  b ;
    char s [20] = "a*(b+c)";
    int x = strlen(s);
    infixtopostfix(b,s);
}

int empty(sstack *s)
{
    if (s->top == -1)
        return (1);
    else
        return(0);
}

int full(sstack *s)
{
    if (s->top==MAX-1)
        return (1);
    else
        return(0);
}

void push(sstack *s,char c)
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


int pre (char c)
{
    if(c == '(')
        return 0 ;
    if (c == '+' || c == '-')
        return 1 ;
    if (c == '*' || c == '/')
        return 2 ;
    if ( c == '^')
        return 3 ;
}

char topelement(sstack * s)
{
    return s->data[s->top];

}

char pop (sstack * s)
{
    char x = s->data[s->top];
    s->top = s->top - 1;
    return x ;
}

void infixtopostfix(sstack b,char s[20])
{

    int i,k ;
    char x ;
    for (i = 0 , k = -1 ; s[i]; i++)
    {
    // check if it is an operand ( 1 ,2 , 3 or a ,b ,c)
    if (isalnum(s[i]))
        s[++k] = s[i];
    // check the left paren , push on stack
    else
        {
        if (s[i] == '(')
        {
            push(&b,s[i]);
        }
    // check the right paren , pop the stack until it meets the left paren
        else
        {
            if (s[i] == ')')
            {
                while(topelement(&b) != '(' && !empty(&b))
                {
                    s[++k] = pop(&b);
                }

            }
            else
            {
                while(pre(s[i]) <= pre(topelement(&b)) && !empty(&b)  )
                {
                    s[++k] = pop(&b);
                }
            push(&b,s[i]);
            }
        }
        }
        }

    while(!empty(&b) )
    {
        s[++k]= pop(&b);
    }

    s[++k] = '\0';
    printf("%s",s);


}








