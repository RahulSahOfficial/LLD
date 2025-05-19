#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    int x,y;
    A(int x,int y){
        this->x=x;
        this->y=y;
    }
    virtual void display(){
        cout<<x<<" "<<y<<endl;
    }
};
class B:public A{
    public:
    int z;
    B(int x,int y,int z):A(x,y){
        this->z=z;
    }
    void display() override {
        cout<<x<<" "<<y<<" "<<z<<endl;
    }
};
class Parent{
    public:
    virtual A* getData(){
        A *a=new A(1,2);
        return a;
    }
};
class Child:public Parent{
    public:
    B* getData() override{//returning narrower class object
        B *b=new B(3,4,5);
        return b;
    }
};
int main(){
    Parent *obj=new Parent();
    // Parent *obj=new Child();
    A *data=obj->getData();
    data->display();
    return 0;
}