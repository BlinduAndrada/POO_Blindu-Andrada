#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
char a[250][250],t[250];

int main()
{
    int i=0,j,k;
    char s[250];
    char *p;
    scanf("%[\n]s",s);
    p=strtok(s," ");
   while(p)
   {
      strcpy(a[i],p);
      i++;
      p=strtok(NULL," ");
   }

    for(j=0;j<i-1;j++)
        for(k=j+1;k<i;k++)
        if(strlen(a[j])<strlen(a[k]))
        {
            strcpy(t,a[j]);
            strcpy(a[j],a[k]);
            strcpy(a[k],t);
        }
    for(j=0;j<i;j++)
    printf("%s\n", s[i]);
}
