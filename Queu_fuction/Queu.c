#include <stdio.h>

#include "Queu.h"
#define SIZE  4
int queue[SIZE];

int counter=0,rear=0,front=0;

int is_queue_empty(){
    int x;
    if(counter==0){
        x=1;
    }else{
        x=0;
    }
    return x;
}

int is_queue_full(){
    int x;
    if(counter==SIZE){
        x=1;
    }else{
        x=0;
    }
    return x;
}

void enqueue(int val){
    queue[rear]=val;
    if(rear<SIZE){
        rear++;
    }
    counter++;
}

int dequeue(void){
    int x;
    x=queue[front];
    if(front<SIZE){
        front++;
    }
    counter--;
    return x;
}

int number_of_queue_elements(void){
    return counter;
}

void display_queue_elements(void){
    int i,f=front;
    for(i=0;i<counter;i++){
        printf("%i\n",queue[f]);
        if(f<SIZE){
          f++;
        }
    }
}
