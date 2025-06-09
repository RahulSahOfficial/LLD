#ifndef VEHICLE_H
#define VEHICLE_H
#include<bits/stdc++.h>
using namespace std;
class Vehicle{
    public:
    string name;
    string company;
    string type;
    string number;
    Vehicle(string name,string company,string type,string number){
        this->name=name;
        this->company=company;
        this->type=type;
        this->number=number;
    }
    void print(){
        cout<<"Vehicle : "<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Company : "<<company<<endl;
        cout<<"Type : "<<type<<endl;
        cout<<"Number : "<<number<<endl;
    }
};
#endif