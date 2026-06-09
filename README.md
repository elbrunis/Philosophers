<div align="center">
  <h2 align="center">Philosophers</h2>

  <p align="center">
    <strong>A multithreaded C simulation of the classic Dining Philosophers problem using POSIX threads and mutexes to demonstrate concurrency, synchronization, and deadlock prevention.</strong>
    <br />
    <br />
    <a href="https://github.com/elbrunis/Philosophers/issues">Report Bug</a>
    ·
    <a href="https://github.com/elbrunis/Philosophers/issues">Request Feature</a>
  </p>

  <p align="center">
    <img src="https://img.shields.io/badge/License-MIT-blue.svg" alt="License">
    <img src="https://img.shields.io/badge/Build-Passing-brightgreen.svg" alt="Build Status">
  </p>
</div>

## 📑 Table of Contents
- [✨ Key Features](#-key-features)
- [🛠 Tech Stack](#-tech-stack)
- [🚀 Getting Started](#-getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [💡 Usage](#-usage)
- [🗺 Roadmap](#-roadmap)
- [🤝 Contributing](#-contributing)
- [📄 License](#-license)

---

## ✨ Key Features
* **N-Philosopher Simulation:** Accepts any number of philosophers via CLI, each running in its own `pthread` with individual timing parameters.
* **Mutex-Guarded Forks:** Every fork is protected by a `pthread_mutex_t`, preventing race conditions when adjacent philosophers contend for shared resources.
* **Precise Timing Model:** Uses `gettimeofday()` for millisecond-resolution timeouts (`time_to_die`, `time_to_eat`, `time_to_sleep`) with synchronized start offset.
* **Optional Meal Limit:** A fifth argument stops the simulation once each philosopher has eaten a specified number of times.
* **Leak-Free Memory Management:** Dedicated teardown function (`free_structs`) safely destroys all dynamically allocated structures.

---

## 🛠 Tech Stack

| Category | Technologies |
| :--- | :--- |
| **Core** | C (C99/C11) |
| **Tools** | GNU Make, POSIX Threads |

---

## 🚀 Getting Started

Follow these instructions to set up the project locally.

### Prerequisites
* C compiler (`cc`, `gcc`, or `clang`)
* GNU `make`
* POSIX-compliant operating system (Linux, macOS)

### Installation

1. Clone the repository:
```bash
git clone https://github.com/elbrunis/Philosophers.git
```

2. Build the project:
```bash
cd Philosophers
make
```

---

## 💡 Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

**Examples:**

```bash
# 5 philosophers, die after 800ms, eat 200ms, sleep 200ms
./philo 5 800 200 200

# 4 philosophers with meal limit of 7
./philo 4 410 200 200 7

# Single philosopher edge case
./philo 1 400 100 100
```

---

## 🗺 Roadmap

- [ ] Implement full philosopher lifecycle (eating, sleeping, thinking)
- [ ] Add death detection and simulation stop on death
- [ ] Add logging with timestamps for each state change

---

## 🤝 Contributing

Contributions are welcome! Feel free to open an issue or submit a pull request.

---

## 📄 License

Distributed under the MIT License. See `LICENSE` for more information.
