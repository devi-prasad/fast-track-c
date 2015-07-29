
/*
 * adds 'n' numbers starting from 'm'. 
 * 'sum' may be called with a negative value for 'm'.
 *
 */
int sum(int m, unsigned int n)
{
	int sum = 0;

	while (n > 0) {
	    sum += m;
	    --n;
	    ++m;
	}

	return sum;
}
