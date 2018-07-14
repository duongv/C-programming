# include <stdio.h>
# include <stdlib.h>


typedef struct node
{
    int key ;
    struct node * next ;
}snode ;

// function implementation
struct node * new_node(int x);
void push(snode** s, int x);
int empty(snode* s);
void print_out(snode *s);
int pop(snode* s);

// main function
int main()
{
    snode * n ;
    push(&n,1);
    push(&n,2);

    print_out(n);


return 0 ;
}

struct node* new_node(int x)
{
    snode* s = malloc(sizeof(snode));
    s->key = x ;
    s->next = NULL ;
    return s ;
}

int empty(snode * s)
{
    if (s == NULL)  return 0 ;
    else return 1 ;
}
// push item to the stack
void push (snode** s, int x)
{
    snode * nnode = new_node(x);

    if (*s == NULL)
    {
        *s = nnode;
    }
    else
    {
        nnode->next = *s ;
        *s = nnode;
        printf("%d is pushed to the stack \n",(*s)->key);
    }
}
// pop item from stack
int pop(snode * s)
{
    int m ;
    snode * temp ;

    if (s == NULL)
    {
        printf("STACK IS EMPTY");
        return 0 ;
    }
    else
    {
         temp = s ;
         s = s->next;
         m = temp->key;
         printf("%d is poped from stack",temp->key);
         free(temp);
         return m ;
    }

}




}


