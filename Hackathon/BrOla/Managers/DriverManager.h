#ifndef DRIVER_MANAGER_H
#define DRIVER_MANAGER_H
#include<bits/stdc++.h>
#include "../Models/Driver.h"
using namespace std;
class DriverManager{
    static unordered_map<string,set<Driver *>> availableRiders;
    static vector<Driver*> drivers;
    static DriverManager *instance;
    DriverManager(){
    }
    public:
    static DriverManager* getInstance(){
        if(instance==nullptr)
            instance=new DriverManager();
        return instance;
    }
    Driver* createDriver(string name,string phoneNumber,Location *currentLocation,Vehicle *vehicle){
        Driver *newDriver=new Driver(name,phoneNumber,currentLocation,vehicle);
        drivers.push_back(newDriver);
        cout<<"Driver "<<name<<" created!"<<endl;
        return newDriver;
    }
    string getVehicleType(Driver *driver){
        return driver->getVehicleType();
    }
    double getRating(Driver *driver){
        return driver->getRating();
    }
    void changeRating(Driver *driver,double diff){
        driver->changeRating(diff);
    }
    void printDriver(Driver *driver){
        driver->print();
    }
    vector<Driver*> getAllDrivers(){
        return drivers;
    }
    void printAllDrivers(){
        cout<<"All Drivers :"<<endl;
        for(auto each:drivers)
            each->print();
    }
    set<Driver*> getAvilableRiders(string vehicleType){
        return availableRiders[vehicleType];
    }
    void goOnline(Driver *driver){
        driver->isOnline=true;
        driver->isAvailable=true;
        string vehicleType=driver->getVehicleType();
        availableRiders[vehicleType].insert(driver);
    }
    void goOffline(Driver *driver){
        if(!driver->isAvailable){
            throw runtime_error("Cannot go offline. Complete the ride!");
            return;
        }
        driver->isOnline=false;
        driver->isAvailable=false;
        string vehicleType=driver->getVehicleType();
        availableRiders[vehicleType].erase(driver);
    }
    void makeAvilable(Driver *driver){
        availableRiders[driver->getVehicleType()].insert(driver);
    }
    void makeUnavilable(Driver *driver){
        availableRiders[driver->getVehicleType()].erase(driver);
    }
    void updateLocation(Driver *driver,Location *newLocation){
        driver->updateLocation(newLocation);
    }
};
unordered_map<string,set<Driver *>> DriverManager::availableRiders;
DriverManager* DriverManager::instance=nullptr;
vector<Driver*> DriverManager::drivers;
#endif