#include <assert.h>
#include "student.h"

void test_student_new_attacks()
{
    {
    	Student st = student_new("", "", "", "");
    	assert(st.status == INVALID);
    }
}

int main()
{
	test_student_new_attacks();

    return 0;
}