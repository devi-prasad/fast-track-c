

void gen_fibs(unsigned int n1, unsigned int n2, unsigned int arr[], 
                                                             unsigned int size)
{
    int i;

    for (i = 0; i < size; ++i) {
    	arr[i] = n1 + n2;
    	n1 = n2;
    	n2 = arr[i];
    }
}
