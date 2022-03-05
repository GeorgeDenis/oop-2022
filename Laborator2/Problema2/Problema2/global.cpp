#include "global.h"
#include "Student.h"
int comparatie_Name(Student student1, Student student2) {
    if (strcmp(student1.get_name(), student2.get_name()) > 0)
        return 1;
    else if (strcmp(student1.get_name(), student2.get_name()) < 0)
        return -1;
    else
        return 0;
}

int comparatie_gradeMathematics(Student student1, Student student2) {
    if (student1.get_gradeMathematics() > student2.get_gradeMathematics())
        return 1;
    else if (student1.get_gradeMathematics() < student2.get_gradeMathematics())
        return -1;
    else
        return 0;
}

int comparatie_gradeEnglish(Student student1, Student student2) {
    if (student1.get_gradeEnglish() > student2.get_gradeEnglish())
        return 1;
    else if (student1.get_gradeEnglish() < student2.get_gradeEnglish())
        return -1;
    else
        return 0;
}

int comparatie_gradeHistory(Student student1, Student student2) {
    if (student1.get_gradeHistory() > student2.get_gradeHistory())
        return 1;
    else if (student1.get_gradeHistory() < student2.get_gradeHistory())
        return -1;
    else
        return 0;
}

int comparatie_average(Student student1, Student student2) {
    float medieStudent1 = student1.average_grade();
    float medieStudent2 = student2.average_grade();
    if (medieStudent1 > medieStudent2)
        return 1;
    else if (medieStudent1 < medieStudent2)
        return -1;
    else
        return 0;
}
