#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int val;
    struct point *next;
}node;

void print_list(node *head);
void push_head(node ** head_ptr, int val);
void push_end(node * head,node **head_adr, int data);
int pop_head(node ** head_ptr);
int remove_last(node * head,node **head_ptr);
void insert_by_index(node* head,node **head_ptr,int data ,int n);
int remove_by_index(node ** head_ptr, int n);

