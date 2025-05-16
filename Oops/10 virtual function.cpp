#include<bits/stdc++.h>
using namespace std;
class Animal{
    public:
    virtual void speak()=0;
}; 
class Dog:public Animal{
    public:
        void speak() override{
            cout<<"Bhaw Bhaw!"<<endl;
        }
};
class Cat:public Animal{
    public:
        void speak() override{
            cout<<"Meow Meow!"<<endl;
        }
};
int main(){
    Animal *d;
    vector<Animal *> zoo;
    zoo.push_back(new Dog());
    zoo.push_back(new Cat());
    // zoo.push_back(new Animal());
    for(auto each:zoo)
        each->speak();
    return 0;
}