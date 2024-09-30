#include<stdio.h>
int main()
{
double x=3,y,z;
z=y=x;
z/=y*=x;
printf("x=%f y=%f z=%f",x,y,z);
}
