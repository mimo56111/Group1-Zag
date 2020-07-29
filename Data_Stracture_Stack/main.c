#include <stdio.h>
#include <stdlib.h>
#include "Stack_function.h"
int main()
{
    int choice, popped_val,pushed_val,h;
    while(1){
        printf("Is stack Full\n IS stack Empty \n Push \n Pop \n Display Stack Element \n Number of Stack element");
        printf("Please enter your choice:");
        scanf("%i",&choice);
        switch(choice){
            case 1:
                if(is_stack_Full()==1){
                    printf("Stack IS Full\n");
                }else{
                    printf("Stack IS Not Full\n");
                }
                break;
            case 2:
                if(is_stack_Empty()==1){
                     printf("Stack IS Empty\n");
                }else{
                    printf("Stack IS Not Empty\n");
                }
                break;
            case 3:
                printf("Enter Element:");
                scanf("%i",&pushed_val);
                Push(pushed_val);
                break;
            case 4:
                popped_val=Pop();
                printf("The value =%i",popped_val);
                break;
            case 5:
                dispaly_Stack_elements();
                break;
            case 6:
                h=number_of_stack_elements();
                printf("Number of elements stored =%i",h);
                break;
        }
    }
    return 0;
}
