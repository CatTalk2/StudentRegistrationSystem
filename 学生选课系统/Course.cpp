#include "Course.h"

Course::Course(const string &n, int ch)
{
    name=n;
    creditHour=ch;
}

Course::~Course()
{
    //dtor
}
ostream& operator<<(ostream &output, const Course&c)
{
	output<<"课程名："<<c.name
		<<"\t学分："<<c.creditHour
		<<"\t成绩："<<c.getScore()
		<<"\n";
	return output;
}

