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
        cout<<"�������"<<i+1<<"λѧ��ѧ�ţ�";
        cin>>tempID;
        while(cin.fail()){
            if(cin.fail()){
                cin.clear();
                cout<<"��������ݲ��Ϸ��������������ݺ���������(�س��Լ���)"<<endl;
                system("pause>nul");
                cout<<"�������"<<i+1<<"λѧ��ѧ�ţ�";
                while(cin.get()!='\n'){
                    continue;
                }
                cin>>tempID;
            }
        }
        cout<<"�������"<<i+1<<"λѧ��������";
        cin>>tempName;
        while(cin.fail()){
            if(cin.fail()){
                cin.clear();
                cout<<"��������ݲ��Ϸ��������������ݺ���������(�س��Լ���)"<<endl;
                system("pause>nul");
                cout<<"�������"<<i+1<<"λѧ��������";
                while(cin.get()!='\n'){
                    continue;
                }
                cin>>tempName;
            }
        }
        cout<<"�������"<<i+1<<"λѧ���ɼ���";
        cin>>tempScore;
        while(cin.fail()){
            if(cin.fail()){
                cin.clear();
                cout<<"��������ݲ��Ϸ��������������ݺ���������(�س��Լ���)"<<endl;
                system("pause>nul");
                cout<<"�������"<<i+1<<"λѧ���ɼ���";
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
    cout<<"��������..."<<endl;
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
    cout<<"������Ҫ��ӵ�ѧ��ѧ�ţ�";
    cin>>tempID;
    while(cin.fail()){
        if(cin.fail()){
            cin.clear();
            cout<<"��������ݲ��Ϸ��������������ݺ���������(�س��Լ���)"<<endl;
            system("pause>nul");
            cout<<"������Ҫ��ӵ�ѧ��ѧ�ţ�";
            while(cin.get()!='\n'){
                continue;
            }
            cin>>tempID;
        }
    }
    cout<<"������Ҫ��ӵ�ѧ��������";
    cin>>tempName;
    while(cin.fail()){
        if(cin.fail()){
            cin.clear();
            cout<<"��������ݲ��Ϸ��������������ݺ���������(�س��Լ���)"<<endl;
            system("pause>nul");
            cout<<"������Ҫ��ӵ�ѧ��������";
            while(cin.get()!='\n'){
                continue;
            }
            cin>>tempName;
        }
    }
    cout<<"������Ҫ��ӵ�ѧ���ɼ���";
    cin>>tempScore;while(cin.fail()){
        if(cin.fail()){
            cin.clear();
            cout<<"��������ݲ��Ϸ��������������ݺ���������(�س��Լ���)"<<endl;
            system("pause>nul");
            cout<<"������Ҫ��ӵ�ѧ���ɼ���";
            while(cin.get()!='\n'){
                continue;
            }
            cin>>tempScore;
        }
    }
    ptr3=new Student(tempID,tempName,tempScore);
    ptr3->setTheNext(NULL);
    ptr2->setTheNext(ptr3);
    cout<<"��ӳɹ�~(�س��Լ���)"<<endl;
    system("pause>nul");
}
int StudentsDatabase::deleteStudent(){
    Student* ptr1=NULL;
    Student* ptr2=NULL;
    Student* ptr3=NULL;
    double tempID;
    cout<<"������ɾ��ѧ����ѧ�ţ�";
    cin>>tempID;
    while(cin.fail()){
        if(cin.fail()){
            cin.clear();
            cout<<"��������ݲ��Ϸ��������������ݺ���������(�س��Լ���)"<<endl;
            system("pause>nul");
            cout<<"������ɾ��ѧ����ѧ�ţ�";
            while(cin.get()!='\n'){
                continue;
            }
            cin>>tempID;
        }
    }
    ptr1=this->findTarget(tempID);
    if(ptr1==NULL){
        cout<<"δ���ҵ�ѧ�������������ѧ��(�س��Լ���)"<<endl;
        system("pause>nul");
        return 1;
    }
    ptr2=this->findPre(tempID);
    ptr2->setTheNext(ptr1->getNext());
    delete ptr1;
    cout<<"ɾ���ɹ�~(�س��Լ���)"<<endl;
    system("pause>nul");
    return 0;
}
int StudentsDatabase::inquiryStudentInfo(){
    double tempID;
    cout<<"������Ҫ��ѯ��ѧ�ţ�";
    cin>>tempID;
    while(cin.fail()){
        if(cin.fail()){
            cin.clear();
            cout<<"��������ݲ��Ϸ��������������ݺ���������(�س��Լ���)"<<endl;
            system("pause>nul");
            cout<<"������Ҫ��ѯ��ѧ�ţ�";
            while(cin.get()!='\n'){
                continue;
            }
            cin>>tempID;
        }
    }
    Student* ptr=this->findTarget(tempID);
    if(ptr==NULL){
        cout<<"δ���ҵ�ѧ�������������ѧ��(�س��Լ���)"<<endl;
        system("pause>nul");
        return 1;
    }
    cout<<"��ѯ�����"<<endl
        <<"ѧ��������"<<ptr->getStudentName()<<endl
        <<"ѧ���ɼ���"<<ptr->getStudentScore()<<endl
        <<"(�س��Լ���)"<<endl;
    system("pause>nul");
    return 0;
}
int StudentsDatabase::editStudentInfo(){
    Student* ptr=NULL;
    int choice=0;
    double tempID;
    string tempName;
    float tempScore;
    cout<<"������Ҫ�޸ĵ�ѧ�ţ�";
    cin>>tempID;
    while(cin.fail()){
        if(cin.fail()){
            cin.clear();
            cout<<"��������ݲ��Ϸ��������������ݺ���������(�س��Լ���)"<<endl;
            system("pause>nul");
            cout<<"������Ҫ�޸ĵ�ѧ�ţ�";
            while(cin.get()!='\n'){
                continue;
            }
            cin>>tempID;
        }
    }
    ptr=this->findTarget(tempID);
    if(ptr==NULL){
        cout<<"δ���ҵ�ѧ�������������ѧ��(�س��Լ���)"<<endl;
        system("pause>nul");
        return 1;
    }
    cout<<"��ѡ��Ҫ�޸ĵ����ݣ�"<<endl
        <<"1)ѧ������"<<endl
        <<"2)ѧ���ɼ�"<<endl
        <<"3)������һ���˵�"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            cout<<"��ǰѧ������Ϊ��"<<ptr->getStudentName()<<endl
                <<"�������޸ĵ����ݣ�";
            cin>>tempName;
            while(cin.fail()){
                if(cin.fail()){
                    cin.clear();
                    cout<<"��������ݲ��Ϸ��������������ݺ���������(�س��Լ���)"<<endl;
                    system("pause>nul");
                    cout<<"��ǰѧ������Ϊ��"<<ptr->getStudentName()<<endl
                        <<"�������޸ĵ����ݣ�";
                    while(cin.get()!='\n'){
                        continue;
                    }
                    cin>>tempName;
                }
            }
            ptr->setStudentName(tempName);
            cout<<"���޸�ѧ��������"<<endl;
            break;
        case 2:
            cout<<"��ǰѧ���ɼ�Ϊ��"<<ptr->getStudentScore()<<endl
                <<"�������޸ĵ����ݣ�";
            cin>>tempScore;
            while(cin.fail()){
                if(cin.fail()){
                    cin.clear();
                    cout<<"��������ݲ��Ϸ��������������ݺ���������(�س��Լ���)"<<endl;
                    system("pause>nul");
                    cout<<"��ǰѧ���ɼ�Ϊ��"<<ptr->getStudentScore()<<endl
                        <<"�������޸ĵ����ݣ�";
                    while(cin.get()!='\n'){
                        continue;
                    }
                    cin>>tempScore;
                }
            }
            ptr->setStudentScore(tempScore);
            cout<<"���޸�ѧ���ɼ���"<<endl;
            break;
        case 3:
            cout<<"���ڷ���..."<<endl;
            break;
    }
    return 0;  
}