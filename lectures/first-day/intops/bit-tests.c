#include <assert.h>
#include <stdint.h>

/*
 *
 * Computers represent numbers in binary. There's a special way of 
 * representing numbers called the two's complement system which the modern
 * computers employ. 
 * 
 * The following tests are intended to give us an idea of the intricacies
 * that C language programmers MUST confront and appreciate. A good grasp of
 * the first-principles is mandatory to be a good C programmer! 
 *
 * 
 */


void run_byte_tests()
{
    unsigned char x = 1;
    
    /* positive numbers */
	assert(x << 1 == 2);
	assert(x << 2 == 4);
	assert(x << 3 == 8);
	
	assert(x << 4 == 16);
	assert(x << 4 == 0x0F + 1);
	assert(x << 4 == 0x10);

	assert(x << 7 == 128);
    assert(x << 7 == 0x7F + 1);
    assert(x << 7 == 0x80);

    assert(x << 7 == x << 6 * x << 1);
    assert(x << 7 > 0);
    assert((x << 7) >> 7 == 1);

	assert(((x << 7) | 0x7F) == 0xFF);
	assert(((x << 7) | 0x7F) == UINT8_MAX);    
}


void run_signed_int_bit_tests()
{
	int x = 1;

    /* positive numbers */
	assert(x << 1 == 2);
	assert(x << 2 == 4);
	assert(x << 3 == 8);
	assert(x << 4 == 16);
	assert(x << 8 == 256);
	assert(x << 16 == 65536);
	assert(x << 16 == x << 8 * x << 8);
    assert(x << 30 > 0);

    assert((x << 1) >> 1 == 1);
    assert((x << 2) >> 2 == 1);
    assert((x << 8) >> 8 == 1);
    assert((x << 30) >> 30 == 1);

    /* this looks perfect */    
    assert(x << 31 == x << 16 * x << 15);

    /* 
     * But, this looks weird. What's happening here? 
     */
    assert(x << 31 < 0);
    assert((x << 31) >> 31 < 0);
	
    
    /* in order to understand why the following assertions hold, one needs
     * to know the two's complement binary number system.
     */
	assert(x << 31 == INT_LEAST32_MIN);
	assert(((x << 31) | 0x7FFFFFFF) == 0xFFFFFFFF);
	assert((x << 31) >> 31 == -1);
	assert((x << 31) >> 31 == 0xFFFFFFFF);
    assert((x << 31) >> 31 == ((x << 31) | 0x7FFFFFFF));
}

void run_unsigned_int_bit_tests()
{
	unsigned int x = 1;

    assert(sizeof(int) == 4); /* we assume ints to be 32-bit beasts! */
    /* positive numbers */
	assert(x << 1 == 2);
	assert(x << 2 == 4);
	assert(x << 3 == 8);
	assert(x << 4 == 16);
	assert(x << 8 == 256);
	assert(x << 16 == 65536);
	assert(x << 16 == x << 8 * x << 8);
    assert(x << 30 > 0);

    assert((x << 1) >> 1 == 1);
    assert((x << 2) >> 2 == 1);
    assert((x << 8) >> 8 == 1);
    assert((x << 30) >> 30 == 1);

    /* this looks perfect */    
    assert(x << 31 == x << 16 * x << 15);
    assert(x << 31 > 0);
	assert((x << 31) >> 31 == 1);

	assert(((x << 31) | 0x7FFFFFFF) == 0xFFFFFFFF);
	assert(((x << 31) | 0x7FFFFFFF) == UINT32_MAX);
}

void run_bit_tests()
{
	run_byte_tests();
    run_unsigned_int_bit_tests();
    run_signed_int_bit_tests();
}
