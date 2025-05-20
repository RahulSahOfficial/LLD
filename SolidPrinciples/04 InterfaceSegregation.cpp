#include<bits/stdc++.h>
using namespace std;
class Shape2d{
    public:
    virtual double area()=0;
};
class Shape3d{
    public:
    virtual double area()=0;
    virtual double volume()=0;
};
class Square:public Shape2d{
    double side;
    public:
    Square(double side):side(side){};
    double area() override{
        return side*side;
    }
};
class Rectange:public Shape2d{
    double length;
    double breadth;
    public:
    Rectange(double l,double b):length(l),breadth(b){};
    double area() override{
        return length*breadth;
    }
};
class Cube:public Shape3d{
    double side;
    public:
    Cube(double side):side(side){};
    double area() override{
        return side*side;
    }
    double volume() override{
        return side*side*side;
    }
};
int main(){
    Shape2d *sq=new Square(2);
    cout<<sq->area()<<endl;
    Shape2d *rect=new Rectange(2,4);
    cout<<rect->area()<<endl;
    Shape3d *cu=new Cube(5);
    cout<<cu->area()<<endl;
    cout<<cu->volume()<<endl;
    return 0;
}