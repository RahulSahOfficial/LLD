#ifndef RIDER_H
#define RIDER_H
#include<bits/stdc++.h>
#include "../Utils/Location.h"
#include "./User.h"
using namespace std;
class Rider:public User{
    public:
    Location* defaultPickupLocation;
    // Contructor if not passing default pickup location
    Rider(string name,string phoneNumber,Location *currentLocation): User(name, phoneNumber, currentLocation), defaultPickupLocation(currentLocation) {}
    Rider(string name,string phoneNumber,Location *currentLocation,Location *defaultPickupLocation):User(name,phoneNumber,currentLocation){
        this->defaultPickupLocation=defaultPickupLocation;
    }
};
#endif