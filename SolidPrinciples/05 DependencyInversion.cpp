#include<bits/stdc++.h>
using namespace std;
class Persistence{
    public:
    virtual void save()=0;
};
class SqlDB:public Persistence{
    public:
    void save() override{
        cout<<"Saved to SQL DB"<<endl;
    }
};
class MongoDB:public Persistence{
    public:
    void save() override{
        cout<<"Saved to Mongo DB"<<endl;
    }
};
class UserService{
    Persistence *p;
    public:
    UserService(Persistence *db){
        p=db;
    }
    void storeData(){
        p->save();
    }
};
int main(){
    Persistence *p1=new SqlDB();
    Persistence *p2=new MongoDB();
    UserService *us1=new UserService(p1);
    us1->storeData();
    UserService *us2=new UserService(p2);
    us2->storeData();
    return 0;
}