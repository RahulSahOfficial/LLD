#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    int x,y;
    A(int x,int y){
        this->x=x;
        this->y=y;
    }
};
class B:public A{
    public:
    int z;
    B(int x,int y,int z):A(x,y){
        this->z=z;
    }
};
/*
Even though LSP says we can pass broader class
objects in method parameters but C++ says 
We want exact match if you want to do this
goto any other programming language
Wasted 30 minutes to implement & on research.
And also broader class may have less data members 
as compared to child class SO there may be problems
Hence C++ parameters are kept invariant.
*/


class Parent{
    public:
    virtual void print(A *a){
        cout<<"Parent "<<a->x<<" "<<a->y<<endl;
    }
};
class Child:public Parent{
    public:
    void print(A *a) override{
        cout<<"Child "<<a->x<<" "<<a->y<<endl;
    }
};
int main(){
    A* a=new B(1,2,3);
    // Parent *obj=new Child();
    Parent *obj=new Parent();
    obj->print(a);
    return 0;
}