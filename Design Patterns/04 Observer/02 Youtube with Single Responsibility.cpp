#include<bits/stdc++.h>
using namespace std;
class ISubscriber{
    public:
    virtual void update()=0;
};
class IChannel{
    vector<ISubscriber *> subs;
    public:
    void addSubscriber(ISubscriber *newSubscriber){
        subs.push_back(newSubscriber);
    } 
    void removeSubscriber(ISubscriber *unSubscriber){
        vector<ISubscriber *> temp;
        for(auto each:subs){
            if(each!=unSubscriber)
                temp.push_back(each);
        }
        subs=temp;
    }
    void notify(){
        for(auto each:subs)
            each->update();
    } 
};

class Channel:public IChannel{
    string name;
    vector<string> videos;
    public:
    Channel(string name){
        this->name=name;
    }
    
    void addVideo(string title){
        cout<<"\nNew video uploaded : "<<title<<endl;
        videos.push_back(title);
        notify();
    }
    string getLatestVideo(){
        return videos.back();
    }
};
class Subscriber:public ISubscriber{
    string name;
    Channel *channel;
    public:
    Subscriber(string name,Channel *channel){
        this->name=name;
        this->channel=channel;
    }
    void update() override{
        cout<<"\tSubscriber "<<name<<" notified about "<<channel->getLatestVideo()<<endl;
    }
};
int main(){
    Subscriber *s1,*s2,*s3;
    Channel *coderArmy=new Channel("Coder Army");
    s1=new Subscriber("Sah",coderArmy);
    s2=new Subscriber("Stark",coderArmy);
    s3=new Subscriber("Dwivedi",coderArmy);
    //Adding Subscription
    coderArmy->addSubscriber(s1);
    coderArmy->addSubscriber(s2);
    
    coderArmy->addVideo("System Design Day 10");
    coderArmy->addVideo("System Design Day 11");
    coderArmy->addSubscriber(s3);
    coderArmy->addVideo("System Design Day 12");
    coderArmy->removeSubscriber(s2);
    coderArmy->addVideo("System Design Day 13");
    return 0;
}