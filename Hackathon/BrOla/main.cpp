#include<bits/stdc++.h>
#include "./Types/Types.h"
#include "./Managers/RideManager.h"
#include "./Managers/RiderManager.h"
#include "./Managers/DriverManager.h"
using namespace std;
int main(){
    srand(time(0));
    try{
        Location *d1Loc=new Location(2,2);
        Vehicle *scorpio=new Vehicle("Scorpio","Mahindra","SUV","JH09AX4512");
        Driver *d1=DriverManager::getInstance()->createDriver("Driver1","9998887777",d1Loc,scorpio);
        DriverManager::getInstance()->changeRating(d1,0.7);
        DriverManager::getInstance()->printDriver(d1);

        Location *d2Loc=new Location(7,7);
        Vehicle *thar=new Vehicle("THAR","Mahindra","SUV","JH09AX4511");
        Driver *d2=DriverManager::getInstance()->createDriver("Driver2","1234566782",d2Loc,thar);
        DriverManager::getInstance()->printDriver(d2);

        Location *source1=new Location(8,8);
        Location *dest1=new Location(20,20);
        Rider *r1=RiderManager::getInstance()->createRider("Sah","5675765676",source1,source1);
        
        DriverManager::getInstance()->goOnline(d1);
        // DriverManager::getInstance()->goOnline(d2);
        DriverManager::getInstance()->printAllDrivers();
       
        RideManager::getInstance()->createRide(r1,"SUV",source1,dest1,true,PaymentStrategyType::COD);
        DriverManager::getInstance()->updateLocation(d1,source1);
        RideManager::getInstance()->validateAndStartRide(d1,"1234");
        DriverManager::getInstance()->updateLocation(d1,dest1);
        RideManager::getInstance()->completeRide(d1);
        RideManager::getInstance()->makePayment(r1);
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
    return 0;
}