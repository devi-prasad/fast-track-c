/*
 * replaces each space character in 'str' by a '$' across first 'len' chars.
 * returns the count of characters thus affected.
 * 
 * Note: this computes two results employing a side-effect.
 *
 */
int replace_space_by_dollar(char str[], unsigned int len)
{
    int i;
    int nc;

    for (i = 0, nc = 0; i < len; ++i) {
        if (str[i] == ' ') {
            str[i] = '$';
            ++nc;
        }
    }

    return nc;
}
