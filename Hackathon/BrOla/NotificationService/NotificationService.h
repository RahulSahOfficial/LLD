#ifndef NOTIFICATION_SERVICE_H
#define NOTIFICATION_SERVICE_H
#include<bits/stdc++.h>
#include "./AppNotification.h"
#include "./SMSNotification.h"
#include "../Types/Types.h"
using namespace std;
class NotificationService{
    static void dispatch(NotificationType notificationType,string target,string message){
        INotification *notifier;
        if(notificationType == NotificationType::APP)
            notifier=new AppNotification(target,message);
        if(notificationType == NotificationType::SMS)
            notifier=new SMSNotification(target,message);
        notifier->notify();
    }
    public:
    // Different notifications
    static void sendRideBooked(Rider* rider, NotificationType notificationType) {
        string msg = "🔔 Ride Booked!";
        string phone = rider->phoneNumber;
        NotificationService::dispatch(notificationType, phone, msg);
    }
    static void sendRideOTP(Rider* rider,string otp, NotificationType notificationType) {
        string msg = "🔔 Ride OTP : "+otp;
        string phone = rider->phoneNumber;
        NotificationService::dispatch(notificationType, phone, msg);
    }
    static void sendRideAssigned(Rider* rider, NotificationType notificationType) {
        string msg = "🔔 Rider Assigned!";
        string phone = rider->phoneNumber;
        NotificationService::dispatch(notificationType, phone, msg);
    }
    static void sendNoRidesFound(Rider* rider, NotificationType notificationType) {
        string msg = "🔔 No Riders Found!";
        string phone = rider->phoneNumber;
        NotificationService::dispatch(notificationType, phone, msg);
    }
    static void sendRideStarted(Rider* rider, NotificationType notificationType) {
        string msg = "🔔 Ride Started!";
        string phone = rider->phoneNumber;
        NotificationService::dispatch(notificationType, phone, msg);
    }
    static void sendRideCompleted(Rider* rider, NotificationType notificationType) {
        string msg = "🔔 Ride Completed!";
        string phone = rider->phoneNumber;
        NotificationService::dispatch(notificationType, phone, msg);
    }
    static void sendPaymentDone(Rider* rider, NotificationType notificationType) {
        string msg = "🔔 Payment Done!";
        string phone = rider->phoneNumber;
        NotificationService::dispatch(notificationType, phone, msg);
    }
    static void sendUPIPaymentStatus(string phoneNumber,double amount,NotificationType notificationType){
        string msg = "🔔 Amount "+to_string(amount)+" paid via UPI";
        NotificationService::dispatch(notificationType, phoneNumber, msg);
    }
    static void sendCODPaymentStatus(string phoneNumber,double amount,NotificationType notificationType){
        string msg = "🔔 Amount "+to_string(amount)+" paid via CASH";
        NotificationService::dispatch(notificationType, phoneNumber, msg);
    }
};
#endif