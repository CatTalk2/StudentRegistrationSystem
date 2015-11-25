#include "ObligatoryCourse.h"

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

int ObligatoryCourse::getScore() const
{
	return mark;
}

bool ObligatoryCourse::setMark(int m)
{
	if ((m<=100)&&(m>=0)) {
		mark=m;
		return true;
	}else{
		return false;
	}
}
