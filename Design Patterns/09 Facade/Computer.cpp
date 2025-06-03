#include<bits/stdc++.h>
using namespace std;
class PowerSupply{
    public:
    void supplyPower(){
        cout<<"Power Supply Started."<<endl;
    }
};
class CPU{
    public:
    void initialize(){
        cout<<"CPU Initialized"<<endl;
    }
};
class Memory{
    public:
    void selfTest(){
        cout<<"Memory Working"<<endl;
    }
};
class BIOS{
    public:
    void boot(CPU &cpu,Memory &mem){
        cpu.initialize();
        mem.selfTest();
        cout<<"BIOS Booted"<<endl;
    }
};
class HardDisk{
    public:
    void spinUp(){
        cout<<"Hard Drive started"<<endl;
    }
};
class OS{
    public:
    void load(){
        cout<<"OS Loaded"<<endl;
    }
};
// Facade
class ComputerFacade{
    PowerSupply ps;
    CPU cpu;
    Memory mem;
    BIOS bios;
    HardDisk hd;
    OS os;
    public:
    void startComputer(){
        cout<<"Computer Starting ..."<<endl;
        ps.supplyPower();
        bios.boot(cpu,mem);
        hd.spinUp();
        os.load();
        cout<<"Computer Started"<<endl;
    }
};
int main(){
    ComputerFacade comp;
    comp.startComputer();
    return 0;
}