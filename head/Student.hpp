#include<iostream>
using namespace std;

class Student{
    public:
    Student(double=0,string="default",float=0);
    double getStudentID();
    string getStudentName();
    float getStudentScore();
    Student* setTheNext(Student*);
    Student* getNext();
    void setStudentName(string);
    void setStudentScore(float);
    private:
    double studentID;
    string studnetName;
    float studentScore;
    Student* theNext;
};

Student::Student(double id,string name,float score){
    this->studentID=id>0?id:0;
    this->studnetName=name;
    this->studentScore=score>0?score:0;
}
double Student::getStudentID(){
    return this->studentID;
}
string Student::getStudentName(){
    return this->studnetName;
}
float Student::getStudentScore(){
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
void Student::setStudentScore(float newScore){
    this->studentScore=newScore;
}