#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"


class ObligatoryCourse : public Course
{
    public:
    	int getScore() const;//获得课程成绩
        bool setMark(int m);//设置课程成绩

        virtual double getWeight() const {return 0.6;}
        virtual int getElectiveNumber() const {return 0;}

        ObligatoryCourse(const string &n="", int ch=0, int m=0):Course(n, ch), mark(m){}
        ObligatoryCourse(const ObligatoryCourse& oc):Course(oc), mark(oc.mark){}	//拷贝构造函数
        virtual ~ObligatoryCourse();
    protected:
    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
