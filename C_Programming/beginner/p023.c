#include<stdio.h>
int main(){
int x=0,j;
for(j=0;j<=5;j++)
{
switch(j-1)
{
case -1:x+=1;break;
case 0:
case 1:
case 2:
case 3:x+=2;break;
default:x+=3;
}
printf("%d",x);
}
}
