 
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

# S - Single Responsibility Principle

One class should have only one responsibility.

Bad:
One class doing:
- login
- email
- report generation

Good:
Separate classes for each work.

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