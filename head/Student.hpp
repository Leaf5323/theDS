#include<iostream>
using namespace std;

class Student{
    public:
    Student(long=0,string="default",int=0);
    string getStudentName();
    int getStudentScore();
    private:
    long studentID;
    string studnetName;
    int studentScore;
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

    
void FindStudent(SqList*L)
{
    int n;
    printf("请输入查找方式: \n0=学号查找\n1=储存位置查找");//查找方式的选择
    scanf("%d",&n);
    printf("请输入要查找的学生信息:");
    switch (n) {
        case 0:
            {
                long number;//输入需要查找的学生学号
                scanf("%ld",&number);
                for (int i=0;i<=L->length;i++)
                {
                    if(number==L->student[i].id)
                        PrintStudent(L,i);
                }
                break;
            }
        case 1:
            {
                int number;
                scanf("%d",&number);
                PrintStudent(L,number-1);
                break;
            }
        default:
            printf("您输入的查找方式有误请确认");
            break;
    }
    void DeletStudent (Sqlist*L,int i)
{
    if(i<0||i>sum)
        printf("输入信息有误");
    else
    {
        for (int m=i-1;m<sum;m++)
        {
            L->student[m]=L->student[m+1];        
        }//删除
        sum--;
        L->length--;
    }
    //更新表中的学生信息
void ReGetStudent(Sqlist*L)
{
    int p;
