#include<stdio.h>
#include<stdlib.h> 

typedef struct car_node{
	char *data; 
	struct car_node *next_car;

}car_node;

car_node *create_car_node(char *data){
	car_node *new_car_node=( car_node *)malloc(sizeof( car_node));
    new_car_node->data=data;

	return new_car_node;
}

int main(){
	car_node *first=create_car_node("honda");

	first->next_car=create_car_node("toyota");
	first->next_car->next_car=create_car_node("nissan");

	printf("list:\n");
	for( car_node *temp=first;temp!=NULL;temp=temp->next_car)
		printf("%s\n",temp->data);

	return 0;
}
