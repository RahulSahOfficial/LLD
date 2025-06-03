#include<bits/stdc++.h>
using namespace std;
class ICharacter{
    public:
    virtual string getAbilities()=0;
};
class Mario:public ICharacter{
    public:
    string getAbilities() override{
        return "🧍‍♂️";
    }
};
class IDecorator:public ICharacter{
    public:
    ICharacter *ch;
    IDecorator(ICharacter *c){
        ch=c;
    }
};
class HeightUpDec:public IDecorator{
    public:
    HeightUpDec(ICharacter *ch):IDecorator(ch){}
    string getAbilities(){
        return ch->getAbilities()+" 🍄";
    }
};
class GunPowerDec:public IDecorator{
    public:
    GunPowerDec(ICharacter *ch):IDecorator(ch){}
    string getAbilities(){
        return ch->getAbilities()+" 🌸";
    }
};
class StarPowerDec:public IDecorator{
    public:
    StarPowerDec(ICharacter *ch):IDecorator(ch){}
    string getAbilities(){
        return ch->getAbilities()+" ⭐";
    }
};
int main(){
    cout<<"Simple Mario"<<endl;
    ICharacter *mario=new Mario();
    cout<<mario->getAbilities()<<endl;

    cout<<"Got Mushroom"<<endl;
    mario=new HeightUpDec(mario);
    cout<<mario->getAbilities()<<endl;

    cout<<"Got Flower"<<endl;
    mario=new GunPowerDec(mario);
    cout<<mario->getAbilities()<<endl;

    cout<<"Got Star"<<endl;
    mario=new StarPowerDec(mario);
    cout<<mario->getAbilities()<<endl;
    return 0;
}