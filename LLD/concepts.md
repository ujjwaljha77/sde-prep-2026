 
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