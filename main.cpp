#include<iostream>
#include<iomanip>
#include"./head/StudentsDatabase.hpp"
using namespace std;

int enterChoice();
void renderMenu();

int main(){
    system("title ��ʼ��ѧ����Ϣ");
    int initSize;
    cout<<"�������ʼѧ��������";
    cin>>initSize;
    while(cin.fail()){
        if(cin.fail()){
            cin.clear();
            cout<<"��������ݲ��Ϸ��������������ݺ���������(�س��Լ���)"<<endl;
            system("pause>nul");
            cout<<"�������ʼѧ��������";
            while(cin.get()!='\n'){
                continue;
            }
            cin>>initSize;
        }
    }
    StudentsDatabase studentDB(initSize);
    bool userExit=false;
    int input;
    while(!userExit){
        system("cls");
        system("title ���˵�");
        switch(input=enterChoice()){
            case 1:
                system("cls");
                system("title ��ѯѧ����Ϣ");
                studentDB.inquiryStudentInfo();
                break;
            case 2:
                system("cls");
                system("title ���ѧ����Ϣ");
                studentDB.addStudent();
                break;
            case 3:
                system("cls");
                system("title ɾ��ѧ����Ϣ");
                studentDB.deleteStudent();
                break;
            case 4:
                system("cls");
                system("title �޸�ѧ����Ϣ");
                studentDB.editStudentInfo();
                break;
            case 5:
                userExit=true;
                break;
        }
    }
    return 0;
}

int enterChoice(){
    int choice=0;
    while(choice<1||choice>5){
        renderMenu();
        cin>>choice;
        while(cin.fail()){
            if(cin.fail()){
                cin.clear();
                cout<<"��������ݲ��Ϸ��������������ݺ���������(�س��Լ���)"<<endl;
                system("pause>nul");
                system("cls");
                renderMenu();
                while(cin.get()!='\n'){
                    continue;
                }
                cin>>choice;
            }
        }
    }
    return choice;
}
void renderMenu(){
    cout<<"##############################"<<endl
        <<setw(20)<<setfill(' ')<<"���˵�"<<endl;
    cout<<"1)��ѯѧ����Ϣ"<<endl
        <<"2)���ѧ����Ϣ"<<endl
        <<"3)ɾ��ѧ����Ϣ"<<endl
        <<"4)�޸�ѧ����Ϣ"<<endl
        <<"5)�˳�ϵͳ"<<endl
        <<"##############################"<<endl;
    cout<<"���������ѡ��";
}