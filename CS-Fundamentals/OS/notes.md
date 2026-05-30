 
# OS Notes Day 1

# 1. Process

A process is a program that is currently executing.

Examples:
- Chrome
- VS Code
- Spotify

All are processes.

---

# 2. Thread

A thread is the smallest unit of execution inside a process.

One process can contain multiple threads.

Example:
In Chrome:
- one thread for UI
- one for video
- one for network

---

# 3. Difference Between Process and Thread

| Process | Thread |
|---|---|
| Heavyweight | Lightweight |
| Separate memory | Shared memory |
| Slower creation | Faster creation |
| Communication slower | Communication faster |
| More resources needed | Less resources needed |

---

# 4. Context Switching

Context switching is the process of saving the current process state and loading another process state so CPU can switch between processes.

Example:
VS Code -> Chrome -> Spotify

CPU rapidly switches between processes.

---

# 5. What data is saved during Context Switching?

OS saves:
- Registers
- Program Counter
- Stack
- Memory information
- Current execution position

This saved information is called Context.

---

# 6. PCB (Process Control Block)

Context is stored inside PCB.

PCB = Process Control Block

PCB is stored in RAM.

PCB contains:
- Process ID
- Process State
- Registers
- Scheduling information
- Program Counter
- Memory information

---

# 7. Why Context Switching is Costly

During context switching:
- current process state is saved
- next process state is loaded

During this time:
- CPU does not perform actual computation
- CPU only performs management work

Too many context switches reduce performance.

---

# 8. Process States

## New
Process is being created.

Example:
Opening Chrome.

---

## Ready
Process is ready for execution and waiting for CPU.

---

## Running
Process is currently executing on CPU.

---

## Waiting / Blocked
Process is waiting for:
- file access
- network response
- user input
- I/O operation

Example:
Chrome waiting for internet response.

---

## Terminated
Process execution completed.

---

# 9. Process State Flow

New -> Ready -> Running -> Waiting -> Ready -> Running -> Terminated

---

# 10. Running -> Ready

This happens when:
- time quantum ends
- scheduler switches CPU to another process

Process is not blocked.
It is only waiting for CPU again.

Example:
Round Robin Scheduling.

---

# 11. Running -> Waiting

This happens when process needs:
- user input
- internet response
- file access
- I/O operation

Process cannot continue until resource becomes available.

---

# 12. CPU Scheduling

CPU Scheduling is the process used by Operating System to decide:

which process gets CPU next and for how much time.

CPU can execute only one process at a time (per core),
so OS must decide which process should run first.

Example:
If:
- Chrome
- VS Code
- Spotify

all want CPU together,
then OS uses CPU Scheduling Algorithms to decide execution order.

Goals of CPU Scheduling:
- Better CPU utilization
- Faster response time
- Fair execution
- Minimum waiting time

---

# 13. Types of CPU Scheduling Algorithms

Main CPU Scheduling Algorithms are:

1. FCFS (First Come First Serve)
2. SJF (Shortest Job First)
3. SRTF (Shortest Remaining Time First)
4. Round Robin (RR)
5. Priority Scheduling

---

# 14. FCFS (First Come First Serve)

In FCFS:
the process that arrives first gets CPU first.

Example:

P1 -> P2 -> P3

Execution Order:
P1 executes completely first,
then P2,
then P3.

Real Life Example:
Ticket counter queue.

Advantages:
- Simple
- Easy to implement

Disadvantages:
- Long waiting time
- Convoy effect

Convoy Effect:
small processes wait behind long process.

Example:
If P1 takes 20 seconds,
then all small processes behind it must wait.

Type:
Non-Preemptive

---

# 15. SJF (Shortest Job First)

In SJF:
process with shortest burst time executes first.

Burst Time:
total CPU execution time needed by process.

Example:

| Process | Burst Time |
|---|---|
| P1 | 10 |
| P2 | 2 |
| P3 | 5 |

Execution:
P2 -> P3 -> P1

Advantages:
- Minimum average waiting time

Disadvantages:
- Starvation possible

Starvation:
long process may never get CPU because short jobs keep arriving.

Type:
Non-Preemptive

---

# 16. SRTF (Shortest Remaining Time First)

SRTF is the preemptive version of SJF.

In this algorithm:
the process with shortest remaining execution time gets CPU.

If a new shorter process arrives,
OS removes CPU from current process and gives it to shorter process.

Example:

| Process | Burst Time |
|---|---|
| P1 | 8 |
| P2 | 2 |

If P1 is running and P2 arrives,
CPU switches to P2.

Advantages:
- Better response time
- Good average waiting time

Disadvantages:
- More context switching
- Starvation possible

Type:
Preemptive

---

# 17. Round Robin (RR)

Round Robin gives fixed CPU time to each process.

This fixed time is called:
Time Quantum.

Example:

Time Quantum = 2ms

Execution:
P1 -> P2 -> P3 -> P1

Each process gets CPU for only 2ms.

If process is not completed:
it goes back to Ready Queue.

Advantages:
- Fair scheduling
- Good responsiveness
- Suitable for multitasking systems

Disadvantages:
- High context switching overhead
- Performance decreases if time quantum is very small

Type:
Preemptive

---

# 18. Time Quantum

Time Quantum is fixed CPU time given to each process in Round Robin Scheduling.

Example:

Time Quantum = 2ms

CPU executes:
- P1 for 2ms
- P2 for 2ms
- P3 for 2ms

then repeats again.

---

# 19. Problem with Small Time Quantum

If Time Quantum is very small:
then CPU performs too many context switches.

During every switch:
- current process state is saved
- next process state is loaded

This increases overhead and reduces CPU performance.

Too many context switches waste CPU time.

---

# 20. Priority Scheduling

In Priority Scheduling:
CPU is allocated to highest priority process first.

Example:

| Process | Priority |
|---|---|
| P1 | 1 |
| P2 | 5 |

Smaller number usually means higher priority.

So:
P1 executes before P2.

Advantages:
- Important processes execute first

Disadvantages:
- Low priority processes may starve

Type:
Can be both:
- Preemptive
- Non-Preemptive

---

# 21. Starvation

Starvation means:
a process waits for CPU for a very long time or may never get CPU.

Example:
In SJF,
long processes may continuously wait because short processes keep arriving.

Example:

P1 burst time = 20
P2 burst time = 1
P3 burst time = 1

CPU keeps selecting shorter jobs.

So P1 waits for very long time.

---

# 22. Preemptive Scheduling

In Preemptive Scheduling:
OS can remove CPU from a running process and give it to another process.

Example:
- Round Robin
- SRTF

Example:
If time quantum ends in Round Robin,
OS switches CPU to another process.

Advantages:
- Better responsiveness
- Fair CPU sharing

Disadvantages:
- More context switching
- More overhead

---

# 23. Non-Preemptive Scheduling

In Non-Preemptive Scheduling:
once process gets CPU,
it continues execution until:
- process finishes
or
- process enters waiting state

CPU is not forcefully taken away.

Examples:
- FCFS
- SJF

Advantages:
- Simple
- Less context switching

Disadvantages:
- Poor responsiveness
- Long waiting possible

---

# 24. Difference Between Preemptive and Non-Preemptive Scheduling

| Preemptive | Non-Preemptive |
|---|---|
| CPU can be taken away | CPU cannot be forcefully removed |
| Better responsiveness | Simpler implementation |
| More context switching | Less context switching |
| More overhead | Less overhead |

---

# 25. Which Scheduling Algorithms are Preemptive?

| Algorithm | Type |
|---|---|
| FCFS | Non-Preemptive |
| SJF | Non-Preemptive |
| SRTF | Preemptive |
| Round Robin | Preemptive |
| Priority Scheduling | Both possible |

---

# OS Notes Day 4

# 26. Deadlock

Deadlock happens when two or more processes wait forever for each other’s resources.

Example:

P1:
holds Resource A
waiting for Resource B

P2:
holds Resource B
waiting for Resource A

Both processes wait forever.

This condition is called Deadlock.

---

# 27. 4 Coffman Conditions For Deadlock

Deadlock occurs only if all these 4 conditions exist together.

---

## 1. Mutual Exclusion

A resource can be used by only one process at a time.

Example:
- Printer
- File lock
- Mutex

If everyone could use resource together,
deadlock would not happen.

---

## 2. Hold and Wait

Process holds one resource and waits for another resource.

Example:

P1:
holds Resource A
waiting for Resource B

---

## 3. No Preemption

Resource cannot be forcefully taken away by OS.

Process releases resource only after work completes.

If OS could forcefully remove resource,
deadlock could be broken.

---

## 4. Circular Wait

Processes form circular dependency.

Example:

P1 waits for P2
P2 waits for P3
P3 waits for P1

This circular chain causes deadlock.

---

# 28. Important Point

Deadlock is possible only when all 4 Coffman conditions occur together.

If even one condition is removed,
deadlock cannot happen.

---

# 29. Deadlock Prevention

Deadlock Prevention means:
system is designed in such a way that deadlock never happens.

Idea:
break one of the Coffman conditions.

Example:
avoid circular wait by forcing fixed resource order.

Advantages:
- Deadlock impossible

Disadvantages:
- Resource utilization may decrease
- Less flexibility

---

# 30. Deadlock Avoidance

Deadlock Avoidance means:
OS checks whether resource allocation keeps system in safe state or not.

If system becomes unsafe,
resource is not allocated.

Most famous algorithm:
Banker’s Algorithm

Safe State:
system can execute all processes safely.

Unsafe State:
deadlock may happen in future.

Advantages:
- Better resource utilization than prevention

Disadvantages:
- More complex
- Requires future resource information

---

# 31. Banker’s Algorithm

Banker’s Algorithm works like bank loan system.

OS checks:
if resources are allocated now,
will system still remain safe?

If yes:
allocate resource.

If no:
process must wait.

---

# 32. Deadlock Detection

In Deadlock Detection:
OS allows deadlock to happen first,
then detects it later.

OS periodically checks:
whether circular waiting exists or not.

Advantages:
- Simple allocation policy

Disadvantages:
- Deadlock may already affect system

---

# 33. Deadlock Recovery

If deadlock is detected,
OS must recover from it.

Methods:
- terminate processes
- restart processes
- forcefully release resources

---

# 34. Difference Between Prevention, Avoidance, Detection

| Method | Idea |
|---|---|
| Prevention | Never allow deadlock conditions |
| Avoidance | Allocate resources carefully |
| Detection | Detect deadlock after it occurs |
| Recovery | Remove deadlock after detection |

---

# 35. Real Life Example

Suppose:

Person 1:
has spoon
waiting for fork

Person 2:
has fork
waiting for spoon

Both wait forever.

This is real-life deadlock example.

---

# OS Notes Day 5

# Memory Management

Memory Management is the process used by Operating System to manage RAM efficiently between multiple programs.

OS decides:
- which process gets memory
- how much memory is needed
- when memory should be released

---

# Stack Memory

Stack memory is automatic temporary memory managed by compiler.

It stores:
- local variables
- function calls
- function parameters

Example:

```cpp
int a = 5;
````

a is stored in stack memory.

---

# Function Call in Stack

```cpp
void fun() {
    int x = 10;
}
```

When function runs:

* stack frame is created
* x is stored in stack

When function ends:

* memory is automatically removed

This is why stack memory is temporary.

---

# Stack Features

* Fast memory allocation
* Automatic memory management
* Small memory size
* Uses LIFO (Last In First Out)

---

# Stack Overflow

Stack Overflow happens when stack memory becomes full.

Reasons:

* infinite recursion
* very large local variables

Example:

```cpp
void fun() {
    fun();
}
```

Infinite recursive calls keep increasing stack frames.

Eventually stack becomes full.

This causes Stack Overflow.

---

# Heap Memory

Heap memory is dynamic memory managed manually by programmer.

Heap memory is used when:

* memory size is not known before runtime
* large memory allocation is needed

Example:

```cpp
int* p = new int(5);
```

This memory is allocated inside heap.

---

# Dynamic Memory

Dynamic memory means:
memory size is decided during runtime.

Example:

```cpp
int n;
cin >> n;

int* arr = new int[n];
```

User gives size during execution.

So memory is allocated dynamically.

---

# Heap Features

* Large memory size
* Flexible memory allocation
* Slower than stack
* Programmer must manually release memory

---

# Memory Leak

Memory Leak happens when dynamically allocated memory is not released.

Example:

```cpp
int* p = new int(5);
```

If:

```cpp
delete p;
```

is not used,
memory remains occupied unnecessarily.

This causes Memory Leak.

---

# Dangling Pointer

Dangling Pointer means:
pointer points to memory that is already deleted.

Example:

```cpp
int* p = new int(5);

delete p;
```

Now:
p still stores old address,
but memory is already released.

This is dangerous.

---

# Stack vs Heap

| Stack                  | Heap                  |
| ---------------------- | --------------------- |
| Automatic memory       | Manual memory         |
| Fast                   | Slower                |
| Small size             | Large size            |
| Temporary              | Dynamic               |
| Compiler managed       | Programmer managed    |
| Stores local variables | Stores dynamic memory |

---

# Easy Difference

Stack:

* temporary
* fast
* automatic

Heap:

* dynamic
* flexible
* manual



---
