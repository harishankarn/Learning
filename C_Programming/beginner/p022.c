#include<stdio.h>
int main(){
int i;
for (i=-1;i<=10;)
{
if (i<5)
i++;
else
break;
}
printf("Gets printed only once");
}
