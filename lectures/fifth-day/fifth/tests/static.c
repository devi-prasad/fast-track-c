#include <assert.h>

void rename(char *p)
{
	while (*p != '\0') {
		*p = 'A';
		++p;
	}
}

int main()
{
    char str[] = "embedded systems";

    assert(str == &str[0]);
    rename(str+15);
    assert(strcmp(str, "embedded systemA") == 0);
	return 0;
}
