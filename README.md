# System Design [Rohit Negi]

---
| Day | Topic | Completed
|-|-|-|
| 1 | Introduction | ✅
| 2 | Oops - Abstraction & Encapsulation | ✅
| 3 | Oops - (Inheritance & Polymorphism) | ✅
| 4 | UML Diagrams (Class & Sequence Diagram) | ✅
| 5 | SOLID Principles (SRP & OCP & LSP)| ✅
| 6 | SOLID Principles (LSP Guideline & ISP and DIP) | WIP
---

## Records

### Day 1 : Introduction
- LLD Theory 
- Pillars of LLD
- Difference bw LLD & HLD
- History of Progamming

### Day 2 : Oops - Abstraction & Encapsulation
- Oops
- Abstraction
- Polymorphism

### Day 3 : Oops - (Inheritance & Polymorphism) 
- Inheritance Car (Manual & Electric)
- Polymorphism
    - Static
    - Dynamic

### Day 4 : UML Diagrams (Class & Sequence Diagram)
- Class Diagram 
    - Object Association
- Homework (Manaual & Electric Car Class Diagram)
- Sequence Diagram
    - User withdrawing money from ATM.
    - Objects : `User`,`ATM`,`Transaction`,`Account`,`CashDispenser`
### Day 5 : SOLID Principles
- Problems without SOLID
- Single Responsibility Principle (SRP)
    - Example of **Shopping Cart System**
    - Class : `Product`,`ShoppingCart`,`CartInvoicePrinter`,`CartDBStorage`
- Open Close Principle (OCP)
    - Example of extending Database to 3 different saving method
    - Made DBPersistence abstract class and inherited it in class `SaveToSQLDB`,`SaveToMongoDB`,`SaveToFile`
- Liskov Substitution Principle (LSP)
    - Example of Different Accounts types without tightly bound and breaking OCP
    - Created different class such that we only increase the feature as we inherit it and not restrict it
    - Made Two abstract class `NonWithdrawableAccount` and  `WithdrawableAccount` and made 3 classes of `SavingAccount`, `CurrentAccount`, `FDAccount`accordingly.
### Day 6 : SOLID Principles (Continued)
- LSP Guidelines
    - Signature Rule
        - **Parameter Type Rule.**
        We can pass **same or broader** class object in derived methods parameters
        Made `Parent` and `Child` classes and passed same type of argument in overriding fn as `C++` dont supports parameter covarience.
        - **Return Type Rule.**
        We can return **same or narrower** class object in derived methods.
        Made `Parent` and `Child` classes and return `A` object in Parent method and `B` object in Child method,Class `B` is child of `A`.
        - **Exception Rule.**
        We can throw **same or narrower** class exception in derived method.
        Made `Parent` and `Child` classes and thrown `runtime_error` in `Parent` class `withdraw` method and thrown `LowBalance` exception in `Child` class `withdraw` method and handled the exception.
        `LowBalance` Exception is derived from `runtime_error` Exception class.
    - Property Rule
        - **Class Invariant **
        Some condition or properties must always hold true for an object.
        Made `Account` and `CheatAccount` and invarinat that `balance` cannot go below 0, but child class dont maintain this property.
        - **History Constraint**
        Derived class mush not change the expected behaviour or history of base class
        Made `Account` and `CheatAccount` and `withdraw` had history of reducing the `balance` but derived class is increaing the `balance`.
    - Method Rule
        - **Pre Condition**
        Derived class should not strengthen precondition of a method.
        Made `User` and `Admin` and `setPassword` had precondition that passowrd length should be >=8 and in derived class `Admin` `setPassword` accepts >=6 hence weakening the precondition.
        - Post Condition
        Derived class must not weaken the post condition of base class method.
        >Somewhat vague talked about post condition but given example whre the derived class is fulfilling the promise and also doing something extra
        Like `brake` in `Car` class reducing `speed` and `brake` in `ElectricCar` reducing the `speed` and also increasing the `batteryPercentage`.
---

