#include <stdio.h>
#include <stdlib.h>
#include "slectionsort.h"
int main()
{
    int arr[7];
    scan_arr(arr,7);
    selection_sort(arr,7);
    print_arr(arr,7);
    return 0;
}
