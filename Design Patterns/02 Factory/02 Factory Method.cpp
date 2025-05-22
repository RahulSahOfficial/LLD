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
class SimpleWheatBurger:public Burger{
    public:
    void prepare() override{
        cout<<"🍔 Preparing Simple Wheat Burger"<<endl;
    }
};
class StandardWheatBurger:public Burger{
    public:
    void prepare() override{
        cout<<"🍔 Preparing Standard Wheat Burger"<<endl;
    }
};
class BurgerFactory{
    public:
    virtual Burger* createBurger(string)=0;
};
class SinghBurger:public BurgerFactory{
    public:
    Burger* createBurger(const string type) override{
        if(type=="Simple")
            return new SimpleBurger();
        if(type=="Standard")
            return new StandardBurger();
        if(type=="Premium")
            return new PremiumBurger();
        return NULL;
    }
};
class KingBurger:public BurgerFactory{
    public:
    Burger* createBurger(const string type) override{
        if(type=="Simple")
            return new SimpleWheatBurger();
        if(type=="Standard")
            return new StandardWheatBurger();
        return NULL;
    }
};
int main(){
    BurgerFactory *singhFactory=new SinghBurger();
    BurgerFactory *kingFactory=new KingBurger();
    Burger *b1=singhFactory->createBurger("Simple");
    b1->prepare();
    Burger *b2=kingFactory->createBurger("Standard");
    b2->prepare();
    return 0;
}