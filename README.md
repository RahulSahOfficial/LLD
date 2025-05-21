# System Design [Rohit Negi]

---
| Day | Topic | Completed
|-|-|-|
| 1 | Introduction | ✅
| 2 | Oops - Abstraction & Encapsulation | ✅
| 3 | Oops - (Inheritance & Polymorphism) | ✅
| 4 | UML Diagrams (Class & Sequence Diagram) | ✅
| 5 | SOLID Principles (SRP & OCP & LSP)| ✅
| 6 | SOLID Principles (LSP Guideline & ISP and DIP) | ✅
| 7 | Google Doc (Project) | ✅
| 8 | Strategy Design Pattern | ✅
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
- **LSP Guidelines**
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
        - **Class Invariant**  
        Some condition or properties must always hold true for an object.
        Made `Account` and `CheatAccount` and invarinat that `balance` cannot go below 0, but child class dont maintain this property.
        - **History Constraint**  
        Derived class mush not change the expected behaviour or history of base class
        Made `Account` and `CheatAccount` and `withdraw` had history of reducing the `balance` but derived class is increaing the `balance`.
    - Method Rule
        - **Pre Condition**  
        Derived class should not strengthen precondition of a method.
        Made `User` and `Admin` and `setPassword` had precondition that `password` length should be >=8 and in derived class `Admin` `setPassword` accepts >=6 hence weakening the precondition.
        - **Post Condition**  
        Derived class must not weaken the post condition of base class method.
        >Somewhat vague talked about post condition but given example whre the derived class is fulfilling the promise and also doing something extra
        Like `brake` in `Car` class reducing `speed` and `brake` in `ElectricCar` reducing the `speed` and also increasing the `batteryPercentage`.
- **Interface Segregation Principle**  
    - Many client specific interface are better than one general purpose interface
    - Made `Shape2d` and `Shape3d` so we dont force client to implement `volume` of a 2d shape
- **Dependency Inversion Principle**  
    - HL Module should not depend on LL Module.
    - Made `UserService`,`Persistence`,`SQLDB` and `MongoDB` where Persistence acts as abstraction between business logic and external detailed operations.

### Day 7 : Google Doc (Project)
-  **Bad Design**
    - Made **single class** DocumentEditor and done everything in the same class
- **Better Design**
    - Made **8 class** `DocumentElement`, `TextElement`, `ImageElement`, `NewLineElement`, `Persistence`, `SaveToFile`, `Document`, `DocumentEditor` and distributed the individual tasks.
- **Best Design**
    - Seperated render functionality and distributed tasks of editor,renderer and persistence so that client directly access it.
    - Made **9 class**  `DocumentElement`, `TextElement`, `ImageElement`, `NewLineElement`, `Persistence`, `SaveToFile`, `Document`, `DocumentEditor`, `DocumentRenderer`.
### Day 8 : Strategy Design Pattern
- Defines a family of algorithm, put them into seperate classes so that they can be changed at run time.
- Prefer **Composition** over **Inheritance**.
- Made a Client class `Robot` and 3 different strategies `Walkable`, `Talkable`, `Flyable` and 7 different concrete strategies `NormalWalk`, `NoWalk`, `NormalTalk`, N`oTalk`, `NormalFly`, `JetFly`, `NoFly` and created objects of strategies as per our requirements and passed while creating object of Robot.
Made two derived classes of Robot called `CompanionRobot` and `SparrowRobot` which have own implementation of `projection` method.
---

