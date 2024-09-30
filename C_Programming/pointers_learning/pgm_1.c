#include<stdio.h>

void swap(int *px,int *py);
void swap(int *px,int *py){
	int temp;
	temp=*px;
	*px=*py;
	*py=temp;	
}
int main(){
	int a=88,b=99,x=1,y=2,z[10];
	z[0]=5;
	int *ip; //ip is a pointer to int

	ip=&x; //ip now points to x

	y=*ip; //y now has ip value which has x value which is 1

	*ip=0; //ip now equals 0 which is pointed to x which is now 0
	ip = &z[0]; //ip now hsa value of z[0] which is 5
	
	*ip+=10;

	swap(&a,&b);

	printf("x=%d y=%d z=%d\n",x,y,z[0]);
	printf("a=%d b=%d\n",a,b);
	return 0;
}
