#include<bits/stdc++.h>
using namespace std;
class Burger{
    public:
    virtual void prepare()=0;
};
class SimpleBurger:public Burger{
    public:
    void prepare() override{
        cout<<"🍔 Preparing Simple Burger"<<endl;
    }
};
class StandardBurger:public Burger{
    public:
    void prepare() override{
        cout<<"🍔 Preparing Standard Burger"<<endl;
    }
};
class PremiumBurger:public Burger{
    public:
    void prepare() override{
        cout<<"🍔 Preparing Premium Burger"<<endl;
    }
};
class BurgerFactory{
    public:
    Burger* getBurger(const string type){
        if(type=="Simple")
            return new SimpleBurger();
        if(type=="Standard")
            return new StandardBurger();
        if(type=="Premium")
            return new PremiumBurger();
        return NULL;
    }
};
int main(){
    BurgerFactory *factory=new BurgerFactory();
    Burger *b1=factory->getBurger("Simple");
    b1->prepare();
    Burger *b2=factory->getBurger("Premium");
    b2->prepare();
    return 0;
}