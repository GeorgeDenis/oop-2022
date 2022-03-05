#pragma once
class Student {
    char name[30];
    float gradeMathematics;
    float gradeEnglish;
    float gradeHistory;

  public:
    void set_name(const char* name);
    void set_gradeMathematics(float gradeMathematics);
    void set_gradeEnglish(float gradeEnglish);
    void set_gradeHistory(float gradeHistory);
    const char* get_name() const;
    float get_gradeMathematics() const;
    float get_gradeEnglish() const;
    float get_gradeHistory() const;
    float average_grade() const;
};