#include <assert.h>

#define ARRAY_SIZE 21

int arr_search(int arr[], unsigned int from, unsigned int to, int key);

int main()
{
    int nums[ARRAY_SIZE] = { 100, -35,  0, -2, 14, 73, 88, 
                             -25,   0,  0, 15,  3, 10, -25, 
                              73, 100, 29, 66, 39, 243, 42 };
    
    assert(arr_search(nums, 0, ARRAY_SIZE, 1024) == -1);

    assert(arr_search(nums, 0, ARRAY_SIZE, 100) == 0);

    assert(arr_search(nums, 0, ARRAY_SIZE,42) == ARRAY_SIZE-1);
    assert(arr_search(nums, 0, ARRAY_SIZE-1, 42) == -1);

    assert(arr_search(nums, 0, ARRAY_SIZE, -25) == 7);
    assert(arr_search(nums, 7, 11, -25) == 7);
    assert(arr_search(nums, 8, 12, -25) == -1);
    assert(arr_search(nums, 8, 14, -25) == 13);
    assert(arr_search(nums, 14, ARRAY_SIZE, -25) == -1);

    assert(arr_search(nums, 0, 0, -25) == -1);
    assert(arr_search(nums, 0, 1, 100) == 0);

    return 0;
}
