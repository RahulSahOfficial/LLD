// Diamond Problem

#include <iostream>
using namespace std;

// Base Class 1
class A {
public:
    void display() {
        cout << "Display of A" << endl;
    }
};

// Base Class 2 without Virtual Inheritance
class B : public A {
    // No display() method here
};

// Base Class 3 without Virtual Inheritance
class C : public A {
    // No display() method here
};

// Derived Class
class D : public B, public C {
    // No display() method here
};

int main() {
    D obj;
    obj.display();  // This will call A's display() method
    return 0;
}



// #include <iostream>
// using namespace std;

// // Base Class 1
// class A {
// public:
//     void display() {
//         cout << "Display of A" << endl;
//     }
// };

// // Base Class 2 with Virtual Inheritance
// class B : virtual public A {
//     // No display() method here
// };

// // Base Class 3 with Virtual Inheritance
// class C : virtual public A {
//     // No display() method here
// };

// // Derived Class
// class D : public B, public C {
//     // No display() method here
// };

// int main() {
//     D obj;
//     obj.display();  // This will call A's display() method
//     return 0;
// }
