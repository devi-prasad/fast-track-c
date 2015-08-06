#include <string.h>
#include "student.h"

/*
 * regnum is a 9 digit number with first two chars = "15"
 * returns 1 if 'regnum' passes validation.
 * returns 0 otherwise.
 *
 */
static int is_valid_reg_num(const char regnum[])
{
    if (regnum[9] != '\0') return 0;
    if (regnum[0] != '1' && regnum[1] != '5') return 0;
    if (strncmp(regnum + 5, "0000", 4) == 0) return 0;
    
    return 1;
}

Student student_new(const char name[], const char regnum[],
                    const char program[], const char email_addr[])
{
    Student st;

    memset(&st, 0, sizeof(st));

    if (!is_valid_reg_num(regnum)) return st;

    strncpy(st.name, name, STUDENT_NAME_LEN - 1);
    st.name[STUDENT_NAME_LEN - 1] = '\0';

    strncpy(st.regnum, regnum, REG_NUM_LEN - 1);
    st.regnum[REG_NUM_LEN - 1] = '\0';

    strncpy(st.program, program, PROGRAM_NAME_LEN - 1);
    st.program[PROGRAM_NAME_LEN - 1] = '\0';

    strncpy(st.email_addr, email_addr, EMAIL_ADDR_LEN - 1);
    st.program[EMAIL_ADDR_LEN - 1] = '\0';

    return st;
}

int student_set_elective(Student st, Course elective)
{
	assert(st.status == REGISTERED);
	
    return -1;
}

int student_get_elective(Student st, Course elective)
{
    return -1;
}