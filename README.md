# CPU Scheduling Algorithms in C

## 📌 Overview
This repository contains my **own implementations** of classic **CPU Scheduling Algorithms** written in **C** from scratch.  
These algorithms simulate process scheduling in Operating Systems and calculate important metrics like:  

- Completion Time (CT)  
- Turnaround Time (TAT)  
- Waiting Time (WT)  
- Response Time (RT)  
- Average TAT & Average WT  

---

## ⚡ Implemented Algorithms
- ✅ First Come First Serve (FCFS)  
- ✅ Shortest Job First (SJF) – Non-Preemptive  
- ✅ Shortest Remaining Time First (SRTF) – Preemptive  
- ✅ Priority Scheduling (Preemptive & Non-Preemptive)  
- ✅ Round Robin (RR)  

---

## 🛠️ How to Run
1. Clone this repository:
   ```bash
   git clone https://github.com/<your-username>/<repo-name>.git
   cd <repo-name>
2. Compile any algorithm using gcc:
   ```bash
   gcc fcfs.c -o fcfs
   ./fcfs

(replace fcfs.c with the file you want to run)

## ⏱️ Time & Space Complexities

### 1. FCFS (First Come First Serve)
- **Time Complexity:** O(n²) (due to sorting by arrival time)  
- **Space Complexity:** O(n)  

### 2. SJF (Non-Preemptive)
- **Time Complexity:** O(n²) (sorting + selection)  
- **Space Complexity:** O(n)  

### 3. SRTF (Preemptive)
- **Time Complexity:** O(total_burst * n) in worst case (since selection happens at each unit)  
- **Space Complexity:** O(n)  

### 4. Priority Scheduling
- **Time Complexity:** O(n²) (sorting + selection)  
- **Space Complexity:** O(n)  

### 5. Round Robin
- **Time Complexity:** O(total_burst) (each burst unit executed once)  
- **Space Complexity:** O(n)  
