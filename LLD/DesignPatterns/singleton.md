# Singleton Design Pattern

# Design Patterns

Design Patterns are reusable solutions to common software design problems.

They help in:
- writing clean code
- improving scalability
- reducing code duplication
- improving maintainability

---

# Singleton Design Pattern

Singleton Design Pattern ensures:

only one object of a class is created during entire program execution.

---

# Why Singleton is Needed

Some resources should have only one object.

Examples:
- Database Connection
- Logger
- Configuration Manager
- Cache Manager

Creating multiple objects may:
- waste memory
- create conflicts
- reduce performance

---

# Main Idea of Singleton

Singleton uses:
- private constructor
- static instance
- static getter function

This prevents users from creating multiple objects directly.

---

# Singleton Code

```cpp
class Singleton {

private:

    static Singleton* instance;

    Singleton() {
        cout << "Object Created";
    }

public:

    static Singleton* getInstance() {

        if(instance == nullptr) {
            instance = new Singleton();
        }

        return instance;
    }
};

Singleton* Singleton::instance = nullptr;
```

---

# Usage

```cpp
Singleton* s1 = Singleton::getInstance();

Singleton* s2 = Singleton::getInstance();
```

Both:
- s1
- s2

point to same object.

---

# Why Constructor is Private

```cpp
Singleton s;
```

should not be possible.

Private constructor prevents direct object creation.

Objects can only be created using:

```cpp
getInstance();
```

---

# How Singleton Works

First call:

```cpp
getInstance();
```

creates object.

Next calls:
return same object again.

---

# Advantages of Singleton

- Only one object
- Saves memory
- Global access point
- Better resource management

---

# Disadvantages of Singleton

- Hard to test
- Global state issues possible
- Tight coupling may increase

---

# Real Life Example

Prime Minister:
only one PM exists at a time.

Same concept:
single instance in entire system.