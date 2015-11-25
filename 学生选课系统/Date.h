#ifndef DATE_H
#define DATE_H
#include <iostream>
using std::ostream;
using std::istream;

class Date
{
    friend ostream& operator<<(ostream &, const Date &);//友元声明，将流输出运算符的重载声明为日期类的友元，以便访问私有成员；实现代码放在cpp文件中
    friend istream& operator>>(istream& input, Date &d);	//重载流输入运算符
    public:
        Date& operator++();     //重载前置自增运算符，实现日期日期递增1
        Date operator++(int);   //重载后置自增运算符，实现日期日期递增1

        //void print() const;   //打印函数，将当前日期打印到控制台

        void nextDay();     //将当前日期加1，即下一日期
        bool isLeapYear() const;  //判断当前年份是否为闰年

        void setDate(int y, int m, int d);//set函数，设置日期
        int getYear()const {return year;}     //get函数，返回年
        int getMonth()const {return month;}   //get函数，返回月
        int getDay()const {return day;}       //get函数，返回日

        Date(int y, int m, int d);//构造函数
        Date();//缺省构造函数
        Date(const Date &d);  //拷贝构造函数
        virtual ~Date();//虚析构函数
    protected:
    private:
        bool checkDate();//工具函数，检查当前日期数据是否合法；如果不合法，则修改为默认的合法值，并返回false;否则返回true
        int maxDay() const;//工具函数，返回当前年和月背景下的最大日数

        int year;   //年
        int month;  //月
        int day;    //日
};

#endif // DATE_H
