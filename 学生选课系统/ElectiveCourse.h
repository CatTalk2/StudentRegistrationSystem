#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"


class ElectiveCourse : public Course
{
    public:
    	virtual int getScore() const;   //��ÿγ̳ɼ�
        bool setGrade(char g);  //���ÿγ̳ɼ�

        virtual double getWeight() const {return 0.4;}
        virtual int getObligatoryCredit() const { return 0;}

        ElectiveCourse(const string &n="", int ch=0, char g='\0');
        ElectiveCourse(const ElectiveCourse &ec):Course(ec),grade(ec.grade){}	//�������캯��
        virtual ~ElectiveCourse();
    protected:
    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
