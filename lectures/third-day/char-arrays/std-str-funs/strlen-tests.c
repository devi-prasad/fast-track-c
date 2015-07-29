#include <string.h>
#include <assert.h>

/*
 * In C, strings are represented as a sequence of characters terminated
 * by ASCII zero. Recall that we write ASCII zero as '\0'. 
 *
 */

 /*
  * Test the behavior of strlen standard C function that determines the length 
  * of its string argument.
  */

void test_string_length()
{
    assert(strlen("")   == 0);
    assert(strlen("\0") == 0);
    assert(strlen("0")  == 1);
    assert(strlen(" ")  == 1);       /* one blank char */

    /* leading blank, tab, newline, backspace and a trailing blank character */
    assert(strlen(" \t\n\b ")  == 5); 

    assert(strlen("abcd1234") == 8);
    assert(strlen("abcd1234\0") == 8);
    assert(strlen("abc\0d1234") == 3);
    assert(strlen("\0abcd1234") == 0);
}

/*
 * strcmp and strncmp - lexical comparison of two strings
 * 
 * return zero when strings match (up to the length specified)
 *        < 0  when the first string is "less than" the second, and
 *        > 0  when the first string is "greater than" the second.
 * 
 */
void test_string_comparison()
{
    assert(strcmp("", "") == 0);
    assert(strcmp("", "\0\0\0") == 0);
    assert(strcmp("A", "a") < 0);
    assert('A' < 'a');

    assert(strcmp("a", "b") < 0);
    assert('a' < 'b');
    assert(strcmp("z", "y") > 0);
    assert(strcmp("0", "1") < 0);
    assert(strcmp("1", "0") > 0);
    
    assert(strcmp("1024", "a") < 0);
    assert('1' < 'a');
    
    assert(strcmp("1024", "2") < 0);
    assert(strcmp("1024", "1023") > 0);
    assert(strcmp("1024", "099999") > 0);

    assert(strcmp("abcd", "abc") > 0);

    assert(strncmp("abcd", "abc", 3) == 0);
    assert(strncmp("abcd", "ABC", 3) > 0);
    assert(strncmp("1024", "1023", 3) == 0);
}

/*
 * strcpy and strncpy - copy the second string to the first.
 *  
 * care must be taken while using strncpy when the source string's length is
 * greater than the number of chars requested in the operation. We MUST
 * insert the '\0' character where required.
 *
 */
void test_string_copy()
{
    char str[16];

    strcpy(str, "Hello, Text");
    assert(strlen(str) == strlen("Hello, Text"));
    
    assert(strcmp(str, "Hello, Text") == 0);
    assert(strncmp(str, "Hello", 5)  == 0);
    assert(strncmp(str, "Hello, ", 7) == 0);

    /* watch the following three lines */
    strncpy(str, "Hello, Text", 6);
    str[6] = '\0';
    assert(strcmp(str, "Hello,")  == 0);

    /* notice carefully how we change string in-place */
    str[5] = '\0';
    assert(strcmp(str, "Hello")  == 0);

    /* watch how we are copying more chars than are available in the input */
    strncpy(str, "Hello, World!", 15);
    str[15] = '\0';
    assert(strcmp(str, "Hello, World!")  == 0);
}


int main()
{
    test_string_length();
    
    test_string_comparison();
    
    test_string_copy();
    
    return 0;
}
