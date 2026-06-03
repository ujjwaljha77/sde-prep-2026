# Decorator Design Pattern

# What is Decorator Pattern?

Decorator Pattern means:

adding new features to an object
without modifying original class.

---

# Real Life Example

Coffee Shop:

Base Coffee:
- Normal Coffee

Extra Features:
- Milk
- Chocolate
- Cream

Each topping adds extra functionality.

---

# Main Idea

Instead of modifying original class,
wrap object with decorators.

---

# Decorator Pattern Code

```cpp
#include<bits/stdc++.h>
using namespace std;

class Coffee {

public:

    virtual int cost() = 0;
};

class SimpleCoffee : public Coffee {

public:

    int cost() {

        return 100;
    }
};

class MilkDecorator : public Coffee {

    Coffee* coffee;

public:

    MilkDecorator(Coffee* coffee) {

        this->coffee = coffee;
    }

    int cost() {

        return coffee->cost() + 20;
    }
};

class ChocolateDecorator : public Coffee {

    Coffee* coffee;

public:

    ChocolateDecorator(Coffee* coffee) {

        this->coffee = coffee;
    }

    int cost() {

        return coffee->cost() + 30;
    }
};

int main() {

    Coffee* coffee = new SimpleCoffee();

    coffee = new MilkDecorator(coffee);

    coffee = new ChocolateDecorator(coffee);

    cout << coffee->cost();
}
```

---

# Output

```cpp
150
```

Because:
- Coffee = 100
- Milk = 20
- Chocolate = 30

Total:
150

---

# Advantages

- flexible feature addition
- avoids modifying existing code
- follows Open Closed Principle

---

# Real World Uses

- coffee ordering systems
- pizza toppings
- text editors
- UI frameworks

---

# Easy Summary

Decorator Pattern means:

add new features to objects
without changing original class.

---
