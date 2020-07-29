#include <stdio.h>

void scan_arr(int *arr, int Size){
    int i;
    for(i=0;i<Size;i++){
        printf("Enter array element %i :",i+1);
        scanf("%i",&arr[i]);
    }
}

void print_arr(int *arr, int Size){
    printf("\n\n");
    int i;
    for(i=0;i<Size;i++){
        printf("The array element %i :%i \n",i+1,arr[i]);
    }
    printf("\n\n");
}

void insertion_sort(int *arr, int Size){
    int i,value,hole;
    for(i=1;i<=Size-1;i++){
        hole=i;
        value=arr[hole];
        while(hole>0 && arr[hole-1]>value){
            arr[hole]=arr[hole-1];
            hole--;
        }
        arr[hole]=value;
    }
}
