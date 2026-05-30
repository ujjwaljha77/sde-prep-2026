# OOPS

# What is OOP?

OOP = Object Oriented Programming

It is used to represent real-world objects in programming.

Examples:
- Car
- Bank
- Player
- Animal

---

# Class

Class is a blueprint/template.

Example:

```cpp
class Car {
};
```

It defines:
- properties
- behaviors

---

# Object

Object is an instance of a class.

Example:

```cpp
Car bmw;
```

bmw is an object.

---

# Encapsulation

Encapsulation means:
binding data and methods together and protecting data from direct access.

Example:

```cpp
class Bank {

private:
    int balance = 1000;

public:

    void showBalance() {
        cout << balance;
    }
};
```

balance cannot be directly accessed.

---

# Abstraction

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

# Inheritance

Inheritance means:
one class acquires properties and behavior of another class.

Example:

```cpp
class Vehicle {
};

class Car : public Vehicle {
};
```

Car inherits Vehicle properties.

---

# Polymorphism

Polymorphism means:
same function with different behavior.

Example:

```cpp
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
```

Same function:
```cpp
sound()
```

Different behavior:
- Dog -> Bhow
- Cat -> Meow