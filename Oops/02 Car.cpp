// 2. Car Class:
// Challenge: Create a Car class that simulates the behavior of a vehicle.
// Attributes:
// model: String representing the car model name.
// year: Integer indicating the car's manufacturing year.
// fuelLevel: Double representing the remaining fuel quantity (percentage or liters).
// speed: Integer representing the current speed in kilometers per hour.
// isRunning: Boolean indicating whether the car is currently running.
// Methods:
// startEngine(): Sets isRunning to true and prints a starting message.
// stopEngine(): Sets isRunning to false and prints a stopping message.
// accelerate(amount): Increases the car's speed by the specified amount (check engine state and fuel level).
// brake(amount): Decreases the car's speed by the specified amount (ensure speed doesn't become negative).
// refuel(amount): Increases the fuel level by the specified amount (check for tank capacity).
// printStatus(): Displays the car's model, speed, fuel level, and running state.



#include<bits/stdc++.h>
using namespace std;
class Car{
    string model;
    int year;
    double fuelLevel;
    int speed;
    bool isRunning;
    public:
    Car(const string model,const int year): 
        model(model),year(year),fuelLevel(0),speed(0),isRunning(false){}
    void startEngine(){
        isRunning=true;
        cout<<this->model<<" Engine Started"<<endl;
    }
    void stopEngine(){
        isRunning=false;
        cout<<this->model<<" Engine Stopped"<<endl;
    }
    void accelerate(const int amount){
        if(!this->isRunning)
            cout<<"Car is Not Started!"<<endl;
        else if(this->fuelLevel==0)
            cout<<"No Fuel"<<endl;
        else
            this->speed+=amount;
    }
    void brake(const int amount){
        this->speed=max(this->speed-amount,0);
    }
    void refuel(const double amount){
        this->fuelLevel+=amount;
    }
    void printStatus(){
        cout<<"Car :  Model : "<<this->model<<" Speed : "<<this->speed<<" FuelLevel : "<<this->fuelLevel<<" isRunning : "<<this->isRunning<<endl;
    }
};
int main(){
    Car c1("Alto",2000);
    c1.startEngine();
    c1.refuel(50);
    c1.accelerate(10);
    c1.printStatus();
    c1.brake(5);
    c1.printStatus();
    c1.stopEngine();
    c1.printStatus();
    return 0;
}