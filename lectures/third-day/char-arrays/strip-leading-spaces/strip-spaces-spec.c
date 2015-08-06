#include <assert.h>
#include <string.h>

int strip_leading_spaces(char dest[], const char src[], unsigned int len);

int main()
{
    char str[16];

    strip_leading_spaces(str, "", 0); /* ten spaces in 'src' */
    assert(strlen(str) == 0);

    strip_leading_spaces(str, "     ", 5); /* ten spaces in 'src' */
    assert(strlen(str) == 0);

    strip_leading_spaces(str, " H", 2);
    assert(!strcmp(str, "H"));

    strip_leading_spaces(str, "    Hello, ", 11);
    assert(!strcmp(str, "Hello, "));

    strip_leading_spaces(str, "Hello,  ", 8);
    assert(!strcmp(str, "Hello,  "));

    strip_leading_spaces(str, "Hello, Text", 11);
    assert(!strcmp(str, "Hello, Text"));

    return 0;   
}
