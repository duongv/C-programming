#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
//nlr
void preorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->key);
        inorder(root->left);
        inorder(root->right);
    }
}

struct node* lookup(struct node* root , int data)
{
    if(root->key == data || root == NULL)    return root ;
    else if(data < root->key)   return lookup(root->left,data);
    else if(data > root->key)   return lookup(root->right,data);
    //else return false ;
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

int size(struct node* root)
{
    if(root == NULL) return 0 ;
    else return 1 + size(root->left) + size(root->right);
}

// finding the longest path.
int maxDepth(struct node * root)
{
    if(root == NULL)
    {
        return 0 ;
    }
    else
    {
        int x = 1 + maxDepth(root->left);
        int y = 1 + maxDepth(root->right);
        if( x > y)  return x ;
        else return y ;

    }
}

//finding min value
int minValue(struct node * root)
{
    if(root->left == NULL)  return root->key ;
    else return minValue(root->left);
}

// finding max value

int maxValue(struct node * root)
{
    if(root->right == NULL) return root->key ;
    else return maxValue(root->right);
}

int hasPathSum(struct node* root,int sum)
{
    if(root == NULL)
    {
        return (sum == 0);
    }
    else
    {
        int subsum = sum - root->key;
        return (hasPathSum(root->left,subsum) || hasPathSum(root->right,subsum));
    }
}

// private helper (array for each node)
 void printarray(int a [], int length,struct node * root,int x)
{
    int i ;
    printf("Path is %d : ", x);
    for(i = 0 ; i < length ; i++)
    {
        printf("%d ",a[i]);
    }

   printf("\n");
}
//print every path from root to leaf.
void printPaths(struct node* root,int path[],int length,int x)
{

    if(root == NULL)    return ;
    path[length] = root->key;
    length++ ;

    if(root->left == NULL && root->right == NULL)
    {
            printarray(path,length,root,x);
            x++;
    }

    {
        printPaths(root->left,path,length,x);
        printPaths(root->right,path,length,x);
    }

}

void print_path(struct node* root)
{
    int path [1000];
    printPaths(root,path,0,1);
}

// print the longest path from root to leaf.
void print_longestpath(struct node* root,int path[],int length,int m)
{
    if(root == NULL) return ;
    path[length] = root->key ;
    length++ ;

    if(length == m)
    {       printf("Longest ");
            //printarray(path,length,root);
    }

    {
        print_longestpath(root->left,path,length,m);
        print_longestpath(root->right,path,length,m);
    }

}

/*Change a tree so that the roles of the left
and right pointers are swapped at every node.*/
void mirror(struct node* root)
{

    if(root == NULL)
    {
        return ;
    }
    else
    {
        mirror(root->left);
        mirror(root->right);

        struct node* temp ;

        temp = root->right;
        root->right = root->left;
        root->left = temp;
    }
}
/*For each node in a binary search tree,
create a new duplicate node and insert the
duplicate as the left child of the
original node*/
void doubleTree(struct node * root)
{
    if(root == NULL)
    {
        return ;
    }
    else
    {   doubleTree(root->left);
        doubleTree(root->right);

        struct node *temp = root->left;
        root->left = newNode(root->key);
        root->left->left = temp;

    }
}
/*Given two binary trees, return true if they are structurally identical --
they are made of nodes with the same values*/
int sameTree(struct node * a ,  struct node* b)
{
    if(a == NULL && b == NULL)
    {
        return (true);
    }
    else if ( a != NULL && b!=NULL)
    {
        return( a->key == b->key) && sameTree(a->left,b->left) &&
        sameTree(a->right,b->right);
    }
    else
        return false ;
}

// checking if it is binary search tree or not
int isBST(struct node * root)
{
    if(root == NULL)
        return 1 ;
    if(root->left != NULL && minValue(root->left) > root->key )
        return 0 ;
    if(root->right != NULL && maxValue(root->right) < root->key)
        return 0 ;

    if(!isBST(root->left) || !isBST(root->right))
        return 0 ;

    return 1 ;

}
int main()

{
    struct node* a = NULL;
    a = insert(a,5);
    insert(a,1);
    insert(a,2);
    insert(a,3);
    insert(a,6);
    insert(a,4);
    insert(a,0);
   inorder(a);
//    //size(a);
//    printf("-------------\n");
//   // preorder(a);
//    maxDepth(a);
//    minValue(a);
//    hasPathSum(a,12);
//
//    print_path(a);
//    printf("------------ \n");
//    int path[100];
//    int m = maxDepth(a);
//   // print_longestpath(a,path,0,m);
//    mirror(a);
//    printf("--------------");
//    print_path(a);
//
//    struct node* b = NULL ;
//    b = insert(b,2);
//    insert(b,1);
//    insert(b,3);
//    insert(b,4);
//    doubleTree(b);
//    inorder(b);
//
//    struct node* c = NULL ;
//    c = insert(b,2);
//    insert(c,1);
//    insert(c,3);
//    insert(c,4);
//    int n = sameTree(b,c);
//    printf("\n n is : %d",n);
//    isBST(c);
}




