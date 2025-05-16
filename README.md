# System Design [Rohit Negi]

---
| Day | Topic | Completed
|-|-|-|
| 1 | Introduction | ✅
| 2 | Oops - Abstraction & Encapsulation | ✅
| 3 | Oops - (Inheritance & Polymorphism) | ✅
| 4 | UML Diagrams (Class & Sequence Diagram) | ✅
| 5 | SOLID Principles | ✅
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
    - Made Two abstract class `NonWithdrawableAccount` and  `WithdrawableAccount` and made 3 classes of `SavingAccount`, `CurrentAccount`, `FDAccount`accordingly
---

