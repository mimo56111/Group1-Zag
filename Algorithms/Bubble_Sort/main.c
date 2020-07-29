#include <stdio.h>
#include <stdlib.h>
#include "Bubble_Sort.h"
int main()
{
    int arr[7];
    scan_arr(arr,7);
    bubble_sort(arr,7);
    print_arr(arr,7);
    return 0;
}
