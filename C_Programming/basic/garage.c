#include<stdio.h>
#include<stdlib.h> 
#include <unistd.h> 
#include <string.h>

// Defining node struct string_node
typedef struct string_node{
    char *car_data;
    struct string_node *next_node;
}string_node;

// Defining car_details struct
typedef struct car_details{
	char *car_type; // car type
	char *car_manufacture; // car manufacture
	char *car_brand; // car name
	char *car_price; // car price
	char *car_range; // car range
}car_details;

// Defining car_node struct
typedef struct car_node{
	car_details *car_data; 
	struct car_node *next_car;
}car_node;

void wait_for_enter() {
    printf("\nPress Enter to continue...");
	getchar();
    while (getchar() != '\n');
}

void string_sorting(car_node *head){
    car_details *temp;
    car_node *current,*next;

    for(current = head; current!=NULL;current=current->next_car){
        for(next=current->next_car;next!=NULL;next=next->next_car){
            if(strcmp(current->car_data->car_brand,next->car_data->car_brand)>0){
                temp=current->car_data;
                current->car_data=next->car_data;
               next->car_data=temp;
            }
        }
    }
}

// (Create)
// Creates a node 
car_node *create_car_node(car_details *carDetails){
	car_node *new_car_node=( car_node *)malloc(sizeof( car_node));

	if (new_car_node == NULL) {
        printf("Memory not allocated for car_node\n");
        return NULL;
    }
	
	new_car_node->car_data=carDetails;
	new_car_node->next_car=NULL;
	
	return new_car_node;
}

// (Read)
// Function to list all the cars
void read_car_node(car_node *head){
	printf("--------------------\n");
	printf("Cars in the list are:\n\n");

 
	for( car_node *temp=head;temp!=NULL;temp=temp->next_car){
		
		printf("Car Type: %s\n", temp->car_data->car_type);
        printf("Car Manufacture: %s\n", temp->car_data->car_manufacture);
        printf("Car name: %s\n", temp->car_data->car_brand);
        printf("Car Price: %s\n", temp->car_data->car_price);
        printf("Car Range: %s\n", temp->car_data->car_range);
		printf("\n--------------------\n\n");
	}
	
}	


//(Update)
// Function to join a node at the end of list
car_node* end_insert(car_node *head, car_details* new_car_data){
	car_node *new_car_node=create_car_node(new_car_data);

	car_node *last = head;

	if (head == NULL)
    {
       return new_car_node;
    }  

	while(last->next_car!=NULL){
		last=last->next_car;
	}

	last->next_car = new_car_node;
	return head;
}

// (Delete)
// Function to delete car from end of list
car_node* last_car_node_delete(car_node* head)
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

	car_node* second_last = head;
    while (second_last->next_car->next_car != NULL) {
        second_last = second_last->next_car;
    }

    // Delete the last node
    free(second_last->next_car);

    // Change next of second last
    second_last->next_car = NULL;

    return head;
}

//Function to delete car according to name
car_node* delete_car_node_by_name(car_node* head, char* carName){
	// If the list is empty, return NULL
	if (head == NULL) {
		return NULL;
	}

	// If the list has only one node, delete it and return
	if (head->next_car == NULL){
		free(head);
        return NULL;
	}
	
	car_node* current = head;
	car_node* previous = NULL;

	if (strcmp(current->car_data->car_brand, carName) == 0){
		head = current->next_car;
		free(current->car_data->car_type);
		free(current->car_data->car_manufacture);
		free(current->car_data->car_brand);
		free(current->car_data->car_price);
		free(current->car_data->car_range);
		free(current->car_data);
		free(current);
		return head;

	}

    while (current != NULL && strcmp(current->car_data->car_brand, carName) != 0) {
		previous = current;
        current = current->next_car;
    }

	previous->next_car = current->next_car;
	free(current->car_data->car_type);
	free(current->car_data->car_manufacture);
	free(current->car_data->car_brand);
	free(current->car_data->car_price);
	free(current->car_data->car_range);
	free(current->car_data);
	free(current);
  	return head;
}

int read_csv_file(char *filename,car_node *head){
	FILE* fp = fopen(filename, "r");
	if(!fp){
		printf("Error opening file\n");
		return 0;
	}

	char csv_row[256];
	while(fgets(csv_row,sizeof(csv_row),fp)){

		car_details *car_data = (car_details *)malloc(sizeof(car_details));
		if(!car_data){
			printf("Memory not allocated\n");
			return 0;
		}

		char *token = strtok(csv_row, ",");
		
        if (token) {
			car_data->car_type = strdup(token); // Use strdup to duplicate token
	        token = strtok(NULL, ",");
		}
        if (token) {
			car_data->car_manufacture = strdup(token);
	        token = strtok(NULL, ",");
		}
        if (token) {
			car_data->car_brand = strdup(token);
	        token = strtok(NULL, ",");
		}
        if (token) {
			car_data->car_price = strdup(token);
	        token = strtok(NULL, ",");
		}
        if (token) {
			car_data->car_range = strdup(token);
		}
		/*printf("Car Type: %s, Manufacture: %s, name: %s, Price: %s, Range: %s\n",
               car_data->car_type,
               car_data->car_manufacture,
               car_data->car_brand,
               car_data->car_price,
               car_data->car_range);*/

		head = end_insert(head, car_data);

	}
	return 0;
}

// Main function
int main(){

	car_node *head=NULL;

	while(1){

		system("clear");
		printf("\n--------------------\n");
		printf("1.Create new list\n");
		printf("2.Add to existing list\n");
		printf("3.Print \n");
		printf("4.Delete last entry\n");
		printf("5.Delete any entry based on name\n");
		printf("6.Read from csv file\n");
		printf("7.Sort the list in alphabetic order\n");
		printf("--------------------\n");

		int choice=0;
		char check;
		printf("Enter your choice:");
		if (scanf("%d%c",&choice,&check) != 2 || choice<=0 || check != '\n'){ // check for valid input
			printf("Invalid input\n");
			while (getchar() != '\n'); // clear input buffer
			wait_for_enter();
			continue;
		}

		switch(choice){
			case 1:{
				printf("\nCreating new list\n");
				car_details *new_car_data = (car_details *)malloc(100*sizeof(car_details));
				if (new_car_data == NULL) {
                    printf("Memory not allocated for car_details\n");
                    break;
                }

				new_car_data->car_type = (char *)malloc(100 * sizeof(char));
				new_car_data->car_manufacture = (char *)malloc(100 * sizeof(char));
				new_car_data->car_brand = (char *)malloc(100 * sizeof(char));
				new_car_data->car_price = (char *)malloc(100 * sizeof(char));
				new_car_data->car_range = (char *)malloc(100 * sizeof(char));

				printf("Enter car type:");
				scanf("%99s", new_car_data->car_type);
				printf("Enter car manufacture:");
				scanf("%99s", new_car_data->car_manufacture);
				printf("Enter car name:");
				scanf("%99s", new_car_data->car_brand);
				printf("Enter car price:");
				scanf("%99s", new_car_data->car_price);
				printf("Enter car range:");
				scanf("%99s", new_car_data->car_range);

				head=create_car_node(new_car_data);

				printf("--------------------\n");

				printf("Car Type: %s\n", head->car_data->car_type);
				printf("Car Manufacture: %s\n", head->car_data->car_manufacture);
				printf("Car name: %s\n", head->car_data->car_brand);
				printf("Car Price: %s\n", head->car_data->car_price);
				printf("Car Range: %s\n", head->car_data->car_range);
				printf("--------------------");
				wait_for_enter();

				break;
			}
			
			case 2:{
				car_details *new_car_data = (car_details *)malloc(100*sizeof(car_details));

				if (new_car_data==NULL){ // Checks if memory is allocated
					printf("Memory not allocated\n");
					break;
				}

				/**/

				new_car_data->car_type = (char *)malloc(100 * sizeof(char));
				new_car_data->car_manufacture = (char *)malloc(100 * sizeof(char));
				new_car_data->car_brand = (char *)malloc(100 * sizeof(char));
				new_car_data->car_price = (char *)malloc(100 * sizeof(char));
				new_car_data->car_range = (char *)malloc(100 * sizeof(char));

				printf("Enter car type:");
				scanf("%99s", new_car_data->car_type);
				printf("Enter car manufacture:");
				scanf("%99s", new_car_data->car_manufacture);
				printf("Enter car name:");
				scanf("%99s", new_car_data->car_brand);
				printf("Enter car price:");
				scanf("%99s", new_car_data->car_price);
				printf("Enter car range:");
				scanf("%99s", new_car_data->car_range);
				head = end_insert( head,new_car_data);
				break;	
			}
			
			case 3:{
				
				if (head == NULL) { // Checks if list is empty
                    printf("List is empty\n");
                    wait_for_enter();
                    break;
                }

				read_car_node(head); 
				getchar();
				wait_for_enter();
				break;
			}

			case 4:{
				
				head = last_car_node_delete(head);

				printf("\nList after removing the last node: \n");
				read_car_node(head);
				wait_for_enter();
				break;
			}

			case 5:{

				char *carName = (char *)malloc(100*sizeof(char));

				printf("Enter car name:");
				scanf("%99s",carName);
				printf("\nList after removing the node with name %s: \n", carName);
				head = delete_car_node_by_name(head, carName);
				read_car_node(head);
				wait_for_enter();
				break;
			}

			case 6:{
				if (head == NULL) { // Checks if list is empty
                    printf("List is empty\nPlease create a list first\n");
					getchar();
                    wait_for_enter();
                    break;
                }
				read_csv_file("mycarlist.csv",head);
				printf("\nCars have been added to the list");
				wait_for_enter();
				break;
			}

			case 7:{
				

				string_sorting(head);
				read_car_node(head);
				wait_for_enter();
				break;
			}

			default:{
				printf("Invalid input\n");
				wait_for_enter();
			}
		}
		
	}
	return 0;
}