#include<stdio.h>
#include<stdlib.h>

// Defining node struct string_node
typedef struct string_node{
    char *car_data;
    struct string_node *next_node;
}string_node;

// Defining car_details struct
typedef struct car_details{
    char *car_name; // car name
	/*char *car_type; // car type
	char *car_manufacture; // car manufacture
	char *car_price; // car price
	char *car_range; // car range
    */
   
}car_details;

// Defining car_node struct
typedef struct car_node{
	car_details *car_data; 
	struct car_node *next_car;

}car_node;

void swap(car_details **a, car_details **b) {
    car_details *temp = *a;
    *a = *b;
    *b = temp;
}

car_node *get_tail(car_node *head){
    car_node *current = head;
    while(current->next_car != NULL){
        current = current->next_car;
    }
    return current;
}

void string_sorting(car_node *head){
    car_details *temp;
    car_node *current1,*current2;

    // Quick sort
}

/*car_node* partition(car_node* head,car_node* end, car_node** newHead, car_node** newEnd) {
    car_node* pivot = get_tail(head);
    printf("Pivot: %s\n", pivot->car_data->car_brand);
}*/

car_node *create_car_node(car_details *carDetails){
    car_node *newNode= (car_node *)malloc(sizeof(car_node)); 

    newNode->car_data = carDetails;
    newNode->next_car  = NULL;

    return newNode;
}

void print_list(car_node *head) {
    car_node *current = head;
    while (current != NULL) {
        printf("%s\n", current->car_data->car_name);
        current = current->next_car;
    }
}

int main(){
    car_details *carDetails = (car_details *)malloc(sizeof(car_details));

    car_node *head = create_car_node("Ford");
    head->next_car = create_car_node("Toyota");
    head->next_car->next_car = create_car_node("Honda");
    head->next_car->next_car->next_car = create_car_node("BMW");
    head->next_car->next_car->next_car->next_car = create_car_node("Audi");

    print_list(head);
    return 0;
 //   printf(partition());
}