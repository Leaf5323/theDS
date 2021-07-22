#include<iostream>
#include"Student.hpp"
using namespace std;

class StudentsDatabase{
    public:
    StudentsDatabase(int);
    ~StudentsDatabase();
    Student* findTarget(double);
    Student* findPre(double);
    void addStudent();
    int deleteStudent();
    int inquiryStudentInfo();
    int editStudentInfo();
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
    double tempID;
    string tempName;
    float tempScore;
    for(int i=0;i<count;i++){
        cout<<"请输入第"<<i+1<<"位学生学号：";
        cin>>tempID;
        while(cin.fail()){
            if(cin.fail()){
                cin.clear();
                cout<<"输入的内容不合法，请检查输入内容后重新输入(回车以继续)"<<endl;
                system("pause>nul");
                cout<<"请输入第"<<i+1<<"位学生学号：";
                while(cin.get()!='\n'){
                    continue;
                }
                cin>>tempID;
            }
        }
        cout<<"请输入第"<<i+1<<"位学生姓名：";
        cin>>tempName;
        while(cin.fail()){
            if(cin.fail()){
                cin.clear();
                cout<<"输入的内容不合法，请检查输入内容后重新输入(回车以继续)"<<endl;
                system("pause>nul");
                cout<<"请输入第"<<i+1<<"位学生姓名：";
                while(cin.get()!='\n'){
                    continue;
                }
                cin>>tempName;
            }
        }
        cout<<"请输入第"<<i+1<<"位学生成绩：";
        cin>>tempScore;
        while(cin.fail()){
            if(cin.fail()){
                cin.clear();
                cout<<"输入的内容不合法，请检查输入内容后重新输入(回车以继续)"<<endl;
                system("pause>nul");
                cout<<"请输入第"<<i+1<<"位学生成绩：";
                while(cin.get()!='\n'){
                    continue;
                }
                cin>>tempScore;
            }
        }
        p=q;
        q=new Student(tempID,tempName,tempScore);
        q->setTheNext(NULL);
        p->setTheNext(q);
    }
}
StudentsDatabase::~StudentsDatabase(){
    cout<<"正在清理..."<<endl;
}
Student* StudentsDatabase::getHead(){
    return this->head;
}
Student* StudentsDatabase::findTarget(double targetID){
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
Student* StudentsDatabase::findPre(double targetID){
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
    double tempID;
    string tempName;
    float tempScore;
    ptr1=this->getHead()->getNext();
    while(ptr1){
        ptr2=ptr1;
        ptr1=ptr1->getNext();
    }
    cout<<"请输入要添加的学生学号：";
    cin>>tempID;
    while(cin.fail()){
        if(cin.fail()){
            cin.clear();
            cout<<"输入的内容不合法，请检查输入内容后重新输入(回车以继续)"<<endl;
            system("pause>nul");
            cout<<"请输入要添加的学生学号：";
            while(cin.get()!='\n'){
                continue;
            }
            cin>>tempID;
        }
    }
    cout<<"请输入要添加的学生姓名：";
    cin>>tempName;
    while(cin.fail()){
        if(cin.fail()){
            cin.clear();
            cout<<"输入的内容不合法，请检查输入内容后重新输入(回车以继续)"<<endl;
            system("pause>nul");
            cout<<"请输入要添加的学生姓名：";
            while(cin.get()!='\n'){
                continue;
            }
            cin>>tempName;
        }
    }
    cout<<"请输入要添加的学生成绩：";
    cin>>tempScore;while(cin.fail()){
        if(cin.fail()){
            cin.clear();
            cout<<"输入的内容不合法，请检查输入内容后重新输入(回车以继续)"<<endl;
            system("pause>nul");
            cout<<"请输入要添加的学生成绩：";
            while(cin.get()!='\n'){
                continue;
            }
            cin>>tempScore;
        }
    }
    ptr3=new Student(tempID,tempName,tempScore);
    ptr3->setTheNext(NULL);
    ptr2->setTheNext(ptr3);
    cout<<"添加成功~(回车以继续)"<<endl;
    system("pause>nul");
}
int StudentsDatabase::deleteStudent(){
    Student* ptr1=NULL;
    Student* ptr2=NULL;
    Student* ptr3=NULL;
    double tempID;
    cout<<"请输入删除学生的学号：";
    cin>>tempID;
    while(cin.fail()){
        if(cin.fail()){
            cin.clear();
            cout<<"输入的内容不合法，请检查输入内容后重新输入(回车以继续)"<<endl;
            system("pause>nul");
            cout<<"请输入删除学生的学号：";
            while(cin.get()!='\n'){
                continue;
            }
            cin>>tempID;
        }
    }
    ptr1=this->findTarget(tempID);
    if(ptr1==NULL){
        cout<<"未查找到学生，请检查输入的学号(回车以继续)"<<endl;
        system("pause>nul");
        return 1;
    }
    ptr2=this->findPre(tempID);
    ptr2->setTheNext(ptr1->getNext());
    delete ptr1;
    cout<<"删除成功~(回车以继续)"<<endl;
    system("pause>nul");
    return 0;
}
int StudentsDatabase::inquiryStudentInfo(){
    double tempID;
    cout<<"请输入要查询的学号：";
    cin>>tempID;
    while(cin.fail()){
        if(cin.fail()){
            cin.clear();
            cout<<"输入的内容不合法，请检查输入内容后重新输入(回车以继续)"<<endl;
            system("pause>nul");
            cout<<"请输入要查询的学号：";
            while(cin.get()!='\n'){
                continue;
            }
            cin>>tempID;
        }
    }
    Student* ptr=this->findTarget(tempID);
    if(ptr==NULL){
        cout<<"未查找到学生，请检查输入的学号(回车以继续)"<<endl;
        system("pause>nul");
        return 1;
    }
    cout<<"查询结果："<<endl
        <<"学生姓名："<<ptr->getStudentName()<<endl
        <<"学生成绩："<<ptr->getStudentScore()<<endl
        <<"(回车以继续)"<<endl;
    system("pause>nul");
    return 0;
}
int StudentsDatabase::editStudentInfo(){
    Student* ptr=NULL;
    int choice=0;
    double tempID;
    string tempName;
    float tempScore;
    cout<<"请输入要修改的学号：";
    cin>>tempID;
    while(cin.fail()){
        if(cin.fail()){
            cin.clear();
            cout<<"输入的内容不合法，请检查输入内容后重新输入(回车以继续)"<<endl;
            system("pause>nul");
            cout<<"请输入要修改的学号：";
            while(cin.get()!='\n'){
                continue;
            }
            cin>>tempID;
        }
    }
    ptr=this->findTarget(tempID);
    if(ptr==NULL){
        cout<<"未查找到学生，请检查输入的学号(回车以继续)"<<endl;
        system("pause>nul");
        return 1;
    }
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
            while(cin.fail()){
                if(cin.fail()){
                    cin.clear();
                    cout<<"输入的内容不合法，请检查输入内容后重新输入(回车以继续)"<<endl;
                    system("pause>nul");
                    cout<<"当前学生姓名为："<<ptr->getStudentName()<<endl
                        <<"请输入修改的内容：";
                    while(cin.get()!='\n'){
                        continue;
                    }
                    cin>>tempName;
                }
            }
            ptr->setStudentName(tempName);
            cout<<"已修改学生姓名。"<<endl;
            break;
        case 2:
            cout<<"当前学生成绩为："<<ptr->getStudentScore()<<endl
                <<"请输入修改的内容：";
            cin>>tempScore;
            while(cin.fail()){
                if(cin.fail()){
                    cin.clear();
                    cout<<"输入的内容不合法，请检查输入内容后重新输入(回车以继续)"<<endl;
                    system("pause>nul");
                    cout<<"当前学生成绩为："<<ptr->getStudentScore()<<endl
                        <<"请输入修改的内容：";
                    while(cin.get()!='\n'){
                        continue;
                    }
                    cin>>tempScore;
                }
            }
            ptr->setStudentScore(tempScore);
            cout<<"已修改学生成绩。"<<endl;
            break;
        case 3:
            cout<<"正在返回..."<<endl;
            break;
    }
    return 0;  
}