#include <stdio.h>
#include <stdlib.h>
#define MAX 20


typedef struct stack_pointer
{
    int top ;
    int data [MAX];
} stack;

int empty(stack * d);
int full (stack * d);
void push(stack* d , int key);
int pop(stack *d);
void print_out(stack *d);
void binary(stack *d , int x);

int main()
{
    stack k ;
    k.top = -1;
    binary(&k,5);
    print_out(&k);
    return 0 ;
}

int empty(stack * d)
{
    if(d->top == -1) return 1 ;
    else return 0 ;
}

int full(stack * d)
{
    if(d->top == MAX - 1)  return 1 ;
    else return 0 ;

}

void push(stack * d, int key)
{
    if( !full(d))
    {
        d->top =d->top + 1 ;
        d->data[d->top] = key;
    }
    else
    printf("stack overflow");

}

int pop(stack *d)
{
    if(!empty(d))
    {
        int k ;
        k = d->data[d->top];
        d->top = d->top - 1 ;
        return k;
        }
    else
        printf("empty stack");

}
void print_out(stack * d)
{
    int m ;
    while(!empty(d))
    {
        m = pop(d);
        printf("%d",m);
    }
}

void binary (stack *d , int x)
{
    while(x > 0)
    {
        int m = x % 2 ;
        push(d,m);
        x = x / 2 ;
    }
}





















