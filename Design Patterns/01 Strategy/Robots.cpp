#include<bits/stdc++.h>
using namespace std;
// Strategy Interface for Talking 
class Talkable{
    public:
    virtual void talk()=0;
};
// Strategy Interface for Walking
class Walkable{
    public:
    virtual void walk()=0;
};
// Strategy Interface for Flying 
class Flyable{
    public:
    virtual void fly()=0;
};
// Concrete Strategies 
class NormalTalk:public Talkable{
    public:
    void talk() override{
        cout<<"Normal Talk"<<endl;
    }
};
class NoTalk:public Talkable{
    public:
    void talk() override{
        cout<<"Cannot Talk"<<endl;
    }
};
class NormalWalk:public Walkable{
    public:
    void walk() override{
        cout<<"Normal Walk"<<endl;
    }
};
class NoWalk:public Walkable{
    public:
    void walk() override{
        cout<<"Cannot Walk"<<endl;
    }
};
class WingFly:public Flyable{
    public:
    void fly() override{
        cout<<"Wing Fly"<<endl;
    }
};
class JetFly:public Flyable{
    public:
    void fly() override{
        cout<<"Jet Fly"<<endl;
    }
};
class NoFly:public Flyable{
    public:
    void fly() override{
        cout<<"No Fly"<<endl;
    }
};
// Dubm Class / Client
class Robot{
    Talkable *talkBehaviour;
    Walkable *walkBehaviour;
    Flyable *flyBehaviour;
    public:
    Robot(Talkable *t,Walkable *w,Flyable *f){
        this->talkBehaviour=t;
        this->walkBehaviour=w;
        this->flyBehaviour=f;
    }
    virtual void projection()=0;
    void talk(){
        talkBehaviour->talk();
    }
    void walk(){
        walkBehaviour->walk();
    }
    void fly(){
        flyBehaviour->fly();
    }
};
class CompanionRobot:public Robot{
    public:
    CompanionRobot(Talkable *t,Walkable *w,Flyable *f):Robot(t,w,f){};
    void projection() override{
        cout<<"Looks like Companion Robot"<<endl;
    }
};
class SparrowRobot:public Robot{
    public:
    SparrowRobot(Talkable *t,Walkable *w,Flyable *f):Robot(t,w,f){};
    void projection() override{
        cout<<"Looks like Sparrow Robot"<<endl;
    }
};
int main(){
    Robot *cr=new CompanionRobot(
        new NormalTalk(),
        new NormalWalk(),
        new NoFly()
    );
    cr->projection();
    cr->fly();
    cr->walk();
    cr->talk();
    
    Robot *sr=new SparrowRobot(
        new NormalTalk(),
        new NormalWalk(),
        new WingFly()
    );
    sr->projection();
    sr->fly();
    sr->walk();
    sr->talk();
    return 0;
}