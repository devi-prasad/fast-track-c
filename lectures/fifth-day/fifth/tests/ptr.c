#include <stddef.h>
#include <assert.h>
#include <string.h>

// NEVER DO THIS!!!!!
int *gp = NULL;

int int_inc(int x)
{
   x += 1;
   return x;
}

int f()
{
    *gp = 0;
}

int int_inc_with_a_ptr(int *p)
{
    gp = p;
    *p += 1;
    return *p;
}

int int_inc_wrapper()
{
    int a;

    a = 100;
    int_inc_with_a_ptr(&a);
}

void some_random_function()
{
    char buf[16 * 1024];
    memset(buf, 0, 16 * 1024 * sizeof(char));
   
    // some computation
}

int main()
{
	int i;

    int_inc_wrapper();

    // DONT DO THIS!!! EVER!!!
    assert(*gp == 101);

    some_random_function();
	
	assert(*gp == 101);

	return 0;
}




