#pragma once
#include <string>
class student
{
	std::string name;
	float gradeM;
	float gradeE;
	float gradeH;
public:
	inline float average() { return(gradeE + gradeH + gradeM) / 3; };
	inline std::string getName() { return name; };
	inline void setName(std::string x) { name = x;};
	inline void setGradeM(float x) { gradeM = x; };
	inline void setGradeE(float x) { gradeE = x; };
	inline void setGradeH(float x) { gradeH = x; };
	inline float getGradeM() { return gradeM; };
	inline float getGradeE() { return gradeE; };
	inline float getGradeH() { return gradeH; };
	student(std::string name, float m, float e, float h);
};

