/*
 * looks for the first occurrence of 'key' starting at 'from' up to 'to'
 * in 'arr'.
 * if found, returns the index of 'key' in 'arr' such that
 *    some i such that from <= i < to and arr[i] == key and
 *      there is no j such that arr[j] == key for from <= j < i.
 *
 * returns -1 otherwise
 */

int arr_search(int arr[], unsigned int from, unsigned int to, int key)
{
    int i;
    
    for (i = from; i < to; ++i) {
        if (arr[i] == key) return i;
    }

    return -1;
}
