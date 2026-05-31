# Factory Design Pattern

# Design Pattern

Design Patterns are reusable solutions to common software design problems.

They help in:
- clean code
- scalability
- maintainability
- reducing duplication

---

# Factory Design Pattern

Factory Pattern means:

object creation logic is handled by a separate factory class.

Instead of creating objects directly,
we ask factory to create objects.

---

# Problem Without Factory

Suppose:

```cpp
class Car {
};

class Bike {
};

int main() {

    string type = "Car";

    if(type == "Car") {
        Car c;
    }

    else if(type == "Bike") {
        Bike b;
    }
}
```

Problem:
- too many if else
- messy code
- difficult scalability
- hard maintenance

If new vehicles come:
- Truck
- Bus
- Cycle

then code keeps increasing.

---

# Main Idea of Factory Pattern

Instead of:

```cpp
Car c;
```

we use:

```cpp
VehicleFactory::getVehicle("Car");
```

Factory decides:
which object to create.

---

# Factory Pattern Code

```cpp
#include<bits/stdc++.h>
using namespace std;

class Vehicle {

public:

    virtual void start() = 0;
};

class Car : public Vehicle {

public:

    void start() {
        cout << "Car Started";
    }
};

class Bike : public Vehicle {

public:

    void start() {
        cout << "Bike Started";
    }
};

class VehicleFactory {

public:

    static Vehicle* getVehicle(string type) {

        if(type == "Car") {
            return new Car();
        }

        else if(type == "Bike") {
            return new Bike();
        }

        return nullptr;
    }
};

int main() {

    Vehicle* v1 = VehicleFactory::getVehicle("Car");

    v1->start();
}
```

---

# Output

```cpp
Car Started
```

---

# How Factory Works

User requests:

```cpp
VehicleFactory::getVehicle("Car");
```

Factory checks:
which object is needed.

Factory creates:
```cpp
Car object
```

and returns it.

---

# Advantages of Factory Pattern

- cleaner code
- centralized object creation
- scalable
- reusable
- easy maintenance

---

# Factory Pattern and SOLID Principles

# SRP

Vehicle classes:
only vehicle logic.

Factory:
only object creation logic.

---

# OCP

New vehicle classes can be added:
without modifying old classes.

Example:

```cpp
class Truck : public Vehicle {
};
```

---

# DIP

Code depends on:

```cpp
Vehicle
```

abstraction,

not directly on:
- Car
- Bike

---

# ISP

Vehicle interface contains:
only required methods.

---

# Real Life Example

Food Factory:

You request:
```cpp
Pizza
```

Factory creates pizza.

You do not care:
how it was created internally.

---

# Easy Summary

Factory Pattern means:

do not create objects directly.

Use a factory class
to create objects.