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
class GarlicBread{
    public:
    virtual void prepare()=0;
};
class SimpleGarlicBread:public GarlicBread{
    public:
    void prepare() override{
        cout<<"🧈 Preparing Simple GarlicBread"<<endl;
    }
};
class StandardGarlicBread:public GarlicBread{
    public:
    void prepare() override{
        cout<<"🧈 Preparing Standard GarlicBread"<<endl;
    }
};
class PremiumGarlicBread:public GarlicBread{
    public:
    void prepare() override{
        cout<<"🧈 Preparing Premium GarlicBread"<<endl;
    }
};
class SimpleWheatGarlicBread:public GarlicBread{
    public:
    void prepare() override{
        cout<<"🧈 Preparing Simple Wheat GarlicBread"<<endl;
    }
};
class StandardWheatGarlicBread:public GarlicBread{
    public:
    void prepare() override{
        cout<<"🧈 Preparing Standard Wheat GarlicBread"<<endl;
    }
};
class Factory{
    public:
    virtual Burger* createBurger(string)=0;
    virtual GarlicBread* createGarlicBread(string)=0;
};
class SinghBurger:public Factory{
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
    GarlicBread* createGarlicBread(const string type) override{
        if(type=="Simple")
            return new SimpleGarlicBread();
        if(type=="Standard")
            return new StandardGarlicBread();
        if(type=="Premium")
            return new PremiumGarlicBread();
        return NULL;
    }
};
class KingBurger:public Factory{
    public:
    Burger* createBurger(const string type) override{
        if(type=="Simple")
            return new SimpleWheatBurger();
        if(type=="Standard")
            return new StandardWheatBurger();
        return NULL;
    }
    GarlicBread* createGarlicBread(const string type) override{
        if(type=="Simple")
            return new SimpleWheatGarlicBread();
        if(type=="Standard")
            return new StandardWheatGarlicBread();
        return NULL;
    }
};
int main(){
    Factory *singhFactory=new SinghBurger();
    Factory *kingFactory=new KingBurger();
    Burger *b1=singhFactory->createBurger("Simple");
    b1->prepare();
    Burger *b2=kingFactory->createBurger("Standard");
    b2->prepare();
    GarlicBread *gb1=kingFactory->createGarlicBread("Standard");
    gb1->prepare();
    GarlicBread *gb2=singhFactory->createGarlicBread("Premium");
    gb2->prepare();
    return 0;
}