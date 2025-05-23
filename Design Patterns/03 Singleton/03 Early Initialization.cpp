#include<bits/stdc++.h>
using namespace std;
class Singleton{
    static Singleton *instance;
    Singleton(){}
    public:
    static Singleton* getInstance(){
        return instance;
    }
    void print(){
        cout<<instance<<" Print"<<endl;
    }
};
Singleton* Singleton::instance=new Singleton();
int main(){
    Singleton *ins1=Singleton::getInstance();
    Singleton *ins2=Singleton::getInstance();
    ins1->print();  
    ins2->print();  
    return 0;
}