# Observer Design Pattern

# What is Observer Pattern?

Observer Pattern means:

when one object changes,
all dependent objects get notified automatically.

---

# Real Life Example

YouTube Notifications.

When creator uploads a video:
all subscribers receive notification.

---

# Main Components

# Subject

Main object being observed.

Example:
YouTube Channel

---

# Observer

Objects that receive updates.

Example:
Subscribers

---

# Working of Observer Pattern

1. Observers subscribe to subject.
2. Subject stores observer list.
3. When subject changes:
   all observers are notified.

---

# Observer Pattern Code

```cpp
#include<bits/stdc++.h>
using namespace std;

class Observer {

public:

    virtual void update(string msg) = 0;
};

class Subscriber : public Observer {

    string name;

public:

    Subscriber(string name) {
        this->name = name;
    }

    void update(string msg) {

        cout << name << " received: " << msg << endl;
    }
};

class YouTubeChannel {

    vector<Observer*> subscribers;

public:

    void subscribe(Observer* obs) {

        subscribers.push_back(obs);
    }

    void notify(string msg) {

        for(auto sub : subscribers) {

            sub->update(msg);
        }
    }
};

int main() {

    YouTubeChannel channel;

    Subscriber s1("Ujjwal");
    Subscriber s2("Rahul");

    channel.subscribe(&s1);
    channel.subscribe(&s2);

    channel.notify("New Video Uploaded");
}
```

---

# Output

```cpp
Ujjwal received: New Video Uploaded
Rahul received: New Video Uploaded
```

---

# Advantages

- loose coupling
- automatic notification
- scalable
- reusable

---

# Disadvantages

- many observers can slow system
- difficult debugging sometimes

---

# Real World Uses

- YouTube notifications
- Instagram notifications
- Stock market apps
- Event systems
- Chat applications

---

# Easy Summary

Observer Pattern means:

one object changes,
all subscribed objects get notified automatically.