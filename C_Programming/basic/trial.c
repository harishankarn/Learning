#include<stdio.h>
#include<stdlib.h> 
#include <unistd.h> 

// Defining car_node struct
typedef struct car_node{
	char *data; 
	struct car_node *next_car;

}car_node;

// Follow C.R.U.D principle
// (Create)
// Creates a node 
car_node *create_car_node(char *carName){
	car_node *new_car_node=( car_node *)malloc(sizeof( car_node));

	new_car_node->data=carName;
	new_car_node->next_car=NULL;	

	return new_car_node;
}

// (Read)
// Function to list all the cars
void read_car_node(car_node *head){
	printf("--------------------\n");
	printf("Cars in the list are:\n");
	for( car_node *temp=head;temp!=NULL;temp=temp->next_car)
        printf("%s\n",temp->data);
	printf("--------------------\n\n");
}	


//(Update)
// Function to join a node at the end of list
car_node* append(car_node *head, char* new_data){
	car_node *new_car_node=create_car_node(new_data);

	car_node *last = head;

	if (head == NULL)
    {
       return new_car_node;
    }  

	while(last->next_car!=NULL){
		last=last->next_car;
	}

	// last = last->next_car;
	last->next_car = new_car_node;
	return head;
}

// (Delete)
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

// Main function
int main(){

	car_node *first=NULL;

	while(1){

		system("clear");
		printf("--------------------\n");
		printf("1.Create new list\n");
		printf("2.Add to existing list\n");
		printf("3.Print \n");
		printf("4.Delete last entry\n");
		printf("--------------------\n");

		int choice;
		printf("Enter your choice:");
		scanf("%d",&choice);



		switch(choice){
			case 1:{
				printf("\nCreating new list\n");
				char *car_name = (char *)malloc(sizeof(char));
				if (car_name == NULL) {
					printf("Memory not allocated.\n");
					break;
				}
				printf("Enter car name:");
				scanf("%s",car_name);
				first=create_car_node(car_name);
				break;
			}
			
			case 2:{
				printf("\nAdding to existing list\n");
				char *carName = (char *)malloc(sizeof(char));
				if (carName == NULL) {
					printf("Memory not allocated.\n");
					break;
				}
				if (first == NULL) {
					printf("List is empty. Please create a list first.\n");
					sleep(2);
					break;
				}
				printf("Enter car name:");
				scanf("%s",carName);
				append( first,carName);
				break;	
			}
			
			case 3:{
				if (first == NULL) {
					printf("List is empty. Please create a list first.\n");
					sleep(2);
					break;
				}
				read_car_node(first);
				sleep(2);
				break;
			}

			case 4:{
				if (first == NULL) {
					printf("List is empty. Please create a list first.\n");
					sleep(2);
					break;
				}
				printf("\nList after removing the last node: \n");
				first = delete_car_node(first);
				read_car_node(first);
				sleep(2);
				break;
			}

			default:{
				printf("Invalid input");
			}
		}
		
	}
	return 0;
}
