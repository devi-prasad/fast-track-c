#include <assert.h>

#define ARRAY_SIZE 20

void gen_fibs(unsigned int n1, unsigned int n2, unsigned int arr[], 
                                                            unsigned int size);
int main()
{
	unsigned int arr[ARRAY_SIZE];

    
    gen_fibs(1, 1, arr, 3);
    assert(arr[0] == 2 && arr[1] == 3);
    assert(arr[2] = arr[1] + arr[0]);

    {
        int i;

        gen_fibs(1, 1, arr, 10);
        for (i = 9; i > 1; --i) {
            assert(arr[i] = arr[i-1] + arr[i-2]);
        }
    }

    return 0;
}