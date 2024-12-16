#include<stdio.h>

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

void swap(car_details **a, car_details **b) {
    car_details *temp = *a;
    *a = *b;
    *b = temp;
}

void string_sorting(car_node *head){
    car_details *temp;
    car_node *current1,*current2;

    // Quick sort
}
car_node* partition(car_node* head,car_node* end, car_node** newHead, car_node** newEnd) {
    car_node* pivot = end;
    car_node* prev = NULL;
    car_node* current = head;
    car_node* tail = NULL;


}

car_node *partition(car_node* head, ){

}