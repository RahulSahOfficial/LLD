#include<bits/stdc++.h>
using namespace std;
class ICommand{
    public:
    virtual void execute()=0;
    virtual void undo()=0;
    virtual bool isOn()=0;
};
class RemoteControl{
    int btnCnt;
    vector<ICommand *> commands;
    public:
    RemoteControl(int btnCnt){
        this->btnCnt=btnCnt;
        commands.resize(btnCnt,nullptr);
    }
    void setCommand(int idx,ICommand *newCommand){
        commands[idx]=newCommand;
    }
    void pressButton(int idx){
        if(commands[idx]->isOn())
            commands[idx]->undo();
        else
            commands[idx]->execute();
    }
};
class Light{
    string name;
    public:
    bool isOn;
    Light(string name){
        isOn=false;
        this->name=name;
    }
    void on(){
        isOn=true;
        cout<<name<<" Light Turned On!"<<endl;
    }
    void off(){
        isOn=false;
        cout<<name<<" Light Turned Off!"<<endl;
    }
};
class Fan{
    string name;
    public:
    bool isOn;
    Fan(string name){
        isOn=false;
        this->name=name;
    }
    void on(){
        isOn=true;
        cout<<name<<" Fan Turned On!"<<endl;
    }
    void off(){
        isOn=false;
        cout<<name<<" Fan Turned Off!"<<endl;
    }
};
class LightCommand:public ICommand{
    Light *light;
    public:
    LightCommand(Light *light){
        this->light=light;
    }
    bool isOn() override{
        return light->isOn;
    }
    void execute() override{
        light->on();
    }
    void undo() override{
        light->off();
    }
};
class FanCommand:public ICommand{
    Fan *fan;
    public:
    FanCommand(Fan *fan){
        this->fan=fan;
    }
    bool isOn() override{
        return fan->isOn;
    }
    void execute() override{
        fan->on();
    }
    void undo() override{
        fan->off();
    }
};
int main(){
    RemoteControl *remote=new RemoteControl(5);
    // Appliances 
    Light *l1=new Light("Bedroom 1");
    Light *l2=new Light("Hall");
    Fan *f1=new Fan("Bedroom 1");
    Fan *f2=new Fan("Hall");
    //Commands
    LightCommand *light1Command=new LightCommand(l1); 
    LightCommand *light2Command=new LightCommand(l2);
    FanCommand *fan1Command=new FanCommand(f1); 
    FanCommand *fan2Command=new FanCommand(f2); 
    //Setting Commands to remote
    remote->setCommand(0,light1Command);
    remote->setCommand(1,light2Command);
    remote->setCommand(2,fan1Command);
    remote->setCommand(3,fan2Command);
    //Pressing Remote Btns
    remote->pressButton(0);
    remote->pressButton(1);
    remote->pressButton(1);
    remote->pressButton(2);
    remote->pressButton(3);
    remote->pressButton(0);

    delete(light1Command);
    delete(light2Command);
    delete(fan1Command);
    delete(fan2Command);
    delete(l1);
    delete(l2);
    delete(f1);
    delete(f2);
    delete(remote);
    return 0;
}