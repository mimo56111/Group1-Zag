#include "Stack_function.h"
#define SIZE 3
int top=-1;
int stack[SIZE];

int is_stack_Full(void){
    int x;
    if(top>=SIZE-1){
        x=1;
    }else{
        x=0;
    }
    return x;
}

void Push(int x){
    top++;
    stack[top]=x;
}

int is_stack_Empty(void){
    int x;
    if(top<=-1){
       x=1;
    }else{
        x=0;
    }
    return x;
}

int Pop(void){
    int x;
    x = stack[top];
    top--;
    return x;
}

void dispaly_Stack_elements(void){
    int i;
    for(i=0;i<=top;i++){
        printf("%i\n",stack[i]);
    }
}

int return_top_value(void){
    return stack[top];
}

int number_of_stack_elements(void){
    return top+1;
}
