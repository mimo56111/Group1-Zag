#include <stdio.h>
void scan_arr(int *arr, int Size){
    int counter;
    for(counter=0;counter<Size;counter++){
        printf("Enter array element %i :",counter+1);
        scanf("%i",&arr[counter]);
    }
}
void print_arr(int *arr, int Size){
    int counter;
    printf("\n\n");
    for(counter=0;counter<Size;counter++){
        printf("The array element %i : %i",counter+1,arr[counter]);
    }
    printf("\n\n");
}

void bubble_sort(int *arr, int Size){
    int i,j,temp,flag;
    for(i=Size-1;i>0;i--){
        flag=0;
        for(j=0;j<i;j++){
            if(arr[j+1]<arr[j]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}
