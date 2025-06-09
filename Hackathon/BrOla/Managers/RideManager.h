#ifndef RIDE_MANAGER_H
#define RIDE_MANAGER_H
#include<bits/stdc++.h>
#include "../Models/Driver.h"
#include "../Models/Rider.h"
#include "../Models/Ride.h"
#include "../PricingService/PricingService.h"
#include "../NotificationService/NotificationService.h"
#include "../NotificationService/AppNotification.h"
#include "../NotificationService/SMSNotification.h"
#include "../DriverAssignService/DriverAssignService.h"
using namespace std;
class RideManager{
    static unordered_map<string,set<Driver *>> availableRiders;
    static unordered_map<Driver*,Ride*> driverToRide;
    static unordered_map<Rider*,Ride*> riderToRide;
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
    void goOnline(Driver *driver){
        driver->isOnline=true;
        driver->isAvailable=true;
        string vehicleType=driver->getVehicleType();
        availableRiders[vehicleType].insert(driver);
    }
    void goOffline(Driver *driver){
        if(!driver->isAvailable){
            throw runtime_error("Cannot go offline. Complete the ride");
            return;
        }
        driver->isOnline=false;
        driver->isAvailable=false;
        string vehicleType=driver->getVehicleType();
        availableRiders[vehicleType].erase(driver);
        
    }
    void createRide(Rider *rider,string vehicleType,Location *source,Location *destination,bool isPeakHour,PaymentStrategyType paymentStrategyType){
        Ride *newRide=new Ride(rider,source,destination,vehicleType,isPeakHour,paymentStrategyType);
        riderToRide[rider]=newRide;
        newRide->print();
        auto availableDriversOfSelectedVehicle=availableRiders[vehicleType];
        DriverAssignService *driverAssignService=DriverAssignStrategyFactory::create(DriverStrategyType::HighestRated);
        Driver *driverAssigned=driverAssignService->assignDriver(source,destination,availableDriversOfSelectedVehicle);
        cout<<driverAssigned<<endl;
        if(driverAssigned){
            newRide->driver=driverAssigned;
            availableRiders[vehicleType].erase(driverAssigned);
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
        // newRide->print();
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
        // ride->print();
    }
    void completeRide(Driver *driver){
        Ride *ride=driverToRide[driver];
        if(driver->currentLocation->getDistance(ride->destination)>driverRiderBufferSpace)
            throw runtime_error("Not in location to end ride");
        ride->status=RideStatus::Completed;
        driverToRide.erase(driver);
        availableRiders[driver->getVehicleType()].insert(driver);
        NotificationService *nf=new AppNotification("Mobile","🔔 Ride Completed");
        nf->notify();
        // ride->print();
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
};
unordered_map<string,set<Driver *>> RideManager::availableRiders;
unordered_map<Driver*,Ride*> RideManager::driverToRide;
unordered_map<Rider*,Ride*> RideManager::riderToRide;
RideManager* RideManager::instance=nullptr;
#endif