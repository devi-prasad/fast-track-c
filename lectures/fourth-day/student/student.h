#include "appconsts.h"

typedef char Course[COURSE_NAME_LEN + 1];

struct _student_ {
    char name[STUDENT_NAME_LEN];
    char regnum[REG_NUM_LEN];
    char program[PROGRAM_NAME_LEN];
    Course elective;
    char email_addr[EMAIL_ADDR_LEN];
    RegistrationStatus status; 
};

typedef struct _student_ Student;

Student student_new(const char name[], const char regnum[],
                    const char program[], const char email_addr[]);

int student_set_elective(Student st, Course elective);
int student_get_elective(Student st, Course elective);
