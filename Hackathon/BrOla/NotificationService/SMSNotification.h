#ifndef SMS_NOTIFICATION_H
#define SMS_NOTIFICATION_H
#include "./INotification.h"
#include<bits/stdc++.h>
using namespace std;
class SMSNotification:public INotification{
    string phoneNumber;
    string msg;
    public:
    SMSNotification(string phoneNumber,string msg){
        this->phoneNumber=phoneNumber;
        this->msg=msg;
    }
    void notify() override{
        cout<<"SMS sent to "<<phoneNumber<<" : "<<msg<<endl;
    }
};
#endif