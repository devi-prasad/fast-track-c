#include <stddef.h>
#include <string.h>
#include <assert.h>

#define MAX_ALLOWED_SWAP_LEN (4 * 1024)
static char __str_swap_buffer__[MAX_ALLOWED_SWAP_LEN];

void str_swap(char *s, char *t)
{
    assert(s != NULL && t != NULL);
    assert(strlen(s) == strlen(t));
    assert(MAX_ALLOWED_SWAP_LEN > strlen(s));

    if (s && t && strlen(s) == strlen(t) && MAX_ALLOWED_SWAP_LEN > strlen(s)) {
        strcpy(__str_swap_buffer__, s);
        strcpy(s, t);
        strcpy(t, __str_swap_buffer__);
    }
}

void int_swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int main()
{
    {
      int a, b;

      a = 100;
      b = -200;

      int_swap(&a, &b);
      assert(a == -200 && b == 100);
    }

    {
      char f[] = "VLSI CAD        ";
      char s[] = "Embedded Systems";
      str_swap(f, s);
      assert(strcmp(f, "Embedded Systems") == 0);
      assert(strcmp(s, "VLSI CAD        ") == 0);
    }

    return 0;
}
