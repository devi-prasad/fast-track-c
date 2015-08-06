/*
 * these constants come from the domain.
 */

#define STUDENT_NAME_LEN    64    /* including the terminating null char */
#define REG_NUM_LEN         10
#define EMAIL_ADDR_LEN      32
#define PROGRAM_NAME_LEN    32
#define COURSE_NAME_LEN     20

#define COURSES_MAX         5
#define ELECTIVES_MAX       1

typedef enum { REGULAR = 1, Elective = 2, AUDIT = 4 } CourseType;

typedef enum { INVALID = 0, REGISTERED, UNREGISTERED, PENDING } 
                                                          RegistrationStatus;
