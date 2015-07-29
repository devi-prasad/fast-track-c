
/*
 * looks for the first occurrence of 'key' in the beginning 'size' elements 
 * of 'arr'.   
 * if found, returns the index of 'key' in 'arr' such that 
 *    0 <= i < size and arr[i] == key and 
 *      there is no j such that arr[j] == key for 0 <= j < i.
 *  
 * returns -1 otherwise
 */

int arr_search(int arr[], unsigned int size, int key)
{
    int i;
    
    for (i = 0; i < size; ++i) {
        if (arr[i] == key) return i;
    }

    return -1;
}
