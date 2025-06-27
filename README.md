# 🍜 Philosophers: Solving the Dining Philosophers Problem

![Language: C](https://img.shields.io/badge/Language-C-blue.svg)
![Build: Makefile](https://img.shields.io/badge/Build-Makefile-green.svg)
![Concurrency: Pthreads](https://img.shields.io/badge/Concurrency-Pthreads-blueviolet.svg)
![Sync: Mutex](https://img.shields.io/badge/Sync-Mutex-orange.svg)
![School: 42 Paris](https://img.shields.io/badge/School-42_Paris-orange.svg)
![Grade: 100/100](https://img.shields.io/badge/Grade-100/100-brightgreen.svg)

## ✨ Overview

`Philosophers` is a classic and highly challenging project from 42 Paris, focused on implementing a solution to the **"Dining Philosophers Problem"**. This famous problem, originally formulated by **Edsger W. Dijkstra**, is used to illustrate fundamental issues of concurrency, deadlock, and resource starvation in a multi-threaded environment.

The core objective was to simulate philosophers who alternate between eating, thinking, and sleeping, sharing a limited number of forks (resources) at a circular table. The challenge lies in designing a robust synchronization mechanism to prevent deadlock (where philosophers endlessly wait for each other) and starvation (where a philosopher never gets to eat).

## 🌟 Key Features & Implementation Details (Mandatory Part)

This project implements a simulation of the dining philosophers problem using POSIX threads (`pthreads`) and mutexes for synchronization.

### **1. Philosopher Simulation**

*   **Philosopher Lifecycle:** Each philosopher is represented by a separate **thread**, cycling through states of *thinking*, *eating*, and *sleeping*.
*   **Resource Management:** Philosophers require **two forks** (mutexes) to eat, picking them up one by one from their left and right.
*   **Time Parameters:** The simulation operates with configurable time-to-die, time-to-eat, and time-to-sleep parameters (in milliseconds).
*   **Death Condition:** A philosopher dies if they do not eat within the specified `time_to_die` from their last meal (or simulation start).
*   **Optional Meal Limit:** The simulation can stop gracefully if all philosophers have eaten a specified number of times.

### **2. Concurrency Control & Synchronization**

*   **POSIX Threads (`pthreads`):** Each philosopher's behavior is managed by its own independent thread, demonstrating multi-threaded programming.
*   **Mutexes:** **Forks are represented by mutexes**, ensuring that only one philosopher can pick up a specific fork at a time, preventing race conditions.
    *   `pthread_mutex_init`: Initializes mutexes.
    *   `pthread_mutex_lock`: Acquires a mutex (picks up a fork).
    *   `pthread_mutex_unlock`: Releases a mutex (puts down a fork).
*   **Deadlock Prevention:** Implemented a strategy to prevent classical deadlock scenarios (e.g., ensuring an order of fork acquisition, odd/even philosopher strategy).
*   **State Logging:** All status changes (taking fork, eating, sleeping, thinking, dying) are precisely logged with timestamps without interleaving, ensuring correct event sequencing.
*   **No Global Variables (except justified):** Adheres to 42's strict rules on global variables, focusing on passing data via structures and arguments.

## 🛠️ Technologies Used

*   **Language:** C
*   **Build System:** Makefile
*   **Concurrency:** POSIX Threads (`pthreads`)
*   **Synchronization:** Mutexes (`pthread_mutex_t`)
*   **System Calls:** `gettimeofday()` for precise timestamps, `usleep()` for timed delays.
*   **Memory Management:** Explicit `malloc` and `free` for dynamic allocations.

## 🚀 How to Use

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/yourusername/philosophers.git
    cd philosophers
    ```
2.  **Compile the program:**
    ```bash
    make
    # This will generate the 'philo' executable.
    ```
3.  **Run the simulation:**
    ```bash
    ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
    ```
    *Example:*
    ```bash
    ./philo 5 800 200 200 7
    # 5 philosophers, they die after 800ms, eat for 200ms, sleep for 200ms, and the simulation stops when each has eaten 7 times.
    ```
    The program will output a log of events (philosophers taking forks, eating, sleeping, thinking, dying) in real-time.

## 🎓 Learning Outcomes

This project was pivotal in deepening my understanding of:

*   **Concurrency & Parallelism:** Fundamental concepts of multi-threaded programming and parallel execution.
*   **Resource Synchronization:** Mastery of mutexes to protect shared resources and prevent race conditions, drawing from principles demonstrated by pioneers like **Edsger W. Dijkstra**.
*   **Deadlock & Starvation Prevention:** Strategies to avoid common concurrency issues in complex systems.
*   **Process & Thread Management:** Creating, managing, and synchronizing threads (`pthreads`).
*   **System Programming:** Utilizing system calls for timing and process control.
*   **Algorithmic Thinking:** Designing a solution for a classic computer science problem.
*   **C Programming:** Reinforcing skills in memory management, data structuring for threads, and robust error handling.
