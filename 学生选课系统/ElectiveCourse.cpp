#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse(const string &n, int ch, char g)
	:Course(n, ch)
{
	setGrade(g);
}

ElectiveCourse::~ElectiveCourse()
{

}

int ElectiveCourse::getScore() const
{
	switch(grade){
	    case 'A': return 95;
	    case 'B': return 85;
	    case 'C': return 75;
	    case 'D': return 65;
	    case 'E': return 55;
	    default: return 0;
	}
}

bool ElectiveCourse::setGrade(char g)
{
	if((g>='A')&&(g<='E')){
		grade=g;
		return true;
	}else{
		grade='\0';	//设置出错，需要做出错处理（以后会用异常来解决）
		return false;
	}
}
