#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <cstring>
void Student::set_name(const char* name) {
    strcpy(this->name, name);
}

void Student::set_gradeMathematics(float gradeMathematics) {
    this->gradeMathematics = gradeMathematics;
}

void Student::set_gradeEnglish(float gradeEnglish) {
    this->gradeEnglish = gradeEnglish;
}

void Student::set_gradeHistory(float gradeHistory) {
    this->gradeHistory = gradeHistory;
}

const char* Student::get_name() const {
    return name;
}

float Student::get_gradeMathematics() const {
    return gradeMathematics;
}

float Student::get_gradeEnglish() const {
    return gradeEnglish;
}

float Student::get_gradeHistory() const {
    return gradeHistory;
}

float Student::average_grade() const {
    return (gradeEnglish + gradeHistory + gradeMathematics) / 3;
}
