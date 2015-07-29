
/*
 * 'len' is the string length of 'src'.
 * Assumes 'dest' is at least 'len' chars in length.
 * skips over the final segment of spaces in 'src' string. 
 * Copies to 'dest' the rest of the 'src' string.
 *
 * returns the number of trailing spaces stripped from 'src'.
 */

int strip_trailing_spaces(char dest[], char src[], unsigned int len)
{
    unsigned int i, j, r;

    for (i = len; i > 0; --i) {
        if (src[i - 1] != ' ') break;
    }
    
    r = len - i;

    dest[i] = '\0';
    for (j = i; j > 0; --j, --i) {
        dest[j-1] = src[i-1];
    }

    return r;
}
