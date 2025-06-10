#ifndef DRIVER_MANAGER_H
#define DRIVER_MANAGER_H
#include<bits/stdc++.h>
#include "../Models/Driver.h"
using namespace std;
//Singleton Class
class DriverManager{
    //stores list of avilable rider map helps get only specifc type of vehicle
    unordered_map<string,set<Driver *>> availableDrivers;
    vector<Driver*> drivers;
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
    set<Driver*> getAvilableDrivers(string vehicleType){
        return availableDrivers[vehicleType];
    }
    void goOnline(Driver *driver){
        driver->isOnline=true;
        driver->isAvailable=true;
        string vehicleType=driver->getVehicleType();
        availableDrivers[vehicleType].insert(driver);
    }
    void goOffline(Driver *driver){
        if(!driver->isAvailable){
            throw runtime_error("Cannot go offline. Complete the ride!");
            return;
        }
        driver->isOnline=false;
        driver->isAvailable=false;
        string vehicleType=driver->getVehicleType();
        availableDrivers[vehicleType].erase(driver);
    }
    // When ride is completed driver becomes avilable
    void makeAvilable(Driver *driver){
        availableDrivers[driver->getVehicleType()].insert(driver);
    }
    // When driver is in ride he is unavilable
    void makeUnavilable(Driver *driver){
        availableDrivers[driver->getVehicleType()].erase(driver);
    }
    void updateLocation(Driver *driver,Location *newLocation){
        driver->updateLocation(newLocation);
    }
};
DriverManager* DriverManager::instance=nullptr;
#endif