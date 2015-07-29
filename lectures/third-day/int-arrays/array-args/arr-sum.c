
/*
 * This is a simple function that takes an array 'arr' and finds the sum of
 * first 'n' elements of 'arr'.
 * 'n' may be less than the actual size of 'arr'.
 *
 * On the other hand, there's really no way to know if the passed
 * value of 'n' is actually safe! 
 *
 */

int array_sum(int arr[], unsigned int n)
{
    int sum = 0;
    int i;

    for (i = 0; i < n; ++i) {
    	sum += arr[i];
    }

    return sum;
}
