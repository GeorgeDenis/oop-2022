#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h"
#include "global.h"
int main() {
    Student denis;
    denis.set_name("Denis");
    printf("Nume: %s \n", denis.get_name());
    denis.set_gradeEnglish(9.5);
    denis.set_gradeMathematics(10);
    denis.set_gradeHistory(8.2);
    printf("Nota Engleza: %.2f \n", denis.get_gradeEnglish());
    printf("Nota Matematica: %.2f \n", denis.get_gradeMathematics());
    printf("Nota Istorie: %.2f \n", denis.get_gradeHistory());
    printf("Media: %.3f  \n", denis.average_grade());
    Student marcel;
    marcel.set_name("Marcel");
    printf("Nume: %s \n", marcel.get_name());
    marcel.set_gradeEnglish(9.4);
    marcel.set_gradeMathematics(9);
    marcel.set_gradeHistory(8.3);
    printf("Nota Engleza: %.2f \n", marcel.get_gradeEnglish());
    printf("Nota Matematica: %.2f \n", marcel.get_gradeMathematics());
    printf("Nota Istorie: %.2f \n", marcel.get_gradeHistory());
    printf("Media: %.3f  \n", marcel.average_grade());
    printf("Comparare nume: %d\n", comparatie_Name(denis, marcel));
    printf("Comparare nota Engleza: %d\n", comparatie_gradeEnglish(denis, marcel));
    printf("Comparare nota Matematica: %d\n", comparatie_gradeMathematics(denis, marcel));
    printf("Comparare nota Istorie: %d\n", comparatie_gradeHistory(denis, marcel));
    printf("Comparare medie: %d \n", comparatie_average(denis, marcel));
}