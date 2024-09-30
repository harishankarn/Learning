#include<stdio.h>
int main()
{
int i=1,j=1;
for(;j<=5;j=i++)
{
printf("%d%d\n",i,j);
//j=i++;
}
}
