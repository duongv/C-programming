#include <stdio.h>
#include <string.h>


int main (void)
{
    int result;
    char str[20] ;
    scanf("%c",str);
    int length = strlen (str);
    result = isPalindrome (str,length);/*The function isPalindrome is called.It takes a string
    argument and returns a value 0 or 1 which is stored in
    the integer variable "result"*/
    if (result==1)
        printf ("\n******Input string %s is a palindrome string.************\n",str);
    else
        printf ("\n******Not a palindrome******\n");
    return 1;
}



int isPalindrome (char str[],int  length)
{

    if (length<=0)
        return 1;
    if (str[0] == str[length-1])
    {

        return isPalindrome (str+1, length-2);/*Recursive call as the function isPalindrome
        is called again within itself*/
    }
    else return 0;
}


