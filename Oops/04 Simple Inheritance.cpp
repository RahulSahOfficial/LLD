#include<bits/stdc++.h>
using namespace std;
class Human{
    public:
    string name;
    int age;
    int weight;
    Human(string name,int age,int weight){
        cout<<"Human Constructor"<<endl;
        this->name=name;
        this->age=age;
        this->weight=weight;
    }
    void display(){
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Weight : "<<weight<<endl;
    }
    ~Human(){
        cout<<"Human Destructor"<<endl;
    }
};
class Student:public Human{
    public:
    int rollNo;
    int std;
    Student(string name,int age,int weight,int rollNo,int std):Human(name,age,weight){
        cout<<"Student Constructor"<<endl;
        this->rollNo=rollNo;
        this->std=std;
    }
    void display(){
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Weight : "<<weight<<endl;
        cout<<"RollNo : "<<rollNo<<endl;
        cout<<"Std : "<<std<<endl;
    }
    ~Student(){
        cout<<"Student Constructor"<<endl;
    }
};
int main(){
    Student s1("Sah",24,74,80,12);
    s1.display();
    // Human h1("a",2,4);
    // h1.display();
    return 0;
}