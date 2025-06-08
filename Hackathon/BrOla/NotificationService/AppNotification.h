#ifndef APP_NOTIFICATION_H
#define APP_NOTIFICATION_H
#include "NotificationService.h"
#include<bits/stdc++.h>
using namespace std;
class AppNotification:public NotificationService{
    string mobile;
    string msg;
    public:
    AppNotification(string mobile,string msg){
        this->mobile=mobile;
        this->msg=msg;
    }
    void notify() override{
        cout<<"Notification sent to "<<mobile<<endl;
        cout<<msg<<endl;
    }
};
#endif