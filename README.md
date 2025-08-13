# 🚀 Redis-like In-Memory Key-Value Store in C++

A high-performance **in-memory key-value store** built from scratch in **C++**, inspired by Redis.  
Implements **core Redis commands** for storing, retrieving, and managing data using **POSIX sockets** for network communication.

---

## ✨ Features
- **Core Data Operations** – `SET`, `GET`, `DEL`, `EXISTS`, `KEYS`
- **In-Memory Storage** – Fast access using C++ STL containers
- **Persistent Connections** – Handle multiple clients over TCP sockets
- **Custom Protocol Parsing** – Lightweight request/response format
- **POSIX Socket Programming** – Low-level networking for server-client communication

---

## 🛠 Tech Stack
- **Language:** C++17
- **Networking:** POSIX Sockets (TCP)
- **Data Structures:** `unordered_map` for O(1) lookups
- **Build Tool:** `g++`
- **OS Compatibility:** Linux / WSL / macOS

---

## 🔮 Future Improvements
- Implement **persistence to disk**
- Add **pub/sub messaging**
- Optimize memory management for large datasets
- Support **Redis Serialization Protocol (RESP)**
