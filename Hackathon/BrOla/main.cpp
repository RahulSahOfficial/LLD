#include<bits/stdc++.h>
#include "./Utils/Location.h"
#include "./NotificationService/NotificationService.h"
#include "./NotificationService/AppNotification.h"
#include "./NotificationService/SMSNotification.h"
#include "./OtpService/OtpService.h"
using namespace std;
// Global 
unordered_map<string,double> vehicleTypeToPrice;
double basePrice=49;
class Vehicle{
    public:
    string name;
    string company;
    string type;
    string number;
    Vehicle(string name,string company,string type,string number){
        this->name=name;
        this->company=company;
        this->type=type;
        this->number=number;
    }
    void print(){
        cout<<"Vehicle : "<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Company : "<<company<<endl;
        cout<<"Type : "<<type<<endl;
        cout<<"Number : "<<number<<endl;
    }
};
//User Class
class User{
    public:
    string name;
    string phoneNumber;
    Location* currentLocation;
    User(string name,string phoneNumber,Location *currentLocation){
        this->name=name;
        this->phoneNumber=phoneNumber;
        this->currentLocation=currentLocation;
    }
};
class Rider:public User{
    public:
    Location* defaultPickupLocation;
    // Contructor if not passing default pickup location
    Rider(string name,string phoneNumber,Location *currentLocation): User(name, phoneNumber, currentLocation), defaultPickupLocation(currentLocation) {}
    Rider(string name,string phoneNumber,Location *currentLocation,Location *defaultPickupLocation):User(name,phoneNumber,currentLocation){
        this->defaultPickupLocation=defaultPickupLocation;
    }
};
class Driver:public User{
    public:
    Vehicle *vehicle;
    double rating;
    bool isOnline;
    bool isAvailable;
    Driver(string name,string phoneNumber,Location *currentLocation,Vehicle *vehicle):User(name,phoneNumber,currentLocation){
        this->vehicle=vehicle;
        isOnline=false;
        isAvailable=false;
        rating=3;
    }
    string getVehicleType(){
        return vehicle->type;
    }
    double getRating(){
        return rating;
    }
    void changeRating(double diff){
        double newRating=rating+diff;
        newRating=max(0.0,newRating);
        newRating=min(5.0,newRating);
        rating=newRating;
    }
    void print(){
        cout<<"Driver : "<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Phone : "<<phoneNumber<<endl;
        cout<<"Rating : "<<rating<<endl;
        currentLocation->print();
        vehicle->print();
        cout<<endl;
    }
};
class FareCalculator{
    public:
    virtual double calculatePrice(double,string)=0;
};
class BaseFareCalculator:public FareCalculator{
    double basePrice;
    public:
    BaseFareCalculator(){
        basePrice=49;
    }
    double calculatePrice(double distance,string vehicleType) override {
        double pricePerKm=vehicleTypeToPrice[vehicleType];
        double price=basePrice+distance*pricePerKm;
        return price;
    }
};
class PriceDecorator:public FareCalculator{
    public:
    FareCalculator *fc;
    PriceDecorator(FareCalculator *fc){
        this->fc=fc;
    }
};
class SurgeDecorator:public PriceDecorator{
    double surgeMultiplier;
    public:
    SurgeDecorator(FareCalculator *fc):PriceDecorator(fc){
        surgeMultiplier=1.05;    
    };
    double calculatePrice(double distance,string vehicleType) override{
        return fc->calculatePrice(distance,vehicleType)*surgeMultiplier;
    }
};
class Ride{
    public:
    Driver *driver;
    Rider *rider;
    Location *source;
    Location *destination;
    string vehicleType;
    string otp;
    double price;
    string status;
    bool isPeakHour;
    Ride(Rider *rider,Location *source,Location *destination,string vehicleType,bool isPeakHour){
        this->driver=nullptr;
        this->rider=rider;
        this->source=source;
        this->vehicleType=vehicleType;
        this->destination=destination;
        this->isPeakHour=isPeakHour;
        this->status="Assiging Rider";
        this->otp=OtpService::generateOtp(4);
        this->price=calculatePrice();
    }
    double calculatePrice(){
        double distance=source->getDistance(destination);
        FareCalculator *calc=new BaseFareCalculator();
        if(isPeakHour)
            calc=new SurgeDecorator(calc);
        return calc->calculatePrice(distance,vehicleType);
    }
    void print(){
        cout<<"Ride : "<<endl;
        cout<<"Driver : "<<driver<<endl;
        cout<<"Rider : "<<rider<<endl;
        cout<<"Source : "<<endl;
        source->print();
        cout<<"Destination : "<<endl;
        destination->print();
        cout<<"Vehicle Type : "<<vehicleType<<endl;
        cout<<"OTP : "<<otp<<endl;
        cout<<"Price : "<<price<<endl;
        cout<<"status : "<<status<<endl;
        cout<<"isPeakHour : "<<isPeakHour<<endl;
    }
};
class DriverAssignStrategy{
    public:
    virtual Driver* assignDriver(Location*,Location*,set<Driver*>)=0;
};
class NearestDriver:public DriverAssignStrategy{
    public:
    Driver* assignDriver(Location *source,Location *destination,set<Driver*> availableDrivers){
        if(availableDrivers.size()==0)
            return nullptr;
        priority_queue<pair<double,Driver*>> pq;
        for(auto each:availableDrivers){
            double distanceBewteenDriverAndRiderSource=each->currentLocation->getDistance(source);
            pq.push({-distanceBewteenDriverAndRiderSource,each});
        }
        return pq.top().second;
    }
};
class HighestRatedDriver:public DriverAssignStrategy{
    public:
    Driver* assignDriver(Location *source,Location *destination,set<Driver*> availableDrivers){
        if(availableDrivers.size()==0)
            return nullptr;
        priority_queue<pair<double,Driver*>> pq;
        for(auto each:availableDrivers){
            double rating=each->getRating();
            pq.push({rating,each});
        }
        return pq.top().second;
    }
};
class IRideManager{
    static unordered_map<string,set<Driver *>> availableRiders;
    static unordered_map<Driver*,Ride*> waitingQueue;
    static unordered_map<Driver*,Ride*> driverToRide;
    static unordered_map<Rider*,Ride*> riderToRide;
    static IRideManager *obj;
    IRideManager(){
    }
    public:
    static IRideManager* getInstance(){
        if(obj==nullptr)
            obj=new IRideManager();
        return obj;
    }
    void goOnline(Driver *driver){
        driver->isOnline=true;
        driver->isAvailable=true;
        string vehicleType=driver->getVehicleType();
        availableRiders[vehicleType].insert(driver);
    }
    void goOffline(Driver *driver){
        if(!driver->isAvailable){
            throw runtime_error("Cannot go offline. Complete the ride");
            return;
        }
        driver->isOnline=false;
        driver->isAvailable=false;
        string vehicleType=driver->getVehicleType();
        availableRiders[vehicleType].erase(driver);
        
    }
    void createRide(Rider *rider,string vehicleType,Location *source,Location *destination,bool isPeakHour,DriverAssignStrategy *strategy){
        Ride *newRide=new Ride(rider,source,destination,vehicleType,isPeakHour);
        riderToRide[rider]=newRide;
        newRide->print();
        auto availableDriversOfSelectedVehicle=availableRiders[vehicleType];
        Driver *driverAssigned=strategy->assignDriver(source,destination,availableDriversOfSelectedVehicle);
        cout<<driverAssigned<<endl;
        if(driverAssigned){
            newRide->driver=driverAssigned;
            availableRiders[vehicleType].erase(driverAssigned);
            driverToRide[driverAssigned]=newRide;
            newRide->status="Rider en Route";
        }
        else{
            cout<<"Not assiged"<<endl;
            newRide->status="No Rider Found";
        }
        newRide->print();
    }
};
unordered_map<string,set<Driver *>> IRideManager::availableRiders;
unordered_map<Driver*,Ride*> IRideManager::waitingQueue;
unordered_map<Driver*,Ride*> IRideManager::driverToRide;
unordered_map<Rider*,Ride*> IRideManager::riderToRide;
IRideManager* IRideManager::obj=nullptr;
int main(){
    srand(time(0));
    // Types of Vehicle 
    vehicleTypeToPrice["Bike"]=5;
    vehicleTypeToPrice["Sedan"]=6;
    vehicleTypeToPrice["SUV"]=6;
    vehicleTypeToPrice["AutoRikshaw"]=6;

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
    Location *dest1=new Location(10,10);
    Rider *r1=new Rider("Sah","5675765676",source1);

    IRideManager *rideManager=IRideManager::getInstance();

    rideManager->goOnline(d1);
    rideManager->goOnline(d2);
    rideManager->createRide(r1,"SUV",source1,dest1,true,new HighestRatedDriver());

    NotificationService *nf=new AppNotification("Xperia","otp "+OtpService::generateOtp(4));
    nf->notify();

    NotificationService *nf1=new SMSNotification("5675688900","otp "+OtpService::generateOtp(4));
    nf1->notify();
    return 0;
}