 
# OOP Notes Day 1

# 1. What is OOP?

OOP = Object Oriented Programming

It is used to represent real-world objects in programming.

Example:
- Car
- Bank
- Player
- Animal

---

# 2. Class

Class is a blueprint/template.

Example:

class Car {
};

It defines:
- properties
- behaviors

---

# 3. Object

Object is an instance of a class.

Example:

Car bmw;

bmw is an object.

---

# 4. Encapsulation

Encapsulation means:
binding data and methods together and protecting data from direct access.

Example:

class Bank {
private:
    int balance = 1000;

public:
    void showBalance() {
        cout << balance;
    }
};

balance cannot be directly accessed.

---

# 5. Abstraction

Abstraction means:
show important details and hide internal implementation.

Example:
In a car:
- steering
- brake
- accelerator

are visible.

But internal engine working is hidden.

---

# 6. Inheritance

Inheritance means:
one class acquires properties and behavior of another class.

Example:

class Vehicle {
};

class Car : public Vehicle {
};

Car inherits Vehicle properties.

---

# 7. Polymorphism

Polymorphism means:
same function with different behavior.

Example:

class Animal {
public:
    virtual void sound() {
        cout << "Animal";
    }
};

class Dog : public Animal {
public:
    void sound() {
        cout << "Bhow";
    }
};

class Cat : public Animal {
public:
    void sound() {
        cout << "Meow";
    }
};

Same function:
sound()

Different behavior:
- Dog -> Bhow
- Cat -> Meow

---

# SOLID Principles Day 2

# S - Single Responsibility Principle (SRP)

Single Responsibility Principle means:

A class should have only one responsibility or one reason to change.

Bad Design:
One class handles:
- login
- email
- report generation

If email system changes,
whole class may need modification.

This increases complexity.

---

# Bad Example

class Employee {
public:

    void calculateSalary() {
        cout << "Calculating Salary";
    }

    void saveToDatabase() {
        cout << "Saving to DB";
    }

    void generateReport() {
        cout << "Generating Report";
    }
};

# Good Example

class SalaryCalculator {
public:

    void calculateSalary() {
        cout << "Calculating Salary";
    }
};

class EmployeeDatabase {
public:

    void saveToDatabase() {
        cout << "Saving to DB";
    }
};

class ReportGenerator {
public:

    void generateReport() {
        cout << "Generating Report";
    }
};

---

# O - Open Closed Principle

Software should be:
- open for extension
- closed for modification

New features should be added without changing old code.

---

# L - Liskov Substitution Principle

Child class should properly replace parent class.

Bad Example:
Penguin inheriting Bird with fly() method.

Penguin cannot fly.

---

# I - Interface Segregation Principle

Do not force classes to implement unnecessary methods.

Example:
Software engineer should not implement cook() method.

---

# D - Dependency Inversion Principle

Depend on abstraction, not concrete classes.

Use interfaces instead of directly depending on:
- MySQL
- MongoDB
etc.

---

# SOLID Principles Day 6

# O - Open Closed Principle (OCP)

Open Closed Principle means:

Software should be:
- open for extension
- closed for modification

Meaning:
new features should be added without changing existing code.

---

# Bad Design

```cpp
class Payment {
public:

    void pay(string type) {

        if(type == "UPI") {
            cout << "UPI Payment";
        }

        else if(type == "Card") {
            cout << "Card Payment";
        }
    }
};
````

Problem:
If new payment method comes like:

* NetBanking
* Crypto
* Wallet

then existing class must be modified again and again.

This increases:

* bugs
* complexity
* testing effort

This violates OCP.

---

# Good Design

```cpp
class Payment {
public:
    virtual void pay() = 0;
};

class UPI : public Payment {
public:

    void pay() {
        cout << "UPI Payment";
    }
};

class Card : public Payment {
public:

    void pay() {
        cout << "Card Payment";
    }
};

class NetBanking : public Payment {
public:

    void pay() {
        cout << "NetBanking Payment";
    }
};
```

Now:
new payment methods can be added by creating new classes.

Existing code does not need modification.

This follows OCP.

---

# Advantages of OCP

* Easy extension
* Less bugs
* Better scalability
* Better maintainability
* Safer updates

---

# Real Life Example

Mobile charger socket:

New chargers and devices can be connected without changing wall socket.

Same idea:
extend functionality without modifying old system.

```

---

````md id="solid9xp"
# SOLID Principles Day 7

# L - Liskov Substitution Principle (LSP)

Liskov Substitution Principle means:

Child class should properly replace parent class without breaking program logic.

If child class cannot behave like parent class,
then inheritance design is wrong.

---

# Bad Example

```cpp
class Bird {
public:

    void fly() {
        cout << "Flying";
    }
};

class Penguin : public Bird {
};
````

Problem:

Penguin cannot fly,
but because of inheritance:

```cpp
Penguin p;
p.fly();
```

becomes possible.

This is wrong design.

This violates LSP.

---

# Good Example

```cpp
class Bird {
};

class FlyingBird : public Bird {
public:

    void fly() {
        cout << "Flying";
    }
};

class Sparrow : public FlyingBird {
};

class Penguin : public Bird {
};
```

Now:

* Sparrow can fly
* Penguin cannot fly

Proper inheritance is maintained.

---

# Main Idea of LSP

Child class should behave correctly when used in place of parent class.

---

# Real Life Example

Vehicle:

* Car
* Bike

can inherit Vehicle.

But:

* Fan
* Chair

cannot inherit Vehicle.

Inheritance should represent proper relationship.

---

# I - Interface Segregation Principle (ISP)

Interface Segregation Principle means:

Do not force classes to implement unnecessary methods.

Small and specific interfaces are better.

---

# Bad Example

```cpp
class Worker {
public:

    virtual void code() = 0;
    virtual void cook() = 0;
};
```

Now:

```cpp
class SoftwareEngineer : public Worker
```

must implement:

```cpp
cook()
```

even though software engineer does not cook.

This is unnecessary.

This violates ISP.

---

# Good Example

```cpp
class Coder {
public:

    virtual void code() = 0;
};

class Chef {
public:

    virtual void cook() = 0;
};
```

Now:

```cpp
class SoftwareEngineer : public Coder {
public:

    void code() {
        cout << "Writing Code";
    }
};
```

And:

```cpp
class Cook : public Chef {
public:

    void cook() {
        cout << "Cooking Food";
    }
};
```

Now:

* SoftwareEngineer only codes
* Cook only cooks

No unnecessary methods are forced.

---

# Main Idea of ISP

Classes should implement only methods they actually need.

---

# Real Life Example

Chef should not be forced to write code.

Software engineer should not be forced to cook.

---

# D - Dependency Inversion Principle (DIP)

Dependency Inversion Principle means:

Depend on abstraction,
not on concrete classes.

High level modules should not directly depend on low level implementations.

---

# Bad Example

```cpp
class MySQL {
public:

    void connect() {
        cout << "MySQL Connected";
    }
};

class App {
public:

    MySQL db;

    void start() {
        db.connect();
    }
};
```

Problem:

If database changes to MongoDB,
App class must also change.

This creates tight coupling.

---

# Good Example

```cpp
class Database {
public:

    virtual void connect() = 0;
};

class MySQL : public Database {
public:

    void connect() {
        cout << "MySQL Connected";
    }
};

class MongoDB : public Database {
public:

    void connect() {
        cout << "MongoDB Connected";
    }
};

class App {
public:

    Database* db;

    App(Database* db) {
        this->db = db;
    }

    void start() {
        db->connect();
    }
};
```

Now:

* App depends on Database abstraction
* MySQL or MongoDB can be used easily
* App class does not need modification

This follows DIP.

---

# Main Idea of DIP

Depend on interfaces/abstractions,
not directly on concrete implementations.

---

# Real Life Example

Phone uses USB interface.

Phone does not depend on one specific charger brand.

Different chargers can work using same interface.

---

# Easy Summary

SRP:
One class → One responsibility

OCP:
Open for extension,
closed for modification

LSP:
Child should properly behave like parent

ISP:
Do not force unnecessary methods

DIP:
Depend on abstraction,
not concrete implementation

```