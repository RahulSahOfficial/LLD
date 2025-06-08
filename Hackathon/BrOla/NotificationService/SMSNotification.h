#ifndef SMS_NOTIFICATION_H
#define SMS_NOTIFICATION_H
#include "NotificationService.h"
#include<bits/stdc++.h>
using namespace std;
class SMSNotification:public NotificationService{
    string phoneNumber;
    string msg;
    public:
    SMSNotification(string phoneNumber,string msg){
        this->phoneNumber=phoneNumber;
        this->msg=msg;
    }
    void notify() override{
        cout<<"SMS sent to "<<phoneNumber<<endl;
        cout<<msg<<endl;
    }
};
#endif