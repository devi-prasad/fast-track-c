
#include <assert.h>

#define ARRAY_SIZE 5

/*
 * The C programming language does not guarantee that local variables
 * will be initialized (unlike Java and C#, for example.
 * 
 * This piece of code shows the one of the good practices while working
 * with arrays.
 *
 */
void test_simple_array_init()
{
    int arr[ARRAY_SIZE];
    int i;

    for (i = 0; i < ARRAY_SIZE; ++i) {
        arr[i] = 0;
    }

    assert(arr[0] == 0);
    assert(arr[ARRAY_SIZE - 1] == 0);
}

int main()
{
	test_simple_array_init();

	return 0;
}