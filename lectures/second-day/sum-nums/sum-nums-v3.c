
/*
 * adds 'n' numbers starting from 'm'. 
 * 'sum' may be called with a negative value for 'm'.
 *
 */
int sum(int m, unsigned int n)
{
	if (n == 0) return 0;
	
	return m + sum(m+1, n-1);
}
