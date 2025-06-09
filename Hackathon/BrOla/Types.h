#ifndef TYPES_H
#define TYPES_H
#include<bits/stdc++.h>
using namespace std;
enum class DriverStrategyType { Nearest, HighestRated };
enum class PaymentStrategyType { UPI, COD };
enum class RideStatus {
    AssigningRider,
    RiderEnRoute,
    RideInProgress,
    NoRiderFound,
    Completed
};
string rideStatusToString(RideStatus status) {
    switch(status) {
        case RideStatus::AssigningRider: 
            return "Assigning Rider";
        case RideStatus::RiderEnRoute: 
            return "Rider en Route";
        case RideStatus::RideInProgress: 
            return "Rider In Progress";
        case RideStatus::NoRiderFound: 
            return "No Rider Found";
        case RideStatus::Completed: 
            return "Completed";
    }
}
#endif