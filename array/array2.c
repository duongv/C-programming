#include <stdio.h>
#include <string.h>

char v[][80] = { "viet is a nice guy ", "viet is a hot boy " , " viet is a cool guy"};

find_name(char search_for[])
{
    int i ;
    for (i = 0 ; i < 3; i++)
    {
      if (strstr(v[i],search_for))
      printf("%s",v[i]);
    }
}



int main()
{

char search_for[80];
printf("search for : ");
scanf("%s",&search_for);
find_name(search_for);
return 0 ;

}
