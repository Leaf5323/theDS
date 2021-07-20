#include<iostream>
using namespace std;

class Student{
    public:
    Student(long=0,string="default",int=0);
    string getStudentName();
    int getStudentScore();
    Student* setTheNext(Student*);
    Student* getNext();
    private:
    long studentID;
    string studnetName;
    int studentScore;
    Student* theNext;
};

Student::Student(long id,string name,int score){
    this->studentID=id>0?id:0;
    this->studnetName=name;
    this->studentScore=score>0?score:0;
}
string Student::getStudentName(){
    return this->studnetName;
}
int Student::getStudentScore(){
    return this->studentScore;
}
Student* Student::setTheNext(Student* next){
    this->theNext=next;
    return this->theNext;
}
Student* Student::getNext(){
    return this->theNext;
}