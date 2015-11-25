#ifndef CONSOLE_H
#define CONSOLE_H

#include "Student.h"
#include "Course.h"

//控制台类，实现用户界面
class Console
{
    public:
        int run();    //运行控制台

        Console();
        virtual ~Console();
    protected:
    private:
        int displayMenu() const;    //显示系统主菜单
        Course* selectCourse(int op);     //选课，返回课程地址；参数：op=1选择必修课，op=2选择选修课
        bool setCourseScore();       //设置所有的课程成绩

        Console& buildStudent();//构造学生对象
        Console& buildCourse();//构造所有的可选课程（包括必修和选修课）
        
        Student *student;           //当前学生对象
        Course *oc[MAX_SIZE];		//全部可选的必修课程清单
        Course *ec[MAX_SIZE];		//全部可选的选修课程清单
        int ocNum;      //可选的必修课程实际数量
        int ecNum;	//可选的选修课程实际数量
};

#endif // CONSOLE_H
