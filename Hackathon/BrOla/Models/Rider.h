#ifndef RIDER_H
#define RIDER_H
#include<bits/stdc++.h>
#include "../Utils/Location.h"
#include "./User.h"
using namespace std;
class Rider:public User{
    public:
    Location* defaultPickupLocation;
    Rider(string name,string phoneNumber,Location *currentLocation,Location *defaultPickupLocation):User(name,phoneNumber,currentLocation){
        this->defaultPickupLocation=defaultPickupLocation;
    }
    void setDefaultPickupLocation(Location *newLocation){
        defaultPickupLocation=newLocation;
    }
    void print(){
        cout<<"Rider :"<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Phone Number : "<<phoneNumber<<endl;
        cout<<"Current Location : "<<endl;
        currentLocation->print();
        cout<<"Default Pickup Location : "<<endl;
        defaultPickupLocation->print();
    }
};
#endif