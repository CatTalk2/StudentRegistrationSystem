#ifndef CONSOLE_H
#define CONSOLE_H

#include "Student.h"
#include "Course.h"

//����̨�࣬ʵ���û�����
class Console
{
    public:
        int run();    //���п���̨

        Console();
        virtual ~Console();
    protected:
    private:
        int displayMenu() const;    //��ʾϵͳ���˵�
        Course* selectCourse(int op);     //ѡ�Σ����ؿγ̵�ַ��������op=1ѡ����޿Σ�op=2ѡ��ѡ�޿�
        bool setCourseScore();       //�������еĿγ̳ɼ�

        Console& buildStudent();//����ѧ������
        Console& buildCourse();//�������еĿ�ѡ�γ̣��������޺�ѡ�޿Σ�
        
        Student *student;           //��ǰѧ������
        Course *oc[MAX_SIZE];		//ȫ����ѡ�ı��޿γ��嵥
        Course *ec[MAX_SIZE];		//ȫ����ѡ��ѡ�޿γ��嵥
        int ocNum;      //��ѡ�ı��޿γ�ʵ������
        int ecNum;	//��ѡ��ѡ�޿γ�ʵ������
};

#endif // CONSOLE_H
