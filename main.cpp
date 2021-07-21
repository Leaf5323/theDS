#include<iostream>
#include<iomanip>
#include"./head/StudentsDatabase.hpp"
using namespace std;

int enterChoice();
void renderMenu();

int main(){
    system("title 初始化学生信息");
    int initSize;
    cout<<"请输入初始学生人数：";
    cin>>initSize;
    while(cin.fail()){
        if(cin.fail()){
            cin.clear();
            cout<<"输入的内容不合法，请检查输入内容后重新输入(回车以继续)"<<endl;
            system("pause>nul");
            cout<<"请输入初始学生人数：";
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
        system("title 主菜单");
        switch(input=enterChoice()){
            case 1:
                system("cls");
                system("title 查询学生信息");
                studentDB.inquiryStudentInfo();
                break;
            case 2:
                system("cls");
                system("title 添加学生信息");
                studentDB.addStudent();
                break;
            case 3:
                system("cls");
                system("title 删除学生信息");
                studentDB.deleteStudent();
                break;
            case 4:
                system("cls");
                system("title 修改学生信息");
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
                cout<<"输入的内容不合法，请检查输入内容后重新输入(回车以继续)"<<endl;
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
        <<setw(20)<<setfill(' ')<<"主菜单"<<endl;
    cout<<"1)查询学生信息"<<endl
        <<"2)添加学生信息"<<endl
        <<"3)删除学生信息"<<endl
        <<"4)修改学生信息"<<endl
        <<"5)退出系统"<<endl
        <<"##############################"<<endl;
    cout<<"请输入你的选择：";
}