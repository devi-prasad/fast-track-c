
unsigned int fib(unsigned int n)
{
	unsigned int n_1, n_2, num;

    if (n < 0) return 0;
	
    if (n == 0 || n == 1) return 1;

    n_1 = n_2 = 1;
    while (n > 1) {
    	num = n_1 + n_2;
    	n_2 = n_1;
    	n_1 = num;
    	--n;
    }

    return num;
}