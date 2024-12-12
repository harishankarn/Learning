#include<stdio.h>
#include<stdlib.h> 

// Defining car_node struct
typedef struct car_node{
	char *data; 
	struct car_node *next_car;

}car_node;

// Joining the nodes into a singly linked list 
car_node *create_car_node(char *carName){
	car_node *new_car_node=( car_node *)malloc(sizeof( car_node));
	strcpy(new_car_node->data,carName);

	new_car_node->data=carName;
	new_car_node->next_car=NULL;	

	return new_car_node;
}

// Function to list all the cars
void read_car_node(car_node *head){
	for( car_node *temp=head;temp!=NULL;temp=temp->next_car)
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
	/*first->next_car=create_car_node("toyota");
	first->next_car->next_car=create_car_node("nissan");
	first->next_car->next_car->next_car=create_car_node("mazda");
	first->next_car->next_car->next_car->next_car=create_car_node("subaru");*/

	car_node *first=NULL;

	while(1){
		printf("1.Create/Add \n");
		printf("2.Delete last entry\n");
		printf("3.Print \n");

		int choice;
		scanf("%d",&choice);

		switch(choice){
			case 1:{
				char *car_name = (char *)malloc(sizeof(char));
				printf("Enter car name:");
				scanf("%s",car_name);
				
				first=create_car_node(car_name);
			//	printf("%s\n",first);

				//printf("%s\n",first->next_car->next_car);
				//printf("%s\n",first->next_car->next_car->next_car);
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
	}
	return 0;
}
