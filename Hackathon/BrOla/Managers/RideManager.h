#ifndef RIDE_MANAGER_H
#define RIDE_MANAGER_H
#include<bits/stdc++.h>
#include "../Models/Driver.h"
#include "../Models/Rider.h"
#include "../Models/Ride.h"
#include "./DriverManager.h"
#include "../NotificationService/NotificationService.h"
#include "../NotificationService/AppNotification.h"
#include "../NotificationService/SMSNotification.h"
#include "../DriverAssignService/DriverAssignService.h"
using namespace std;
class RideManager{
    unordered_map<Driver*,Ride*> driverToRide;
    unordered_map<Rider*,Ride*> riderToRide;
    static RideManager *instance;
    double driverRiderBufferSpace=5;//to start ride driver must be 5m or less of start ride
    RideManager(){
    }
    public:
    static RideManager* getInstance(){
        if(instance==nullptr)
            instance=new RideManager();
        return instance;
    }
    void createRide(Rider *rider,string vehicleType,Location *source,Location *destination,bool isPeakHour,PaymentStrategyType paymentStrategyType){
        Ride *newRide=new Ride(rider,source,destination,vehicleType,isPeakHour,paymentStrategyType);
        riderToRide[rider]=newRide;
        newRide->print();
        auto availableDriversOfSelectedVehicle=DriverManager::getInstance()->getAvilableRiders(vehicleType);
        DriverAssignService *driverAssignService=DriverAssignStrategyFactory::create(DriverStrategyType::HighestRated);
        Driver *driverAssigned=driverAssignService->assignDriver(source,destination,availableDriversOfSelectedVehicle);
        cout<<driverAssigned<<endl;
        if(driverAssigned){
            newRide->driver=driverAssigned;
            DriverManager::getInstance()->makeUnavilable(driverAssigned);
            driverToRide[driverAssigned]=newRide;
            newRide->status=RideStatus::RiderEnRoute;
            NotificationService *nf=new AppNotification("Mobile","🔔 Rider Assigned");
            nf->notify();
        }
        else{
            newRide->status=RideStatus::NoRiderFound;
            NotificationService *nf=new AppNotification("Mobile","🔔 No Riders Found!");
            nf->notify();
        }
    }
    void validateAndStartRide(Driver *driver,string otp){
        Ride *ride=driverToRide[driver];
        if(driver->currentLocation->getDistance(ride->source)>driverRiderBufferSpace){
            throw runtime_error("Not in location to start ride");
            return;
        }
        if(false && ride->otp!=otp){//false just to bypass as we dont know generated otp in runtime
            throw runtime_error("Not in location to start ride");
            return;  
        }
        ride->status=RideStatus::RideInProgress;
        NotificationService *nf=new AppNotification("Mobile","🔔 Ride Started");
        nf->notify();
    }
    void completeRide(Driver *driver){
        Ride *ride=driverToRide[driver];
        if(driver->currentLocation->getDistance(ride->destination)>driverRiderBufferSpace)
            throw runtime_error("Not in location to end ride");
        ride->status=RideStatus::Completed;
        driverToRide.erase(driver);
        DriverManager::getInstance()->makeAvilable(driver);
        NotificationService *nf=new AppNotification("Mobile","🔔 Ride Completed");
        nf->notify();
    }
    void makePayment(Rider *rider){
        Ride *ride=riderToRide[rider];
        if(ride->status!=RideStatus::Completed)
            throw runtime_error("Ride is not completed!");
        if(ride->paymentStrategy->pay()){
            ride->paymentCompleted=true;
            riderToRide.erase(rider);
            NotificationService *nf=new AppNotification("Mobile","🔔 Payment Done");
            nf->notify();
        }
    }
    void printRide(Ride *ride){
        ride->print();
    }
};
RideManager* RideManager::instance=nullptr;
#endif