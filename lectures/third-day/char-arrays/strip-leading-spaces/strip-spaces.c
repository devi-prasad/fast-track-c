
/*
 * 'len' is the string length of 'src'.
 * Assumes 'dest' is at least 'len' chars in length.
 * skips over the initial segment of spaces in 'src' string. 
 * Copies to 'dest' the rest of the 'src' string.
 *
 * returns the number of leading spaces stripped from 'src'.
 */

int strip_leading_spaces(char dest[], const char src[], unsigned int len)
{
    unsigned int i, j, r;

    for (i = 0; i < len; ++i) {
        if (src[i] != ' ') break;
    }

    r = i;
    for (j = 0; i < len; ++j, ++i) {
        dest[j] = src[i];
    }

    dest[j] = '\0';

    return r;
}

