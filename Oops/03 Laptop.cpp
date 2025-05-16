// 3. Laptop Class:
// Challenge: Design a Laptop class that represents a portable computer system.
// Attributes:
// brand: String representing the laptop brand and model.
// screenSize: Double indicating the screen size in inches.
// processor: String specifying the processor type and speed.
// ram: Integer representing the available RAM capacity in gigabytes.
// storage: Integer representing the storage capacity in gigabytes.
// batteryLevel: Double showing the remaining battery percentage.
// isOn: Boolean indicating whether the laptop is currently powered on.
// Methods:
// powerOn(): Sets isOn to true and prints a startup message.
// powerOff(): Sets isOn to false and prints a shutdown message.
// openApps(numApps): Simulates opening a specified number of applications, potentially impacting battery life.
// closeApps(numApps): Simulates closing applications, restoring battery life.
// charge(amount): Increases the battery level by the specified amount (check for maximum capacity).
// printSpecs(): Displays the laptop's brand, screen size, processor, RAM, storage, and battery level.


#include<bits/stdc++.h>
using namespace std;
class Laptop{
    string brand;
    double screenSize;
    string processor;
    int ram;
    int storage;
    double batteryLevel;
    bool isOn;
    public:
    Laptop(const string brand,const double screenSize,const string processor,const int ram,const int storage):
        brand(brand),screenSize(screenSize),processor(processor),ram(ram),storage(storage),batteryLevel(0),isOn(false){}
    void powerOn(){
        cout<<this->brand<<" powered ON"<<endl;
        this->isOn=true;
    }
    void powerOff(){
        cout<<this->brand<<" shuts down"<<endl;
        this->isOn=false;
    }
    void openApps(const int numApps){
        if(!this->isOn){
            cout<<"Laptop not ON";
            return;
        }
        for(int i=0;i<numApps;i++){
            if(this->batteryLevel==0){
                cout<<"Battery Over!!"<<endl;
                this->powerOff();
                return;
            }
            cout<<"Opening App "<<(i+1)<<endl;
            this->batteryLevel=max(this->batteryLevel-1,0.0);
        }
    }
    void closeApps(const int numApps){
        if(!this->isOn){
            cout<<"Laptop not ON"<<endl;
            return;
        }
        //vague description how i can increase battery if app is closed
        this->batteryLevel = min(this->batteryLevel + numApps * 0.5, 100.0);
        cout<<"Closed "<<numApps<<" apps. Battery partially restored."<<endl;
    }
    void charge(const double amount){
        this->batteryLevel=min(this->batteryLevel+amount,100.00);
    }
    void printSpec(){
        cout<<"Brand "<<this->brand<<endl;
        cout<<"ScreenSize "<<this->screenSize<<endl;
        cout<<"Processor "<<this->processor<<endl;
        cout<<"RAM "<<this->ram<<endl;
        cout<<"Storage "<<this->storage<<endl;
        cout<<"Battery Level "<<this->batteryLevel<<endl;
        cout<<endl;
    }
};
int main(){
    Laptop l1("Asus",15.6,"Intel i3",4,1024);
    l1.printSpec();
    l1.charge(8);
    l1.printSpec();
    l1.openApps(5);
    l1.printSpec();
    l1.powerOn();
    l1.openApps(5);
    l1.printSpec();
    l1.closeApps(10);
    l1.printSpec();
    return 0;
}