#include<bits/stdc++.h>
using namespace std;
class Car{
    public:
        Car(){
            cout<<"Car Constructor"<<endl;
        }
        virtual void startEngine()=0;
        virtual void accelerate()=0;
        virtual void brake()=0;
        virtual void shiftGear(int)=0;
        virtual void stopEngine()=0;
        ~Car(){
            cout<<"Car Destructor"<<endl;
        }
};
class SportsCar : public Car{
    public:
    string brand;
    string model;
    bool isEngineStart;
    int currentSpeed;
    int currentGear;
    // public:
    SportsCar(const string brand,const string model):brand(brand),model(model){
        isEngineStart=false;
        currentGear=0;
        currentSpeed=0;
    }
    void startEngine() override {
        isEngineStart=true;
    }
    void accelerate() override {
        currentSpeed++;
    }
    void shiftGear(int newGear) override {
        currentGear=newGear;
    }
    void brake() override {
        if(currentSpeed)
            currentSpeed--;
    }
    void stopEngine() override {
        currentGear=0;
        currentSpeed=0;
        isEngineStart=false;
    }
    void display(){
        cout<<isEngineStart<<" "<<currentSpeed<<" "<<currentGear<<endl;
    }
};
int main(){
    SportsCar *sc=new SportsCar("Swift","i10");
    sc->display();
    sc->startEngine();
    sc->display();
    sc->accelerate();
    sc->display();
    sc->accelerate();
    sc->display();
    sc->shiftGear(2);
    sc->display();
    sc->brake();
    sc->display();
    sc->stopEngine();
    sc->display();
    delete sc;
    return 0;
}