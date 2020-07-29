#include <stdio.h>

void scan_arr(int *arr, int Size){
    int counter;
    for(counter=0;counter<Size;counter++){
        printf("Please Enter the array Element %i:",counter+1);
        scanf("%i",&arr[counter]);
    }
}

void selection_sort(int *arr, int Size){
    int counter1,temp,loction,counter2;
    for(counter1=0;counter1<Size-1;counter1++){
        loction=counter1;
        for(counter2=counter1+1;counter2<Size;counter2++){
            if(arr[counter2]<arr[loction]){
                loction=counter2;
            }
        }
        if(loction != counter1){
            temp=arr[counter1];
            arr[counter1]=arr[loction];
            arr[loction]=temp;
        }
    }
}

void print_arr(int *arr, int Size){
    printf("\n\n");
    int counter;
    for(counter=0;counter<Size;counter++){
        printf("The array element %i : %i",counter+1,arr[counter]);
    }
    printf("\n\n");
}
