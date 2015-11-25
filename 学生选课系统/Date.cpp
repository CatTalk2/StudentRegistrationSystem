#include "Date.h"
#include <iostream>
using namespace std;

Date::Date()
{
    year=1900;
    month=1;
    day=1;
}

Date::Date(int y, int m, int d)
{
    setDate(y, m, d);//调用set函数设置日期值
}

Date::Date(const Date &d)
{
    setDate(d.year, d.month, d.day);//调用set函数设置日期值，注意参数
}

Date::~Date()
{
    //dtor
}

void Date::setDate(int y, int m, int d)
{
    year=y; //初始化数据成员
    month=m;
    day=d;
    checkDate();//检查日期是否合法，如果不合法则调整。保证设置的日期值合法
}

bool Date::checkDate()
{
    bool flag=true; //日期是否合法，缺省合法
    //年不做任何限制

    //月应该在1~12之间
    if ((month<1)||(month>12))
    {
        month=1;    //将月改为合法日期
        flag=false;
    }
    //日应该在特定月的日期范围之内，即在1和本月最大天数之间
    if ((day<1)||(day>maxDay()))
    {
        day=1;
        flag=false;
    }
    return flag;
}

int Date::maxDay() const
{
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if(isLeapYear()) return 29;
            else return 28;
        default: //月错误，则返回0
            return 0;
    }
}

bool Date::isLeapYear() const
{
    return ( ((year%4==0)&&(year%100)) || (year%400==0) );
}

void Date::nextDay()
{
    day++;
    if(!checkDate()) month++;
    if(!checkDate()) year++;
}

/*void Date::print() const
{
    cout<<year<<"-"<<month<<"-"<<day;
}*/

Date& Date::operator++()
{
    nextDay();
    return *this;
}

Date Date::operator++(int)
{
    Date d=*this;
    nextDay();
    return d;
}

ostream& operator<<(ostream &output, const Date &d)
{
    output<<d.year<<"-"<<d.month<<"-"<<d.day;
    return output;
}

istream& operator>>(istream& input, Date &d)
{
	int year, month, day;
	cout<<", (格式: 年 月 日): ";
	input>>year>>month>>day;
	d.setDate(year,month,day);
	return input;
}
