#include "Console.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Date.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
using namespace std;

Console::Console()
{
    //ctor
    ocNum=0;
    ecNum=0;
}

Console::~Console()
{
    //dtor
    if(student!=NULL) delete student;//�ͷ�ѧ����Ϣ

    int i;
    for(i=0;i<ocNum;i++)
		delete oc[i];//�ͷ����еı��޿γ�
	for(i=0;i<ecNum;i++)
		delete ec[i];//�ͷ����е�ѡ�޿γ�
}


int Console::run()
{
    char fileName[256];
    ofstream *ofile;

    buildCourse();  //�������еĿ�ѡ�γ̶���
    buildStudent(); //����ѧ������

    int choice=displayMenu();
    while (choice!=0)
    {
        switch (choice)
        {
            case 1: //ѡ���޿�
            case 2: //ѡѡ�޿�
                student->addCourse(selectCourse(choice));
                break;
            case 3: //���ѧ��ѡ����Ϣ����ʱ�������ɼ���
                cout<<*student;
                break;
            case 4: //����ѧ���ɼ�
                setCourseScore();
                break;
            case 5:
				cout<<"��������Ҫ������ļ�����";
				cin>>fileName;
				ofile=new ofstream(fileName);
				if(!ofile){
					cerr<<"�޷������ļ���\n";
					break;
				}
				(*ofile)<<*student;
				ofile->close();
				delete ofile;
				break;
        }
        choice=displayMenu();
    }

    return 0;
}

int Console::displayMenu() const
{
	int choice=0;
	cout<<"**********ѧ��ѡ��ϵͳ-���˵�**********\n"
		<<"\t1. ѡ���޿γ�\n"
		<<"\t2. ѡѡ�޿γ�\n"
		<<"\t3. �鿴ѡ�����\n"
		<<"\t4. ���ÿγ̳ɼ�\n"
		<<"\t5. ����γ̳ɼ�\n"
		<<"\t0. �˳�ϵͳ\n"
		<<"��ѡ������Ĳ���(0~4)��";
	cin>>choice;
	return choice;
}

Course* Console::selectCourse(int op)
{
    int i, choice=-1;
    switch(op)
    {
        case 1: //ѡ���޿�
            cout<<"������б��޿γ���ѡ��һ�ſγ�:\n";
            while((choice>ocNum)||(choice<0)){
                for(i=0;i<ocNum;i++){
                    cout<<"\t"<<i+1<<"."<<*oc[i];
                }
                cout<<"\t0.ȡ������ѡ��\n";
                cout<<"��Ҫѡ�ı��޿γ��ǣ�";
                cin>>choice;
            }
            if (choice!=0) return oc[choice-1];
            break;
        case 2: //ѡѡ�޿�
            cout<<"�������ѡ�޿γ���ѡ��һ�ſγ�:\n";
            while((choice>ecNum)||(choice<0)){
                for(i=0;i<ecNum;i++){
                    cout<<"\t"<<i+1<<"."<<*ec[i];
                }
                cout<<"\t0.ȡ������ѡ��\n";
                cout<<"��Ҫѡ��ѡ�޿γ��ǣ�";
                cin>>choice;
            }
            if (choice!=0) return ec[choice-1];
            break;
    }
    return NULL;
}

bool Console::setCourseScore()
{
	int mark=0;
	char grade='\0';
	for(int i=0;i<student->getCourseNumber();i++){
		if(typeid(ObligatoryCourse)==typeid((*student)[i])){//����RTTI,�ж��ǲ��Ǳ��޿�
			cout<<"���޿γ̡�"<<(*student)[i].getName()<<"���ĳɼ�(0-100)��";
			cin>>mark;
			while (!dynamic_cast<ObligatoryCourse &>((*student)[i]).setMark(mark)){
				cout<<"��ʽ���󣬱��޿γ̡�"<<(*student)[i].getName()<<"���ĳɼ�(0-100)��";
				cin>>mark;
			}
		}else if (typeid(ElectiveCourse)==typeid((*student)[i])){//����RTTI,�ж��ǲ���ѡ�޿�
			cout<<"ѡ�޿γ̡�"<<(*student)[i].getName()<<"���ĳɼ�(A-E)��";
			cin>>grade;
			while (!dynamic_cast<ElectiveCourse &>((*student)[i]).setGrade(grade)){
				cout<<"��ʽ����ѡ�޿γ̡�"<<(*student)[i].getName()<<"���ĳɼ�(A-E)��";
				cin>>grade;
			}
		}else{
			return false;
		}
	}
	return true;
}

Console& Console::buildStudent()
{
    char name[50];
	Date birthDate;

	cout<<"������ѧ������: ";
	cin>>name;
	cout<<"������ѧ������";
	cin>>birthDate;
	student=new Student(name, birthDate);
	return *this;
}

Console& Console::buildCourse()
{
    char fileName[]=".\\data\\CourseList.dat";
	ifstream ifile(fileName);
	int catalog, credit;
	string cname;
	ocNum=ecNum=0;
	if (!ifile){
		return *this;
	}
	while(ifile>>catalog>>cname>>credit){
		switch (catalog){
		case 1:
			oc[ocNum++]=new ObligatoryCourse(cname, credit);
			break;
		case 2:
			ec[ecNum++]=new ElectiveCourse(cname, credit);
			break;
		}
	}
	ifile.close();

	return *this;
}
