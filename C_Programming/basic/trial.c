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

// Function to list all the cars
void read_car_node(car_node *node_head){
    /*while(node_head!=NULL){	        
		printf("%s\n",temp->data);

	}*/
	for( car_node *temp=node_head;temp!=NULL;temp=temp->next_car)
        printf("%s\n",temp->data);
}

// Function to delete car
car_node* delete_car_node(car_node* head)
{
    // If the list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // If the list has only one node, delete it and return
	if (head->next_car == NULL){
		free(head);
        return NULL;
	}

	struct car_node* second_last = head;
    while (second_last->next_car->next_car != NULL) {
        second_last = second_last->next_car;
    }

    // Delete the last node
    free(second_last->next_car);

    // Change next of second last
    second_last->next_car = NULL;

    return head;
}

int main(){
	car_node *first=create_car_node("honda");
	first->next_car=create_car_node("toyota");
	first->next_car->next_car=create_car_node("nissan");
	first->next_car->next_car->next_car=create_car_node("mazda");
	first->next_car->next_car->next_car->next_car=create_car_node("subaru");
	
	printf("1.Create/Add \n");
	printf("2.Delete last entry\n");
	printf("3.Print \n");

	int choice;
	scanf("%d",&choice);

	switch(choice){
		case 1:{
			break;
		}
		
		case 2:{
			printf("\nList after removing the last node: \n");
			first = delete_car_node(first);
			read_car_node(first);
			break;
		}
		
		case 3:{
			read_car_node(first);
			break;
		}
	}
	return 0;
}
