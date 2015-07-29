
#include <assert.h>

/*
 * The C programming language does not guarantee that local variables
 * will be initialized (unlike Java and C#, for example.
 * 
 * There are various worries with C arrays. Buffer overflow being one
 * of the notorious unsafe operations.
 *
 */
void test_simple_array_init()
{
    int arr[5];

    assert(arr[0] == 0);
    assert(arr[4] == 0);
}

int main()
{
	test_simple_array_init();

	return 0;
}