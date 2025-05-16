#include<bits/stdc++.h>
using namespace std;
class Car{
    public:
        string brand;
        string model;
        bool isEngineStart;
        int currentSpeed;
        Car(const string brand,const string model):brand(brand),model(model){
            isEngineStart=false;
            currentSpeed=0;
        }
        void startEngine(){
            isEngineStart=true;
        }
        void accelerate(){
            currentSpeed++;
        }
        void brake(){
            if(currentSpeed)
                currentSpeed--;
        }
        void stopEngine(){
            currentSpeed=0;
            isEngineStart=false;
        }
        void display(){
            cout<<brand<<" "<<model<<" "<<isEngineStart<<" "<<currentSpeed<<" "<<endl;
        }
};
class ManualCar:public Car{
    public:
    int currentGear;
    ManualCar(string brand,string model):Car(brand,model){};
    void shifGear(int gear){
        currentGear=gear;
    }
};
class ElectricCar:public Car{
    public:
    int batteryPercentage;
    ElectricCar(string brand,string model):Car(brand,model){
        batteryPercentage=50;
    };
    void chargeBattery(){
        cout<<"charging Battery"<<endl;
        batteryPercentage=min(batteryPercentage+1,100);
    }
};
int main(){
    ElectricCar tesla=ElectricCar("Telsa","S4");
    cout<<tesla.batteryPercentage<<endl;
    tesla.display();
    tesla.chargeBattery();
    cout<<tesla.batteryPercentage<<endl;

    ManualCar maruti=ManualCar("Suzuki","i10");
    maruti.shifGear(2);
    cout<<maruti.currentGear<<endl;
    maruti.display();
    return 0;
}