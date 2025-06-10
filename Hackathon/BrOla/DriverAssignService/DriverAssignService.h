#ifndef DRIVER_ASSIGN_SERVICE_H
#define DRIVER_ASSIGN_SERVICE_H
#include<bits/stdc++.h>
#include "../Types/Types.h"
#include "../Models/Driver.h"
#include "../Utils/Location.h"
/*
Assumption : First Rider base on filter automatically accpepts the ride
as here in loop we cannot accept and reject the ride in runtime
*/
class DriverAssignService{
    public:
    virtual Driver* assignDriver(Location*,Location*,set<Driver*>)=0;
};
class NearestDriver:public DriverAssignService{
    public:
    Driver* assignDriver(Location *source,Location *destination,set<Driver*> availableDrivers){
        if(availableDrivers.size()==0)
            return nullptr;
        priority_queue<pair<double,Driver*>> pq;
        for(auto each:availableDrivers){
            double distanceBewteenDriverAndRiderSource=each->currentLocation->getDistance(source);
            // cout<<each->name<<" "<<distanceBewteenDriverAndRiderSource<<endl;
            pq.push({-distanceBewteenDriverAndRiderSource,each});
        }
        //returning the top rider based on min distance
        return pq.top().second;
    }
};
class HighestRatedDriver:public DriverAssignService{
    public:
    Driver* assignDriver(Location *source,Location *destination,set<Driver*> availableDrivers){
        if(availableDrivers.size()==0)
            return nullptr;
        priority_queue<pair<double,Driver*>> pq;
        for(auto each:availableDrivers){
            double rating=each->getRating();
            pq.push({rating,each});
        }
        //returning the top rider based on rating
        return pq.top().second;
    }
};
class DriverAssignStrategyFactory{
    public:
    static DriverAssignService* create(DriverStrategyType strategyType){
        if(strategyType==DriverStrategyType::Nearest)
            return new NearestDriver();
        else if(strategyType==DriverStrategyType::HighestRated)
            return new HighestRatedDriver();
        return nullptr;
    }
};
#endif