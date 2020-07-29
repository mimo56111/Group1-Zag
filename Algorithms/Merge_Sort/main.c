#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5];
    scan_arr(arr,5);
    merge_sort(arr,0,4);
    print_arr(arr,5);
    return 0;
}
