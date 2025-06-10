#ifndef TYPES_H
#define TYPES_H
#include<bits/stdc++.h>
using namespace std;
// Types of Driver Assign Strategy  
enum class DriverStrategyType { Nearest, HighestRated };
// Types of Payment Strategy 
enum class PaymentStrategyType { UPI, COD };
// Types of Notification Strategy 
enum class NotificationType {APP,SMS};
// Type of Ride Status  
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