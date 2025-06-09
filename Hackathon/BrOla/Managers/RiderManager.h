#ifndef RIDER_MANAGER_H
#define RIDER_MANAGER_H
#include<bits/stdc++.h>
#include "../Utils/Location.h"
#include "../Models/Rider.h"
using namespace std;
class RiderManager{
    static vector<Rider*> riders;
    static RiderManager *instance;
    RiderManager(){
    }
    public:
    static RiderManager* getInstance(){
        if(instance==nullptr)
            instance=new RiderManager();
        return instance;
    }
    Rider* createRider(string name,string phoneNumber,Location *currentLocation,Location *defaultPickupLocation){
        Rider *newRider=new Rider(name,phoneNumber,currentLocation,defaultPickupLocation);
        riders.push_back(newRider);
        cout<<"Rider "<<name<<" created!"<<endl;
        return newRider;
    }
    vector<Rider*> getAllRiders(){
        return riders;
    }
    void printAllRiders(){
        for(auto each:riders)
            each->print();
    }
    void updateRiderLocation(Rider* rider, Location* newLocation){
        rider->updateLocation(newLocation);
    }
    void setDefaultPickupLocation(Rider* rider, Location* newLocation){
        rider->setDefaultPickupLocation(newLocation);
    }
    void updateLocation(Rider *rider,Location *newLocation){
        rider->updateLocation(newLocation);
    }
};
RiderManager* RiderManager::instance=nullptr;
vector<Rider*> RiderManager::riders;
#endif