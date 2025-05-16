#include<bits/stdc++.h>
using namespace std;
class Student{
    string name;
    const int roll;
    int marks=0;
    public:
    Student(int roll,string name="NOT SET",int marks=0) : roll(roll){
        this->name=name;
        this->marks=marks;
    }
    void setName(string inputName){
        name=inputName;
    }
    void setMarks(int inputMarks){
        marks=inputMarks;
    }
    string getName(){
        return name;
    }
    int getMarks(){
        return marks;
    }
    int getRoll(){
        return roll;
    }
    void display(){
        cout<<"Roll No : "<<roll<<" Name : "<<name<<" Marks  : "<<marks<<endl;
    }
};
class A{
    int val;
    public:
    A(int v){
        val=v;
    }
    A(A &cpy){
        this->val=cpy.val;
    }
    int getVal(){
        return val;
    }
    ~A(){
        cout<<"Destructor"<<endl;
    }
};

int main(){
    // vector<Student> s;
    // for(int i=0;i<5;i++){
    //     Student temp(i);
    //     s.push_back(temp);
    // }
    // for(int i=0;i<5;i++)
    //     s[i].display();
    A a(7);
    A b(1);
    b=a;
    cout<<b.getVal()<<endl;
    cout<<sizeof(b)<<endl;
    return 0;
}