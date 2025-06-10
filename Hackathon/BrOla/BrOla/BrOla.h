#ifndef BROLA_H
#define BROLA_H
#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include "../Types/Types.h"
#include "../Managers/RideManager.h"
#include "../Managers/RiderManager.h"
#include "../Managers/DriverManager.h"
class BrOla{
    RiderManager *riderManager;
    DriverManager *driverManager;
    RideManager *rideManager;
    public:
    BrOla(){
        rideManager=RideManager::getInstance();
        driverManager=DriverManager::getInstance();
        riderManager=RiderManager::getInstance();
    }
    void run1(){
        // Driver Assignment based on Nearest Strategy
        // Creating Driver 1 
        Vehicle *safari=new Vehicle("Safari","Tata","SUV","JH01AA1234");
        Location *driver1Loc=new Location(2,2);
        Driver *driver1=driverManager->createDriver("Driver1","9998887777",driver1Loc,safari);

        // Creating Driver 2
        Vehicle *scorpio=new Vehicle("Scorpio","Mahindra","SUV","JH01BB1234");
        Location *driver2Loc=new Location(8,8);
        Driver *driver2=driverManager->createDriver("Driver2","9988776655",driver2Loc,scorpio);
        // Creating Driver 3
        Vehicle *creta=new Vehicle("Creta","Hyundai","SUV","JH01CC1234");
        Location *driver3Loc=new Location(15,0);
        Driver *driver3=driverManager->createDriver("Driver3","8877665544",driver3Loc,creta);

       //Creating Rider 1
        Location *riderCurrentLocation=new Location(12,0);
        Rider *rider1=riderManager->createRider("Sah","5675765676",riderCurrentLocation,riderCurrentLocation);

        // All riders are online now 
        driverManager->goOnline(driver1);
        driverManager->goOnline(driver2);
        driverManager->goOnline(driver3);
        driverManager->printAllDrivers();

        Location *destination=new Location(6,-5);
        rideManager->createRide(rider1,"SUV",riderCurrentLocation,destination,false,DriverStrategyType::Nearest,PaymentStrategyType::COD);
        // Driver 3 assined as he was nearest 
        // Driver 3 comes to riders location
        driverManager->updateLocation(driver3,riderCurrentLocation);
        // Driver Submits otp and starts the ride 
        rideManager->validateAndStartRide(driver3,"1234");
        // Driver Reached the destination 
        driverManager->updateLocation(driver3,destination);
        // Driver Completes the ride 
        rideManager->completeRide(driver3);
        // Rider makes the payment 
        rideManager->makePayment(rider1);
    }
   void run2(){
        // Driver Assignment based on Rating Strategy
        // Creating Driver 1 
        Vehicle *safari=new Vehicle("Safari","Tata","SUV","JH01AA1234");
        Location *driver1Loc=new Location(2,2);
        Driver *driver1=driverManager->createDriver("Driver1","9998887777",driver1Loc,safari);
        // Adding extra rating sor simulation 
        driverManager->changeRating(driver1,1.5);

        // Creating Driver 2
        Vehicle *scorpio=new Vehicle("Scorpio","Mahindra","SUV","JH01BB1234");
        Location *driver2Loc=new Location(8,8);
        Driver *driver2=driverManager->createDriver("Driver2","9988776655",driver2Loc,scorpio);
        driverManager->changeRating(driver2,1.0);

        // Creating Driver 3
        Vehicle *creta=new Vehicle("Creta","Hyundai","SUV","JH01CC1234");
        Location *driver3Loc=new Location(15,0);
        Driver *driver3=driverManager->createDriver("Driver3","8877665544",driver3Loc,creta);
        driverManager->changeRating(driver3,0.5);

       //Creating Rider 1
        Location *riderCurrentLocation=new Location(12,0);
        Rider *rider1=riderManager->createRider("Sah","5675765676",riderCurrentLocation,riderCurrentLocation);

        // All riders are online now 
        driverManager->goOnline(driver1);
        driverManager->goOnline(driver2);
        driverManager->goOnline(driver3);
        driverManager->printAllDrivers();

        Location *destination=new Location(6,-5);
        rideManager->createRide(rider1,"SUV",riderCurrentLocation,destination,true,DriverStrategyType::HighestRated,PaymentStrategyType::UPI);
        // Driver 1 assined as he has highest rating 
        // Driver 1 comes to riders location
        driverManager->updateLocation(driver1,riderCurrentLocation);
        // Driver Submits otp and starts the ride 
        rideManager->validateAndStartRide(driver1,"1234");
        // Driver Reached the destination 
        driverManager->updateLocation(driver1,destination);
        // Driver Completes the ride 
        rideManager->completeRide(driver1);
        // Rider makes the payment 
        rideManager->makePayment(rider1);
    }

    void run3(){
        // Driver Assignment based on Rating Strategy
        // Creating Driver 1 
        Vehicle *safari=new Vehicle("Safari","Tata","SUV","JH01AA1234");
        Location *driver1Loc=new Location(2,2);
        Driver *driver1=driverManager->createDriver("Driver1","9998887777",driver1Loc,safari);

        // Creating Driver 2
        Vehicle *scorpio=new Vehicle("Scorpio","Mahindra","SUV","JH01BB1234");
        Location *driver2Loc=new Location(8,8);
        Driver *driver2=driverManager->createDriver("Driver2","9988776655",driver2Loc,scorpio);

       //Creating Rider 1
        Location *riderCurrentLocation=new Location(12,0);
        Rider *rider1=riderManager->createRider("Sah","5675765676",riderCurrentLocation,riderCurrentLocation);

        // All riders are online now 
        driverManager->goOnline(driver1);
        driverManager->goOnline(driver2);
        driverManager->printAllDrivers();

        Location *destination=new Location(6,-5);
        rideManager->createRide(rider1,"BIKE",riderCurrentLocation,destination,true,DriverStrategyType::Nearest,PaymentStrategyType::UPI);
        
    }
};
#endif