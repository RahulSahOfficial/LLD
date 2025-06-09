#ifndef DRIVER_H
#define DRIVER_H
#include<bits/stdc++.h>
#include "../Utils/Location.h"
#include "./User.h"
#include "./Vehicle.h"
using namespace std;
class Driver:public User{
    public:
    Vehicle *vehicle;
    double rating;
    bool isOnline;
    bool isAvailable;
    Driver(string name,string phoneNumber,Location *currentLocation,Vehicle *vehicle):User(name,phoneNumber,currentLocation){
        this->vehicle=vehicle;
        isOnline=false;
        isAvailable=false;
        rating=3;
    }
    string getVehicleType(){
        return vehicle->type;
    }
    double getRating(){
        return rating;
    }
    void changeRating(double diff){
        double newRating=rating+diff;
        newRating=max(0.0,newRating);
        newRating=min(5.0,newRating);
        rating=newRating;
    }
    void print(){
        cout<<"Driver : "<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Phone : "<<phoneNumber<<endl;
        cout<<"Rating : "<<rating<<endl;
        currentLocation->print();
        vehicle->print();
        cout<<endl;
    }
};
#endif