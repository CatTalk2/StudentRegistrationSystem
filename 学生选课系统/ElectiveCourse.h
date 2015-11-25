#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"


class ElectiveCourse : public Course
{
    public:
    	virtual int getScore() const;   //获得课程成绩
        bool setGrade(char g);  //设置课程成绩

        virtual double getWeight() const {return 0.4;}
        virtual int getObligatoryCredit() const { return 0;}

        ElectiveCourse(const string &n="", int ch=0, char g='\0');
        ElectiveCourse(const ElectiveCourse &ec):Course(ec),grade(ec.grade){}	//拷贝构造函数
        virtual ~ElectiveCourse();
    protected:
    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
