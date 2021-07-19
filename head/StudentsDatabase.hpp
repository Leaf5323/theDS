#include<iostream>
#include"Student.hpp"
using namespace std;

class StudentsDatabase{
    public:
    StudentsDatabase(int);
    ~StudentsDatabase();
    string getStudentName(long);
    int getStudentScore(long);
    private:
    Student* students;
    int size;
};

StudentsDatabase::StudentsDatabase(int s){
    this->size=s>0?s:1;
    cout<<"请输入"<<this->size<<"位学生信息："<<endl;
    this->students=new Student[this->size];
    long tempID;
    string tempName;
    int tempScore;
    for(int i=0;i<this->size;i++){
        cout<<"学生"<<i+1<<"学号：";
        cin>>tempID;
        cout<<"学生"<<i+1<<"姓名：";
        cin>>tempName;
        cout<<"学生"<<i+1<<"成绩：";
        cin>>tempScore;
        this->students[i].~Student();
        this->students[i]=Student(tempID,tempName,tempScore);
    }
}
StudentsDatabase::~StudentsDatabase(){
    delete[]this->students;
}
string StudentsDatabase::getStudentName(long id){
    return this->students[id].getStudentName();
}
int StudentsDatabase::getStudentScore(long id){
    return this->students[id].getStudentScore();
}