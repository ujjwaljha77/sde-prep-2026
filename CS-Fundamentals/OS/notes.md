 
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

CPU scheduling decides:
which process gets CPU next.

---

# 13. FCFS (First Come First Serve)

Process arriving first executes first.

Advantages:
- Simple

Disadvantages:
- Long waiting time
- Convoy effect

---

# 14. SJF (Shortest Job First)

Process with shortest burst time executes first.

Advantages:
- Minimum average waiting time

Disadvantages:
- Starvation possible

---

# 15. Round Robin

Each process gets fixed CPU time called Time Quantum.

Example:
P1 -> P2 -> P3 -> P1

Advantages:
- Fair scheduling
- Good responsiveness

Disadvantages:
- High context switching overhead