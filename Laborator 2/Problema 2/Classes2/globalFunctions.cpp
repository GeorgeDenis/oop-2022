#include "globalFunctions.h"

int compare(std::string x, std::string y)
{
	if (x == y)
		return 0;
	else if (x > y)
		return 1;
	else
		return -1;
}

int compareM(float x, float y)
{
	if (x == y)
		return 0;
	else if (x > y)
		return 1;
	else
		return -1;
}

int compareE(float x, float y)
{
	if (x == y)
		return 0;
	else if (x > y)
		return 1;
	else
		return -1;
}

int compareH(float x, float y)
{
	if (x == y)
		return 0;
	else if (x > y)
		return 1;
	else
		return -1;
}

int compareA(float x, float y)
{
	if (x == y)
		return 0;
	else if (x > y)
		return 1;
	else
		return -1;
}

int compare2(student x, student y)
{
	if (x.getName() == y.getName())
		return 0;
	else if (x.getName() > y.getName())
		return 1;
	else
		return -1;
}

int compareM2(student x, student y)
{
	if (x.getGradeM() == y.getGradeM())
		return 0;
	else if (x.getGradeM() > y.getGradeM())
		return 1;
	else
		return -1;
}

int compareE2(student x, student y)
{
	if (x.getGradeE() == y.getGradeE())
		return 0;
	else if (x.getGradeE() > y.getGradeE())
		return 1;
	else
		return -1;
}

int compareH2(student x, student y)
{
	if (x.getGradeH() == y.getGradeH())
		return 0;
	else if (x.getGradeH() > y.getGradeH())
		return 1;
	else
		return -1;
}

int compareA2(student x, student y)
{
	if (x.average() == y.average())
		return 0;
	else if (x.average() > y.average())
		return 1;
	else
		return -1;
}
