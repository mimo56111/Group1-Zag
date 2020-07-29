#include <stdio.h>
#define SIZE 5
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

void merge_sort(int *arr, int leftstart, int rightEnd){
    if(leftstart<rightEnd){
        int middle=(rightEnd+leftstart)/2;
        merge_sort(arr,leftstart,middle);
        merge_sort(arr,middle+1,rightEnd);
        merge_halves(arr,leftstart,rightEnd);
    }
}

void merge_halves(int *arr, int leftstart, int rightEnd){
    int temp_arr[SIZE];
    int left=leftstart;
    int left_end=(leftstart+rightEnd)/2;
    int rightstart = left_end+1;
    int right=rightstart;
    int temp_Index=leftstart;
    while(left<=left_end && right<=rightEnd){
        if(arr[left]<=arr[right]){
            temp_arr[temp_Index++]=arr[left++];
        }else{
            temp_arr[temp_Index++] = arr[right++];
        }
    }
    while(left <= left_end){
        temp_arr[temp_Index++]=arr[left++];
    }
    while(right <= rightEnd){
        temp_arr[temp_Index++]=arr[right++];
    }
    temp_Index=left=leftstart;
    while(left<=rightEnd){
        arr[left++]=temp_arr[temp_Index++];
    }
}
