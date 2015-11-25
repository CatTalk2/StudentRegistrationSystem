#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 10
#include "Date.h"
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;
class Student
{
    friend ostream& operator<<(ostream&, const Student &s);   //重载流运算符的友元声明，输出学生以及选课信息
    public:
        double calcAchievement() const;	//计算学生的积点成绩

        /*关于选课列表的一些相关操作*/
        bool existCourse(Course *course);//判断是否已经存在某门课程
        Student& addCourse(Course *course);             //通过课程指针添加课程，实现学生选课功能
        //Student& addCourse(const string &courseName, int creditHour);//通过课程名和学分信息添加课程，实现学生选课功能

        bool removeCourse(int i);                       //删除指定位置的课程
        bool removeCourse(const string& courseName);    //根据课程名称删除课程

        //重载下标运算符，获取该学生的某门课程信息
        const Course& operator[](int subscript) const;//常量成员函数，只允许作为右值
        Course& operator[](int subscript);	//普通成员，可作为左值；可以通过改成函数返回的课程信息设置课程成绩

        //void print() const;   //打印学生信息

        Student& setName(const char* const n);//set函数，设置姓名
        const char* getName() const {return name;}//get函数，获得姓名
        const Date& getBirthDate() const {return birthDate;}//get函数，获得生日
        static int getCount() {return count;}//静态get函数，获得对象数量
        int getCourseNumber()const {return courseNumber;}

        Student(const char* const n, int y, int m, int d);//构造函数
        Student(const char* const n, const Date &d);//构造函数
        Student(const Student &s);  //拷贝构造函数
        virtual ~Student(); //析构函数
    protected:
    private:
        char *name; //姓名
        const Date birthDate;   //生日
        static int count;   //静态成员，用于统计学生数目

        int courseNumber;   //当前实际课程数目
        Course *courseList[MAX_SIZE];   //存储当前学生所选的课程指针

        //工具函数
        int calcObligatoryCredit() const;//计算必修课总学分
        int calcElectiveNumber() const;//计算选修课总门数
};

#endif // STUDENT_H
