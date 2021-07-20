#include<iostream>
using namespace std;

class Student{
    public:
    Student(long=0,string="default",int=0);
    long getStudentID();
    string getStudentName();
    int getStudentScore();
    Student* setTheNext(Student*);
    Student* getNext();
    void setStudentName(string);
    void setStudentScore(int);
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
long Student::getStudentID(){
    return this->studentID;
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
void Student::setStudentName(string newName){
    this->studnetName=newName;
}
void Student::setStudentScore(int newScore){
    this->studentScore=newScore;
}