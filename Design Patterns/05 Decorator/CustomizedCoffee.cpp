#include<bits/stdc++.h>
using namespace std;
class Coffee{
    public:
    virtual string getCoffee()=0;
    virtual int getCost()=0;
};
class Espresso:public Coffee{
    public:
    string getCoffee() override{
        return "Espresso";
    }
    int getCost() override{
        return 49;
    }
};
class Latte:public Coffee{
    public:
    string getCoffee() override{
        return "Latte";
    }
    int getCost() override{
        return 79;
    }
};
class CustomizationDecorator:public Coffee{
    public:
    Coffee *cof;
    CustomizationDecorator(Coffee *cof){
        this->cof=cof;
    }
};
class SugarDecorator:public CustomizationDecorator{
    public:
    SugarDecorator(Coffee *cof):CustomizationDecorator(cof){}
    string getCoffee() override{
        return cof->getCoffee()+" with Sugar";
    }
    int getCost() override{
        return cof->getCost()+5;
    }
};
class CreamDecorator:public CustomizationDecorator{
    public:
    CreamDecorator(Coffee *cof):CustomizationDecorator(cof){}
    string getCoffee() override{
        return cof->getCoffee()+" with Cream";
    }
    int getCost() override{
        return cof->getCost()+12;
    }
};
int main(){
    cout<<"Just Espresso"<<endl;
    Coffee *cof=new Espresso();
    cout<<cof->getCoffee()<<" : "<<cof->getCost()<<endl;

    cout<<"Adding Sugar"<<endl;
    cof=new SugarDecorator(cof);
    cout<<cof->getCoffee()<<" : "<<cof->getCost()<<endl;
    
    cout<<"Adding Cream"<<endl;
    cof=new CreamDecorator(cof);
    cout<<cof->getCoffee()<<" : "<<cof->getCost()<<endl;

    cout<<"Just Latte"<<endl;
    Coffee *cof2=new Latte();
    cout<<cof2->getCoffee()<<" : "<<cof2->getCost()<<endl;

    cout<<"Adding Cream"<<endl;
    cof2=new CreamDecorator(cof2);
    cout<<cof2->getCoffee()<<" : "<<cof2->getCost()<<endl;

    return 0;
}