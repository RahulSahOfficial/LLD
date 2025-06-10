#ifndef USER_H
#define USER_H
#include<bits/stdc++.h>
#include "../Utils/Location.h"
using namespace std;
// Parent class of both rider and driver
class User{
    public:
    string name;
    string phoneNumber;
    Location* currentLocation;
    User(string name,string phoneNumber,Location *currentLocation){
        this->name=name;
        this->phoneNumber=phoneNumber;
        this->currentLocation=currentLocation;
    }
    void updateLocation(Location *newLocation){
        currentLocation=newLocation;
    }
};
#endif