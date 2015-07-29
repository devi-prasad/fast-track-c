#include <assert.h>

#define ARRAY_SIZE 6

int array_sum(int arr[], unsigned int n);

int main()
{
    int zero_arr[ARRAY_SIZE] = {0, 0, 0, 0, 0, 0};
    int arr[ARRAY_SIZE] = { 1, 2, 3, 4, 5, 6};
    int sum;
    
    sum = array_sum(zero_arr, ARRAY_SIZE);
    assert(sum == 0);

    sum = array_sum(arr, 0);
    assert(sum == 0);

    sum = array_sum(arr, 1);
    assert(sum == 1);

    sum = array_sum(arr, 4);
    assert(sum == 10);

    sum = array_sum(arr, 6);
    assert(sum == 21);

    return 0;
}
