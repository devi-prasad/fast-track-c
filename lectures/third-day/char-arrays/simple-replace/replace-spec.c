#include <assert.h>
#include <string.h>

/*
 * In C, there is no built-in, native string data type.
 * An array of characters is used to represent strings.
 * The end of a string is marked by the special (ASCII zero) '\0' character.   
 */


/*
 * replace space by '$'
 */
 int replace_space_by_dollar(char str[], unsigned int len);

int main()
{
    char empty_str[] = "";
    char one_space_str[] = " ";
    char compact_str[] = "Hello,World!";
    char str[] = "  Hello, World!  ";
    

    replace_space_by_dollar(empty_str, strlen(empty_str));
    assert(strlen(empty_str) == 0);
    
    replace_space_by_dollar(one_space_str, strlen(one_space_str));
    assert(strcmp(one_space_str, "$") == 0);

    replace_space_by_dollar(compact_str, strlen(compact_str));
    assert(strcmp(compact_str, "Hello,World!") == 0);

    replace_space_by_dollar(str, strlen(str));
    assert(strcmp(str, "$$Hello,$World!$$") == 0);
    
    return 0; 
}
