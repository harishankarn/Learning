#include<stdio.h>
int main()
{
	int x=10,y=5,a,b;
	//a=x>9;b=x>3 && y!=3;
	a=x>9, b=x>3 && y!=3;
	printf("a = %d b = %d",a,b);
}
