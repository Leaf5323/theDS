#include<iostream>
#include"Student.hpp"
using namespace std;

class StudentsDatabase{
    public:
    StudentsDatabase(int);
    ~StudentsDatabase();
    void addStudent();
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