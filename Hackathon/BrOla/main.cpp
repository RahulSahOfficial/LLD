#include<bits/stdc++.h>
#include "./Models/Driver.h"
#include "./Models/Rider.h"
#include "./Models/Ride.h"
#include "./Types/Types.h"
#include "./Managers/RideManager.h"
using namespace std;
int main(){
    srand(time(0));
    try{
        Location *d1Loc=new Location(2,2);
        Vehicle *scorpio=new Vehicle("Scorpio","Mahindra","SUV","JH09AX4512");
        Driver *d1=new Driver("Driver1","9998887777",d1Loc,scorpio);
        d1->changeRating(0.7);
        d1->print();

        Location *d2Loc=new Location(7,7);
        Vehicle *thar=new Vehicle("THAR","Mahindra","SUV","JH09AX4511");
        Driver *d2=new Driver("Driver2","1234566782",d2Loc,thar);
        
        d2->print();

        Location *source1=new Location(8,8);
        Location *dest1=new Location(20,20);
        Rider *r1=new Rider("Sah","5675765676",source1);

        RideManager *rideManager=RideManager::getInstance();

        rideManager->goOnline(d1);
        // rideManager->goOnline(d2);
        rideManager->createRide(r1,"SUV",source1,dest1,true,PaymentStrategyType::COD);
        d1->updateLocation(source1);
        rideManager->validateAndStartRide(d1,"1234");
        d1->updateLocation(dest1);
        rideManager->completeRide(d1);
        rideManager->makePayment(r1);
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
    return 0;
}