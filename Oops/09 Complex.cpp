#include<bits/stdc++.h>
using namespace std;
class Complex{
    int x;
    int y;
    public:
    Complex(const int x,const int y):x(x),y(y){};
    Complex operator + (Complex c){
        return Complex(this->x+c.x,this->y+c.y);
    }
    // Complex operator - (){
    //     x=-x;
    //     y=-y;
    //     return *this;
    // }
    void operator - (){
        x=-x;
        y=-y;
    }
    void display(){
        cout<<this->x<<" "<<this->y<<endl;
    }
};
int main(){
    Complex c1(2,5),c2(3,5);
    c1.display();
    c2.display();
    Complex c3=c1+c2;
    c3.display();
    -c3;
    c3.display();
    return 0;
}