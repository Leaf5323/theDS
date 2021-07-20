#include<iostream>
#include<iomanip>
#include"./head/StudentsDatabase.hpp"
using namespace std;

int enterChoice();

int main(){
    int initSize;
    cout<<"请输入初始学生人数：";
    cin>>initSize;
    StudentsDatabase studentDB(initSize);
    bool userExit=false;
    int input;
    while(!userExit){
        switch(input=enterChoice()){
            case 1:
                studentDB.inquiryStudentInfo();
                break;
            case 2:
                studentDB.addStudent();
                break;
            case 3:
                studentDB.deleteStudent();
                break;
            case 4:
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
        cout<<"##############################"<<endl
            <<setw(20)<<setfill(' ')<<"主菜单"<<endl;
        cout<<"1)查询学生信息"<<endl
            <<"2)添加学生信息"<<endl
            <<"3)删除学生信息"<<endl
            <<"4)修改学生信息"<<endl
            <<"5)退出系统"<<endl
            <<"##############################"<<endl;
        cout<<"请输入你的选择：";
        cin>>choice;
    }
    return choice;
}