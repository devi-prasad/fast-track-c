
/*
 * adds 'n' numbers starting from 'm'. 
 * 'sum' may be called with a negative value for 'm'.
 *
 */
int sum(int m, unsigned int n)
{
	int sum;

	for (sum = 0; n > 0; --n, ++m) {
		sum += m;
	}

	return sum;
}
