// Ambiguity and dublication
// #include<bits/stdc++.h>
// using namespace std;
// class A{
//     public:
//     int a;
// };
// class B:public A{
//     public:
//     int b;
// };
// class C:public A{
//     public:
//     int c;
// };
// class D:public B,public C{
//     public:
//     int d;
// };
// int main(){
//     D d;
//     d.a=5;
//     cout<<d.a<<endl;  
//     return 0;
// }

// Using virtual keyword to make a single shared instance of common base class members
#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    int a;
};
class B:public virtual A{
    public:
    int b;
};
class C:public virtual A{
    public:
    int c;
};
class D:public B,public C{
    public:
    int d;
};
int main(){
    D d;
    d.a=5;
    cout<<d.a<<endl;  
    return 0;
}