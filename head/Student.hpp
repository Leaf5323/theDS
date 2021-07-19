#include<iostream>
using namespace std;

class Student{
    public:
    Student();
    void addStudnetInfo(long,string,int);
    void deleteStudentInfo(long);
    void editStudnetInfo(long);
    long getStudnetID();
    string getStudentName();
    int getStudentScore();
    private:
    long studentID;
    string studnetName;
    int studentScore;
};

Student::Student(){

}
long Student::getStudnetID(){
    return this->studentID;
}
string Student::getStudentName(){
    return this->studnetName;
}
int Student::getStudentScore(){
    return this->studentScore;
}