# SOLID Principles

# S - Single Responsibility Principle (SRP)

Single Responsibility Principle means:

A class should have only one responsibility or one reason to change.

---

# Bad Example

```cpp
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
```

Problem:
One class handles:
- salary
- database
- report

This increases complexity.

---

# Good Example

```cpp
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
```

---

# O - Open Closed Principle (OCP)

Software should be:
- open for extension
- closed for modification

New features should be added without changing old code.

---

# Bad Example

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
```

Problem:
New payment methods require modifying old code again and again.

---

# Good Example

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
new payment methods can be added easily.

---

# L - Liskov Substitution Principle (LSP)

Child class should properly replace parent class.

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
```

Problem:
Penguin cannot fly.

But:

```cpp
Penguin p;
p.fly();
```

becomes possible.

This is wrong design.

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
- Sparrow can fly
- Penguin cannot fly

---

# I - Interface Segregation Principle (ISP)

Do not force classes to implement unnecessary methods.

---

# Bad Example

```cpp
class Worker {

public:

    virtual void code() = 0;
    virtual void cook() = 0;
};
```

Software engineer should not implement:
```cpp
cook()
```

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

class SoftwareEngineer : public Coder {

public:

    void code() {
        cout << "Writing Code";
    }
};

class Cook : public Chef {

public:

    void cook() {
        cout << "Cooking Food";
    }
};
```

---

# D - Dependency Inversion Principle (DIP)

Depend on abstraction,
not concrete classes.

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
If database changes,
App class also changes.

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
App depends on abstraction.

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