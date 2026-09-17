# 🏥 Clinic Management System (C Language)

A robust, console-based **Clinic Management System** developed in C. This project demonstrates core core C programming principles and data structures including **Singly Linked Lists**, **Dynamic Memory Allocation**, and **Modular Software Architecture** with clean layer separation.

---

## 🌟 Key Features

### 🔑 Admin Mode
* **Authentication:** Password-protected access (Default password: `1234`, max 3 attempts).
* **Add Patient Record:** Register a new patient with unique ID, Name, Age, and Gender.
* **Edit Patient Record:** Update existing patient information via unique ID.
* **Reserve Doctor Slot:** Book available time slots from the daily schedule (5 available slots per day).
* **Cancel Reservation:** Cancel existing reservations and free up the slot for other patients.

### 👤 User Mode
* **View Patient Record:** Display patient personal data and details by ID.
* **View Today's Reservations:** Display today's appointment list showing booked slots along with corresponding Patient IDs.

---

## 📁 Project Structure

```text
├── STD.h           # Standard types definitions
├── C_interface.h   # Function prototypes, macros, and structures
├── C_Program.c     # Core logic and function implementations
└── C_main.c        # Main entry point and menu navigation
```
---

## 🛠️ Build and Run

### Prerequisites
* GCC Compiler / Any C IDE (VS Code, Code::Blocks, Eclipse, etc.)

### Compilation via GCC Terminal
Navigate to the project directory and run:

```bash
# Compile source files
gcc C_main.c C_Program.c -o clinic_system

# Run the executable
./clinic_system