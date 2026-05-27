 
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

````md id="ocp8xp"
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