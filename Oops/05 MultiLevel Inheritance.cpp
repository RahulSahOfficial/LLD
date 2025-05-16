#include<bits/stdc++.h>
using namespace std;
class Person{
    public:
    string name;
    int age;
    Person(const string name,const int age):name(name),age(age){
        cout<<"Person Constructor"<<endl;
    }
    void display(){
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<endl;
    }
    ~Person(){
        cout<<"Person Destructor"<<endl;
    }
};
class Employee:public Person{
    public:
    int salary;
    Employee(const string name,const int age,const int salary):Person(name,age),salary(salary){
        cout<<"Employee Constructor"<<endl;
    }
    void display(){
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Salary : "<<salary<<endl;
        cout<<endl;
    }
    ~Employee(){
        cout<<"Employee Destructor"<<endl;
    }
};
class Manager:public Employee{
    public:
    string dept;
    int noOfEmp;
    Manager(const string name,const int age,const int salary,const string dept,const int noOfEmp):Employee(name,age,salary),dept(dept),noOfEmp(noOfEmp){
        cout<<"Manager Constructor"<<endl;
    }
    void display(){
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Salary : "<<salary<<endl;
        cout<<"Department : "<<dept<<endl;
        cout<<"No of People Working Under : "<<noOfEmp<<endl;
        cout<<endl;
    }
    ~Manager(){
        cout<<"Manager Destructor"<<endl;
    }
};
int main(){
    Employee e1("Sah",24,89999);  
    Manager m1("Barik",24,89999,"IT",5);
    e1.display();
    m1.display();  
    return 0;
}