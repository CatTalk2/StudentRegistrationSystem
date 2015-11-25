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
    friend ostream& operator<<(ostream&, const Student &s);   //���������������Ԫ���������ѧ���Լ�ѡ����Ϣ
    public:
        double calcAchievement() const;	//����ѧ���Ļ���ɼ�

        /*����ѡ���б��һЩ��ز���*/
        bool existCourse(Course *course);//�ж��Ƿ��Ѿ�����ĳ�ſγ�
        Student& addCourse(Course *course);             //ͨ���γ�ָ����ӿγ̣�ʵ��ѧ��ѡ�ι���
        //Student& addCourse(const string &courseName, int creditHour);//ͨ���γ�����ѧ����Ϣ��ӿγ̣�ʵ��ѧ��ѡ�ι���

        bool removeCourse(int i);                       //ɾ��ָ��λ�õĿγ�
        bool removeCourse(const string& courseName);    //���ݿγ�����ɾ���γ�

        //�����±����������ȡ��ѧ����ĳ�ſγ���Ϣ
        const Course& operator[](int subscript) const;//������Ա������ֻ������Ϊ��ֵ
        Course& operator[](int subscript);	//��ͨ��Ա������Ϊ��ֵ������ͨ���ĳɺ������صĿγ���Ϣ���ÿγ̳ɼ�

        //void print() const;   //��ӡѧ����Ϣ

        Student& setName(const char* const n);//set��������������
        const char* getName() const {return name;}//get�������������
        const Date& getBirthDate() const {return birthDate;}//get�������������
        static int getCount() {return count;}//��̬get��������ö�������
        int getCourseNumber()const {return courseNumber;}

        Student(const char* const n, int y, int m, int d);//���캯��
        Student(const char* const n, const Date &d);//���캯��
        Student(const Student &s);  //�������캯��
        virtual ~Student(); //��������
    protected:
    private:
        char *name; //����
        const Date birthDate;   //����
        static int count;   //��̬��Ա������ͳ��ѧ����Ŀ

        int courseNumber;   //��ǰʵ�ʿγ���Ŀ
        Course *courseList[MAX_SIZE];   //�洢��ǰѧ����ѡ�Ŀγ�ָ��

        //���ߺ���
        int calcObligatoryCredit() const;//������޿���ѧ��
        int calcElectiveNumber() const;//����ѡ�޿�������
};

#endif // STUDENT_H
