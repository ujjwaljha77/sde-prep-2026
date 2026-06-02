# Strategy Design Pattern

# What is Strategy Pattern?

Strategy Pattern means:

multiple algorithms or behaviors
can be switched dynamically at runtime.

Instead of writing all logic in one class,
we separate each algorithm into different classes.

---

# Real Life Example

Payment System:

Different payment methods:
- Credit Card
- UPI
- PayPal

User can choose any payment method dynamically.

---

# Problem Without Strategy Pattern

```cpp
if(payment == "UPI") {
}

else if(payment == "Card") {
}

else if(payment == "PayPal") {
}
```

Problems:
- too many if else
- difficult maintenance
- difficult scalability

---

# Main Idea

Create:
separate strategy classes.

Main class only uses strategy object.

---

# Strategy Pattern Code

```cpp
#include<bits/stdc++.h>
using namespace std;

class PaymentStrategy {

public:

    virtual void pay(int amount) = 0;
};

class UPI : public PaymentStrategy {

public:

    void pay(int amount) {

        cout << "Paid using UPI: " << amount << endl;
    }
};

class CreditCard : public PaymentStrategy {

public:

    void pay(int amount) {

        cout << "Paid using Credit Card: " << amount << endl;
    }
};

class ShoppingCart {

    PaymentStrategy* strategy;

public:

    void setPaymentStrategy(PaymentStrategy* strategy) {

        this->strategy = strategy;
    }

    void checkout(int amount) {

        strategy->pay(amount);
    }
};

int main() {

    ShoppingCart cart;

    UPI upi;

    cart.setPaymentStrategy(&upi);

    cart.checkout(500);
}
```

---

# Output

```cpp
Paid using UPI: 500
```

---

# Advantages

- removes if else
- easy scalability
- cleaner code
- runtime behavior change possible

---

# Real World Uses

- payment systems
- sorting algorithms
- navigation systems
- compression algorithms

---

# Easy Summary

Strategy Pattern means:

different algorithms can be switched dynamically at runtime.