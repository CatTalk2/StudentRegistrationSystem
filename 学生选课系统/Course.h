#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
using namespace std;

class Course
{
    friend ostream& operator<<(ostream &, const Course&);
    public:

        virtual int getScore() const=0;         //获得课程成绩
        virtual double getWeight() const=0;		//获得课程权重

        virtual int getObligatoryCredit() const { return creditHour;}//计算课程学分（用于必修课）
        virtual int getElectiveNumber() const {return 1;}           //计算课程门数（用于选修课）

        const string& getName()	const	{return name;}  //get函数，获得课程名称
        void setName(const string &n)	{name=n;}       //set函数，修改课程名称
        int getCreditHour()	const	{return creditHour;}//get函数，获得课程学分
        void setCreditHour(int ch){creditHour=ch;}      //set函数，修改课程学分

        Course(const string &n="", int ch=0);   //构造函数
        virtual ~Course();                      //析构函数
    protected:
    private:
        string name;
        int creditHour;
};

#endif // COURSE_H
