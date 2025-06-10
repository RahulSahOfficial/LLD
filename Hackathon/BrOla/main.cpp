#include<bits/stdc++.h>
#include "./BrOla/BrOla.h"
using namespace std;
int main(){
    //For random OTP genertion
    srand(time(0));
    BrOla *app=new BrOla();
    try{
        app->run1();
        // app->run2();
        // app->run3();
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
    return 0;
}