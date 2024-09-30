#include<stdio.h>
int main(){
int x,y,z;
x=y=z=10;
y-=x--;
z-=--x;
x-=--x-x--;
printf("y=%d z=%d x=%d",y,z,x);
}
