
#include <assert.h>

/*
 * The C programming language does not guarantee that local variables
 * will be initialized (unlike Java and C#, for example.
 * 
 * This piece of code shows the care one needs to take.
 *
 */
void test_simple_array_init()
{
    int arr[5];
    int i;

    for (i = 0; i < 5; ++i) {
        arr[i] = 0;
    }

    assert(arr[0] == 0);
    assert(arr[4] == 0);
}

int main()
{
	test_simple_array_init();

	return 0;
}