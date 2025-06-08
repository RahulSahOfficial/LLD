#ifndef LOCATION_H
#define LOCATION_H
#include<bits/stdc++.h>
using namespace std;
//Location Class
class Location{
    public:
    int x;
    int y;
    Location(int x,int y){
        this->x=x;
        this->y=y;
    }
    double getDistance(Location *p){
        return sqrt(pow(x-p->x,2)+pow(y-p->y,2));
    }
    void print(){
        cout<<"Location : ("<<x<<","<<y<<")"<<endl;
    }
};
#endif