#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int value ;
    struct node * next ;
}node;

/*print a node*/
void print_out(node * head)
{   node *i = head ;
    if(head == NULL)
    {
        printf("NOTHING");

    }
    for(;i != NULL ; i = i ->next )
    {

        printf("%d \n",i->value);
    }
}

/* create a node*/
node * create_node(int value)
{
    node * head = malloc((sizeof(node)));
    head->value = value ;
    head->next = NULL;
    return head ;
}

/*adding an item to the list */
void addNodeBottom(int val, node **head){

    //create new node
    node *newNode = malloc(sizeof(node));
    newNode->value = val;
    newNode->next = NULL;

    if(*head == NULL)
    {
        *head = newNode;
        newNode->next = NULL ;
    }
    else
    {
        node *current = *head;
        while (current->next != NULL) {
        current = current->next;
    }
        current->next = newNode;
    }
}
// remove the first item in the list//
void headremove(node** head)
{
int value ;
node *nextnode = NULL ;
if(*head == NULL)
{
    printf("there is nothing here");

}
else
{
    nextnode = (*head)->next;
    free(*head);
    *head = nextnode;
}

}
// remove the last item in the list//

void tailremove(node** head)
{
    node* current = *head;
    while(current->next->next != NULL)
    {
        current = current->next;
    }
    free(current->next);
    current->next= NULL;
}

//adding an item to the front of the list//
void addfront(node** head, int value)

{    node* d = malloc(sizeof(node));
     d ->value = value;
    if( *head== NULL)
    {
        *head = d ;
        d->next = NULL;
    }
    else
    {
        d->next = *head;
        *head = d ;
    }


}
void accesselement(node *head,int n)
{
    int i ;
    node* current = head;
    for(i = 0 ; i < n ; i++);
    {
         current = current->next;
    }
    printf("the element number %d is %d",n,current->value);
}

//remove item with its index..
int check_list(node * head)
{
    if (head == NULL)
        return 1 ;
    else
        return 0 ;
}

void removeindex(node** head, int index)
{
    int i ;
    node* current = *head;
    node* temp ;
    if(index == 0)
    {
       headremove(head);
    }
    else
    {
        for(i = 0 ; i < index - 1 ; i++ )
            {
            current = current->next;
            }
        temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}
void localreference(node *head1)
{
        node* d = head1 ;
        node** pointer = &d ;
        int i ;
        for(i = 1 ; i < 6 ; i++)
        {
            addNodeBottom(i,pointer);
        }
}

int Counted(node* head, int x)
{

    node* temp = head ;
    int count = 0 ;
    while(temp != NULL)
    {
        if(temp->value == x)
        {
            count++ ;
        }

    temp = temp -> next ;

    }
 return count ;
}

int getNth(node * head,int x)
{
    node * current = head ;
    int i ;
    for(i = 0 ;i < x; i ++ )
    {
        current = current->next;
    }
return current->value ;
}

void DeleteList(node** head)
{   node* current = *head ;
    while(current != NULL)
    {
        free(current);
        current = current->next;
    }
    *head = NULL ;

}

void push (node** head, int value)
{
    node* newnode = malloc(sizeof(node));
    newnode->value = value ;
    newnode->next = (*head);
    (*head) = newnode ;

}

void insertNth(node**head, int index , int value)
{
//    node* new_node = getNode(value);
    node* current = *head;
    node* newnode = malloc(sizeof(node));
    newnode->value = value ;
    node* temp ;

    if(index == 0)
    {
        addfront(head,value);
    }
    else
    {
        int i ;
        for(i = 0 ; i < index -1  ; i++)
        {
            current = current->next ;
        }
      push(&(current->next),value);

    }
}
      // current->next->next = newnode->next  ;
void SortedInsert(node** head, node * newnode)
{
    node* current = *head ;
    if(newnode->value < (*head)->value || (*head) == NULL )
   {
    newnode->next = *head ;
    *head = newnode ;

    }
    else
    {
        while(current->next != NULL && newnode->value > current->next ->value)
        {
            current = current->next ;
        }
            newnode -> next = current->next;
            current -> next = newnode ;



    }
}
void insertSort(node ** head)
{
    node * result = NULL ;
    node * current = *head ;
    node * next ;

    while(current != NULL)
    {
        next = current->next ;
        SortedInsert(&result,current);
        current = next;
    }

    *head = result ;


}




int main()
{
//    node *t = malloc(sizeof(node));
//    t->value = 1 ;
//    t->next = malloc((sizeof(node)));
//    t->next->value = 2 ;
//    t->next->next = malloc((sizeof(node)));
//    t->next->next->value = 3 ;
//    t->next->next->next = NULL;
//    print_out(t);
//    printf("-------------------\n");
//    addfront(&t,0);
//    print_out(t);
//    printf("--------------------\n");
//    addfront(&t,-1);
//    print_out(t);
//
//    addNodeBottom(4,t);
//    print_out(t);
//    printf("-------------\n");
//    addNodeBottom(5,t);
//    print_out(t);
//    printf("---------\n");
//
//    headremove(&t);
//    print_out(t);
//    tailremove(&t);
//    print_out(t);
//    printf("---------\n");
//    //removeindex(&t,2);
//    //print_out(t);
//    accesselement(t,1);

   node* t  = NULL;
   //addfront(&t,5);
   //print_out(t);
   addNodeBottom(6,&t);
   addNodeBottom(7,&t);
   addNodeBottom(8,&t);
   addNodeBottom(6,&t);
   addNodeBottom(6,&t);
   addfront(&t,9);
   print_out(t);
   printf("----------- \n");
//   int m ;
//   m = Counted(t,5);
//   printf("%d",m);
//   printf("--------- \n");
//   int x ;
//   x = getNth(t,0);
//   printf("%d",x);

   //DeleteList(&t);
   //print_out(t);

   printf("\n--------- Here we go\n");
   insertNth(&t,3,10);
   printf("-----------\n");
   print_out(t);

   printf("\n----------------------------------\n");
   node* m = malloc(sizeof(node));
   m->value = 1 ;
   m->next = malloc(sizeof(node));
   m->next->value = 2 ;
   m->next->next = malloc(sizeof(node));
   m->next->next ->value = 4 ;
   m->next->next->next = malloc(sizeof(node)) ;
   m->next->next->next->value = 5;
   m->next->next->next->next = NULL ;
  // push(&m,0);
   node * newnode = malloc(sizeof(node));
   newnode->next = NULL ;
   newnode->value = 0 ;
   SortedInsert(&m,newnode);
    print_out(m);
   printf("\n -------------------------------\n");
   node* k = malloc(sizeof(node));
   k->value = 5 ;
    k->next = malloc(sizeof(node));
   k->next->value = 4 ;
   k->next->next = malloc(sizeof(node));
   k->next->next ->value = 1 ;
   k->next->next->next = malloc(sizeof(node)) ;
   k->next->next->next->value = 2;
   k->next->next->next->next = NULL ;
  // insertSort(&k);
   print_out(k);


//int i ,m ,f;
//printf("Enter a number: \n");
//
//scanf("%d",&i);
//scanf("%d",&m);
//scanf("%d",&f);
//    node *t = create_node(i);
//    node *p = create_node(m);
//    node *k = create_node(f);
//    t->next = p;
//    p->next = k ;
//    pushing(t,4);
//    print_out(t);
}
