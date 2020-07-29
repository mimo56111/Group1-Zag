#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
int main()
{
    int choice,value;
    while(1)
    {
        printf("please enter your choice:\n");
        scanf("%i",&choice);
        printf("\n");
        switch(choice)
        {
            case 1:
            printf("please enter a value:\n");
            scanf("%i",&value);
            enqueue(value);
            break;
            case 2:
            if(is_queue_empty()==1)
            {
                printf("queue is empty\n");
            }
            else
            {
                value=dequeue();
                printf("the dequeue value= %i",value);
            }
            break ;
            case 3:
            if(is_queue_empty()==1)
            {
                printf("queue is empty\n");
            }
            else
            {
               display_Queue_elements();
            }
            break ;
            case 4:
            if(is_queue_empty()==1)
            {
                printf("queue is empty\n");
            }
            else
            {
              printf("the number of queue elements=%i",number_of_Queue_elements());
            }
            break ;
            case 5:
            exit(0);
            break;
            default:
            printf("wrong choice\n");
        }
        printf("\n");
    }
    return 0;
}
