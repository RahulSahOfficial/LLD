#include<bits/stdc++.h>
using namespace std;
class Machine{
    public:
    int enginePower;
    Machine(const int enginePower):enginePower(enginePower){
        cout<<"Machine Constructor"<<endl;
    }
    void display(){
        cout<<"EnginePower : "<<enginePower<<endl;
    }
    void displayEngine(){
        cout<<"Only EnginePower : "<<enginePower<<endl;
    }
    ~Machine(){
        cout<<"Machine Destructor"<<endl;
    }
};
class Vehicle{
    public:
    string brand;
    string model;
    Vehicle(const string brand,const string model):brand(brand),model(model){
        cout<<"Vehicle Costructor"<<endl;
    }
    void display(){
        cout<<"Brand : "<<brand<<endl;
        cout<<"Model : "<<model<<endl;
    }
    void displayVehicle(){
        cout<<"Only Brand : "<<brand<<endl;
        cout<<"Only Model : "<<model<<endl;
    }
    ~Vehicle(){
        cout<<"Vehicle Destructor"<<endl;
    }
};
class Car:public Machine,public Vehicle{
    public:
    int wheelCnt;
    Car(const string brand,
        const string model,
        const int enginePower,
        const int wheelCnt
    ):Vehicle(brand,model),Machine(enginePower),wheelCnt(wheelCnt){
        cout<<"Car Constructor"<<endl;
    }
    // void display(){
    //     cout<<"Brand : "<<brand<<endl;
    //     cout<<"Model : "<<model<<endl;
    //     cout<<"Engine Power : "<<enginePower<<endl;
    //     cout<<"Wheel Count : "<<wheelCnt<<endl;
    // }
    ~Car(){
        cout<<"Car Destructor"<<endl;
    }
};
int main(){
    Car c1("Tata","Cedan",1200,4);
    c1.displayEngine();
    c1.displayVehicle(); 
    c1.display();
    return 0;
}