/*
 * looks for the first occurrence of 'key' starting at 'from' up to 'size' 
 * in 'arr'.   
 * if found, returns the index of 'key' in 'arr' such that 
 *    from <= i < size and arr[i] == key and 
 *      there is no j such that arr[j] == key for from <= j < i.
 *  
 * returns -1 otherwise
 */

int arr_search(int arr[], unsigned int size, unsigned int from, int key)
{
    int i;
    
    for (i = from; i < size; ++i) {
        if (arr[i] == key) return i;
    }

    return -1;
}
