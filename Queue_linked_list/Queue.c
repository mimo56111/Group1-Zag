#include "linked_list.h"
node *head='\0';
int count=0;
int is_queue_empty(void){
    int x;
    if(head=='\0'){
        x=1;
    }else{
        x=0;
    }
    return x;
}

void enqueue(int val){
    push_end(head,&head,val);
    count++;
}

int dequeue(void){
    count--;
    return pop_head(&head);
}

void display_Queue_elements(void){
    print_list(head);
}

int number_of_Queue_elements(void){
    return count;
}
