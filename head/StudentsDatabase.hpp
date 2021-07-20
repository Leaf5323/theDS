#include<iostream>
#include"Student.hpp"
using namespace std;

class StudentsDatabase{
    public:
    StudentsDatabase(int);
    ~StudentsDatabase();
    Student* findTarget(long);
    Student* findPre(long);
    void addStudent();
    void deleteStudent();
    void inquiryStudentInfo();
    void editStudentInfo();
    Student* getHead();
    private:
    Student* head;
};

StudentsDatabase::StudentsDatabase(int count){
    this->head=NULL;
    Student* p=NULL;
    Student* q=NULL;
    q=new Student;
    this->head=q;
    long tempID;
    string tempName;
    int tempScore;
    for(int i=0;i<count;i++){
        cout<<"请输入第"<<i+1<<"位学生学号：";
        cin>>tempID;
        cout<<"请输入第"<<i+1<<"位学生姓名：";
        cin>>tempName;
        cout<<"请输入第"<<i+1<<"位学生成绩：";
        cin>>tempScore;
        p=q;
        q=new Student(tempID,tempName,tempScore);
        q->setTheNext(NULL);
        p->setTheNext(q);
    }
}
StudentsDatabase::~StudentsDatabase(){
    
}
Student* StudentsDatabase::getHead(){
    return this->head;
}
Student* StudentsDatabase::findTarget(long targetID){
    Student* ptr1=NULL;
    Student* ptr2=NULL;
    Student* ptr3=NULL;
    ptr1=this->head->getNext();
    while(ptr1){
        ptr2=ptr1;
        if(ptr2->getStudentID()==targetID){
            ptr3=ptr2;
        }
        ptr1=ptr1->getNext();
    }
    return ptr3;
}
Student* StudentsDatabase::findPre(long targetID){
    Student* ptr1=NULL;
    Student* ptr2=NULL;
    ptr1=this->head->getNext();
    while(ptr1){
        if(ptr1->getStudentID()==targetID){
            ptr2=ptr1;
        }
        ptr1=ptr1->getNext();
    }
    return ptr2;
}
void StudentsDatabase::addStudent(){
    Student* ptr1=NULL;
    Student* ptr2=NULL;
    Student* ptr3=NULL;
    long tempID;
    string tempName;
    int tempScore;
    ptr1=this->getHead()->getNext();
    while(ptr1){
        ptr2=ptr1;
        ptr1=ptr1->getNext();
    }
    cout<<"请输入第要添加的学生学号：";
    cin>>tempID;
    cout<<"请输入第要添加的学生姓名：";
    cin>>tempName;
    cout<<"请输入第要添加的学生成绩：";
    cin>>tempScore;
    ptr3=new Student(tempID,tempName,tempScore);
    ptr3->setTheNext(NULL);
    ptr2->setTheNext(ptr3);
}
void StudentsDatabase::deleteStudent(){
    Student* ptr1=NULL;
    Student* ptr2=NULL;
    Student* ptr3=NULL;
    long tempID;
    cout<<"请输入删除学生的学号：";
    cin>>tempID;
    ptr1=this->findTarget(tempID);
    ptr2=this->findPre(tempID);
    ptr2->setTheNext(ptr1->getNext());
    delete ptr1;
}
void StudentsDatabase::inquiryStudentInfo(){
    long tempID;
    cout<<"请输入要查询的"<<endl;
    cin>>tempID;
    Student* ptr=this->findTarget(tempID);
    cout<<"查询结果："<<endl
        <<"学生姓名："<<ptr->getStudentName()<<endl
        <<"学生成绩："<<ptr->getStudentName()<<endl;
}
void StudentsDatabase::editStudentInfo(){
    Student* ptr=NULL;
    int choice=0;
    long tempID;
    string tempName;
    int tempScore;
    cout<<"请输入要修改的学号："<<endl;
    cin>>tempID;
    ptr=this->findTarget(tempID);
    cout<<"请选择要修改的内容："<<endl
        <<"1)学生姓名"<<endl
        <<"2)学生成绩"<<endl
        <<"3)返回上一级菜单"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            cout<<"当前学生姓名为："<<ptr->getStudentName()<<endl
                <<"请输入修改的内容：";
            cin>>tempName;
            ptr->setStudentName(tempName);
            cout<<"已修改学生姓名。"<<endl;
            break;
        case 2:
            cout<<"当前学生成绩为："<<ptr->getStudentScore()<<endl
                <<"请输入修改的内容：";
            cin>>tempScore;
            ptr->setStudentScore(tempScore);
            cout<<"已修改学生成绩。"<<endl;
            break;
        case 3:
            exit();
    }   
}