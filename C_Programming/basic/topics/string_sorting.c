#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// Defining node struct
typedef struct string_node{
    char *node_data;
    struct string_node *next_node;
}string_node;

string_node* create_new_node(){
    string_node *new_node=(string_node *)mallac(sizeof(string_node));

    new_node->node_data=NULL;
    new_node->next_node=NULL;

    return new_node;
}

int main(){
    string_node *head = NULL;
    return 0;
}