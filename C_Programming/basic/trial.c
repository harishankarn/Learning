#include<stdio.h>
#include<stdlib.h> 

// Defining car_node struct
typedef struct car_node{
	char *data; 
	struct car_node *next_car;

}car_node;

// Joining the nodes into a singly linked list 
car_node *create_car_node(char *data){
	car_node *new_car_node=( car_node *)malloc(sizeof( car_node));
    new_car_node->data=data;

	return new_car_node;
}

void list_car_node(car_node *node_head){
	printf("list:\n");
    for( car_node *temp=node_head;temp!=NULL;temp=temp->next_car)
        printf("%s\n",temp->data);
}

int main(){
	car_node *first=create_car_node("honda");

	first->next_car=create_car_node("toyota");
	first->next_car->next_car=create_car_node("nissan");

	list_car_node(first);

	return 0;
}
