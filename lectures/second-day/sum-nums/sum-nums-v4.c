
/*
 * adds 'n' numbers starting from 'm'. 
 * 'sum' may be called with a negative value for 'm'.
 *
 */
int sum(int m, unsigned int n)
{
	return (n == 0) ? 0 : m + sum(m+1, n-1);
}
