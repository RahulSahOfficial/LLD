#ifndef APP_NOTIFICATION_H
#define APP_NOTIFICATION_H
#include "./INotification.h"
#include<bits/stdc++.h>
using namespace std;
class AppNotification:public INotification{
    string mobile;
    string msg;
    public:
    AppNotification(string mobile,string msg){
        this->mobile=mobile;
        this->msg=msg;
    }
    void notify() override{
        cout<<"Notification sent to 📱 : "<<msg<<endl;
    }
};
#endif