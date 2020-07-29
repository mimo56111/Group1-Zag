#include <stdio.h>
#include <stdlib.h>
#include "Queu.h"
int main(){
    int choice,val;
    while(1){
         printf("1-is queue empty\n2-is queue full\n3-enqueue\n4-Dequeue\n5-Number of elements\n6-Display");
         printf("\nEnter Choice");
         scanf("%d",&choice);
         switch(choice){
            case 1:
                if(is_queue_empty()==1){
                    printf("\nQueue is Empty");
                }else{
                    printf("\nQueue is not Empty");
                }
                break;
            case 2:
                if(is_queue_full()==1){
                    printf("\nQueue is Full");
                }else{
                    printf("\nQueue is not Full");
                }
                break;
            case 3:
                printf("Enter Number:");
                scanf("%i",&val);
                enqueue(val);
                break;
            case 4:
                val=dequeue();
                printf("%i",val);
                break;
            case 5:
                printf("Number of element=%i",number_of_queue_elements());
                break;
            case 6:
                display_queue_elements();
                break;
         }
    }

    return 0;
}
