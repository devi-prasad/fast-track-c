#include <assert.h>


int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}


int main()
{
    assert(is_digit('0'));
    assert(is_digit('1'));
    assert(is_digit('9'));
    assert(is_digit('5'));

    assert(!is_digit('\0'));
    assert(!is_digit(0));
    assert(!is_digit(9));

    assert(!is_digit('a'));
    assert(!is_digit('A'));
    assert(!is_digit('-'));
    assert(!is_digit('$'));
    assert(!is_digit('#'));

    return 0;
}

