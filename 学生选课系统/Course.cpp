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
	output<<"�γ�����"<<c.name
		<<"\tѧ�֣�"<<c.creditHour
		<<"\t�ɼ���"<<c.getScore()
		<<"\n";
	return output;
}

