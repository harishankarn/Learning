#ifdef STRING_SORT_H
#define STRING_SORT_H

// Defining node struct
typedef struct string_node{
    char *node_data;
    struct string_node *next_node;
}string_node;

void string_sorting(string_node *head);

#endif //STRING_SORT_H
