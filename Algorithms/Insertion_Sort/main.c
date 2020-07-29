#include <stdio.h>
#include <stdlib.h>
#include "Insertion_Sort.h"
int main()
{
    int arr[5];
    scan_arr(arr,5);
    insertion_sort(arr,5);
    print_arr(arr,5);
    return 0;
}
