#include "Student.h"
#include <cstring>
#include <iostream>
#include <cstdlib>
/*如果使用RTTI则需要包含派生类的头文件
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
*/
using namespace std;

int Student::count=0;

Student::Student(const char* const n, const Date &d)
    :birthDate(d)
{
    name=NULL;
    setName(n);
    count++;
    courseNumber=0;
}

Student::Student(const char* const n, int y, int m, int d)//构造函数
    :birthDate(y, m, d)
{
    name=NULL;
    setName(n);
    count++;
    courseNumber=0;
}

Student::Student(const Student &s)  //拷贝构造函数
    :birthDate(s.birthDate)
{
    name=NULL;
    setName(s.name);
    count++;
    courseNumber=0;
}

Student::~Student()
{
  /*  int i=courseNumber-1;	//释放课程信息
	while(i>0){
		if (removeCourse(i)) i--;
	}*///不再释放课程，由外面负责释放

    delete[] name;
    count--;
}

Student& Student::setName(const char * const n)
{
    if(name) delete[] name;
    name = new char[strlen(n)+1];
    strcpy(name, n);
    return *this;
}

/*void Student::print() const
{
	cout<<"姓名："<<name
		<<"\t生日：";
	birthDate.print();
	cout<<"\n";
}*/

Student& Student::addCourse(Course *course)
{
    //已经选择的课程不能在选择，保证课程只能选择一遍
	if ((course!=NULL)&&!existCourse(course)){
		if(courseNumber<MAX_SIZE){
			courseList[courseNumber++]=course;	//直接指针赋值
		}
	}
	return (*this);
}

/*Student& Student::addCourse(const string &courseName, int creditHour)
{
    if(courseNumber<MAX_SIZE){
		courseList[courseNumber++]=new Course(courseName, creditHour);	//新建一个课程对象，并保存其地址
	}
	return (*this);
}*/

bool Student::removeCourse(int i)
{
	if(i<courseNumber){
		//delete courseList[i];	//此处不再释放课程对象的内存空间，由外面的用户负责释放
		for(int j=i;j<courseNumber-1;j++){
			courseList[j]=courseList[j+1];	//将数组后面的课程前移，覆盖被删除的课程信息
		}
		courseNumber--;
		return true;
	}else{
		return false;
	}
}

bool Student::removeCourse(const string& courseName)
{
    int i;
	for(i=0;i<courseNumber;i++){	//找到所要取消的课程位置
		if (courseName==courseList[i]->getName()) break;
	}
	if (i<courseNumber){
		return removeCourse(i);	//如果找到所需要取消的课程，则调用另一个取消函数取消该门课程
	}else{
		return false;
	}
}


bool Student::existCourse(Course *course)
{
	for(int i=0;i<courseNumber;i++){
		if(courseList[i]==course) return true;
	}
	return false;
}

const Course& Student::operator[](int subscript) const
{
	if (subscript < 0 || subscript >=courseNumber ){
	   cerr <<"下标越界: " << subscript << endl;
	   exit( 1 ); // 访问越界，退出程序
	}
	return (*courseList[subscript]); //返回值，只能作右值，不能修改
}

Course& Student::operator[](int subscript)
{
	if (subscript < 0 || subscript >=courseNumber ){
	   cerr <<"下标越界: " << subscript << endl;
	   exit( 1 ); // 访问越界，退出程序
	}
	return (*courseList[subscript]); //返回值，只能作右值，不能修改
}

int Student::calcObligatoryCredit() const
{
	int totalCredit=0;
	for(int i=0;i<courseNumber;i++){
		/*使用RTTI，如果使用RTTI需要包含ObligatoryCourse.h头文件
		if( typeid(ObligatoryCourse)==typeid((*this)[i])){
			totalCredit+=(*this)[i].getCreditHour();
		}*/
		//使用多态计算必修课总学分
		totalCredit += (*this)[i].getObligatoryCredit();
	}
	return totalCredit;
}

int Student::calcElectiveNumber() const
{
	int number=0;
	for(int i=0;i<courseNumber;i++){
		/*使用RTTI，如果使用RTTI需要包含ElectiveCourse.h头文件
		if(typeid(ElectiveCourse)==typeid((*this)[i])){
			number++;
		}*/
		//使用多态计算选修课门数
		number += (*this)[i].getElectiveNumber();
	}
	return number;
}

double Student::calcAchievement() const
{
	int obligatoryCredit=calcObligatoryCredit();	//必修课总学分
	int electiveNumber=calcElectiveNumber();	//选修课总门次
	/*部分使用多态, 部分使用RTTI，此时需要包含两个派生类的头文件
	int obligatoryAchievement=0;	//必修课程积点
	int electiveAchievement=0;		//选修课程积点
	for(int i=0; i<courseNumber;i++){
		if( typeid(CObligatoryCourse)==typeid((*this)[i])){
			obligatoryAchievement+=(*this)[i].getScore()*(*this)[i].getCreditHour();
		}
		if(typeid(CElectiveCourse)==typeid((*this)[i])){
			electiveAchievement+=(*this)[i].getScore();
		}
	}
	double result=0;
	if(obligatoryCredit>0) result+=0.6*obligatoryAchievement/obligatoryCredit;
	if(electiveNumber>0) result+=0.4*electiveAchievement/electiveNumber;*/

	//使用多态
	double result=0;
	for(int i=0;i<courseNumber;i++){
		if(obligatoryCredit>0)
			result+=(*this)[i].getWeight() * (*this)[i].getScore() * (*this)[i].getObligatoryCredit()/obligatoryCredit;
		if(electiveNumber>0)
			result+=(*this)[i].getWeight() * (*this)[i].getScore() * (*this)[i].getElectiveNumber()/electiveNumber;
	}
	return result;
}

ostream& operator<<(ostream& output, const Student& s)
{
	output<<"姓名："<<s.name<<"\t出生日期："<<s.birthDate
		<<"\t积点成绩："<<s.calcAchievement()
		<<"，选课信息如下：\n";
	for(int i=0;i<s.getCourseNumber();i++){
		output<<s[i];
	}
	return output;
}
