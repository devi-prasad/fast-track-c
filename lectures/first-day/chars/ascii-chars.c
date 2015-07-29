#include <assert.h>

int main()
{
    assert('\0' == 0);
    assert('0' != 0);

    assert('0' < '1');
    assert('1' < '2');
    assert('8' < '9');

    assert('a' < 'b');
    assert('y' < 'z');

    assert('a' + 1 == 'b');
    assert('y' + 1 == 'a' + 25);

    assert('A' < 'a');
    assert('Z' < 'z');
    
    assert('Z' < 'a');
    assert('a' - 'A' == 'z' - 'Z');

    return 0;
}
