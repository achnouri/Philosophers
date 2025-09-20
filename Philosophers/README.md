# 🍝 Philosophers

Philosophers is a **concurrency project** from the [42 School](https://42.fr) curriculum.  
The goal is to solve the classic **Dining Philosophers Problem** using threads and synchronization mechanisms.  

This project emphasizes:
- Understanding multithreading with **pthreads**.  
- Using **mutexes** to manage shared resources.  
- Avoiding common concurrency issues such as **deadlocks** and **race conditions**.  
- Writing clean, efficient, and memory-safe C code.  

---

## 📖 Table of Contents
- [Features](#-features)
- [Technical Details](#-technical-details)
- [Installation & Usage](#-installation--usage)
- [Examples](#-examples)
- [Project Rules](#-project-rules)
- [Learning Outcomes](#-learning-outcomes)
- [Authors](#-authors)

---

## 🚀 Features

- Multiple philosophers sitting around a table.  
- Each philosopher alternates between **eating**, **thinking**, and **sleeping**.  
- A philosopher must pick up **two forks (mutexes)** to eat.  
- Forks are shared resources between philosophers.  
- The program prevents **deadlocks** and ensures all philosophers eventually eat.  
- Each philosopher dies if they cannot eat within the specified `time_to_die`.  
- Accurate timing using `usleep` and custom time management.  
- Thread-safe logging of philosopher actions (no mixed or corrupted output).  

---

## ⚙️ Technical Details

### System Concepts
- **Threads**: Each philosopher runs in its own thread using `pthread_create`.  
- **Mutexes**: Forks are protected with `pthread_mutex_t` to prevent simultaneous access.  
- **Time Management**: Uses `gettimeofday` for precise timing.  
- **Synchronization**: Ensures logs and resource access are thread-safe.  

### Key Actions
- `is_thinking` → Philosopher is thinking.  
- `is_sleeping` → Philosopher is sleeping.  
- `is_eating` → Philosopher has picked up two forks and is eating.  
- `has_taken_a_fork` → Philosopher picked up a fork.  
- `died` → Philosopher did not eat in time.  

---

## 🛠️ Installation & Usage

### Clone the repository
```bash
git clone https://github.com/achnouri/Philosophers.git

