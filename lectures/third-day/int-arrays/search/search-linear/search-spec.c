#include <assert.h>

#define ARRAY_SIZE 21

int arr_search(int arr[], unsigned int size, int key);

int main()
{
    int nums[] = {100, -35, 0, -2, 14, 73, 88, 
                  -25,  0,  0, 15, 3,  10, -25, 
                  73, 100, 29, 66, 39, 243, 42};
    
    assert(arr_search(nums, ARRAY_SIZE, 1024) == -1);

    assert(arr_search(nums, ARRAY_SIZE, 100) == 0);

    assert(arr_search(nums, ARRAY_SIZE, 42) == ARRAY_SIZE-1);

    assert(arr_search(nums, ARRAY_SIZE, -25) == 7);
    assert(arr_search(nums, 0, -25) == -1);
    assert(arr_search(nums, 7, 42) == -1);

    return 0;
}