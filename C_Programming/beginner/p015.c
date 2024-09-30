#include<stdio.h>
int main()
{
int x,y,z;
 x=y=z=3;
z=y+=x=-z;
printf("x=%d y=%d z=%d",x,y,z);
}
