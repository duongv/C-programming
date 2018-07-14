#include <stdlib.h>
#include <stdio.h>

typedef struct dlinklist
{
    int value ;
    struct dlinklist *pre ;
    struct dlinklist *next ;
}dnode;

dnode * head ; //

dnode* getNode(int x)
{
    dnode* newnode ;
    newnode = malloc(sizeof(dnode));
    newnode->value = x ;
    newnode->next = NULL ;
    newnode->pre = NULL;
}

void print_out(dnode* head)
{
    dnode* current = head ;

    while(current!= NULL )
    {
        printf("%d \n",current->value);
        current = current ->next;
    }

}

void print_reverse(dnode * head)
{

    dnode * current = head ;
    while ( current ->next != NULL)
    {
        current = current -> next ;
    }

    for (;current != NULL;current->next)
    {
        printf("%d \n",current->value);
        current  = current ->pre;
    }

}
void inserthead(int x)
{
    dnode* newnode = getNode(x);
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next= head;
        head->pre = newnode;
        head = newnode;
    }
}

void insertbottom (int x)
{
    dnode* newnode = getNode(x);
    dnode* current = head;
    if (head == NULL)
    {
        head = newnode;
    }
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newnode;
    newnode->pre = current;
    newnode->next = NULL ;
}

void removehead(dnode** head)
{
 dnode * current = *head ;

 *head = current->next ;
}

void specific_remove(int n)
{
    dnode * current = head ;
    if (n == 0)
    {
        removehead(&head);
    }
    else if ( current ->next != NULL )
    {   int i ;
        for(i = 0 ; i < n - 1 ; i++)
        {
            current = current ->next ;
        }
        current->next = current->next->next ;
        current-> next ->pre = NULL;
    }
    else
    {
        printf("It is the last item of the list");
    }
}
dnode * elementremove(dnode* head, int n)
{
    dnode * temp ;

    if(head == NULL)
    {
        printf("does not match anything \n");
        return NULL ;
    }
    if(head ->value == n )
    {
        temp = head ->next ;
        //free(head);
        temp ->pre = head ->pre ;
        free(head);
        //head = temp ;
        return temp ;
    }
    else
    {
        elementremove(head->next,n);
    }
return head ;
}
// using loop
int counting(dnode* head)
{
    dnode *current = head ;
    int count = 0 ;
    while( current != NULL)
    {
        current = current ->next ;
        count++;
    }
    return count ;
}
int recursive_counting(dnode* head)
{
    if(head == NULL)
    {
        return 0 ;
    }
    else
    {
        return (1 + recursive_counting(head->next));
    }
}

int main()
{
    head = NULL ;
    inserthead(4);
    inserthead(3);
    inserthead(2);
    insertbottom(5);
    insertbottom(6);
    print_out(head);
    printf("------------------------\n");
    //removehead(&head);
    //removehead(&head);
    print_reverse(head);
//    printf("ENter the element need to remove : ");
//    int n ;
//    scanf("%d",&n);
//    specific_remove(n);
//    print_out(head);
    printf("------------\n");
   // elementremove(head,2);
   // print_out(head);
    int m ;
    int n ;
   m = counting(head) ;
   printf("%d \"it is from loop \"  \n ",m);
   n = recursive_counting(head);
   printf("%d\"it is from recursive \" ", n);
   printf("--------------- \n");



//   int i ;
//   for(i = 0 ; i < 50 ; i++)
//   {
//        inserthead(i);
//   }
//
//    print_out(head);

}
