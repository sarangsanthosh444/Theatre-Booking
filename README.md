# 🎬 Theatre Online Booking System (C++)

A console-based Theatre Ticket Booking System built using C++.  
This project demonstrates core Object-Oriented Programming (OOP) concepts from the **OOP Using C++ syllabus**.

---

## 📌 Features

- 🎥 View available movies and showtimes  
- 🪑 Interactive seat map (5x5 grid)  
- 🎟️ Book multiple seats with validation  
- 💳 Template-based payment processing  
- ⚠️ Exception handling for invalid inputs  
- 📦 Uses STL containers (vector, map, for_each)

---

## 📁 Project Structure


theatre-booking-cpp/
│── ui.h # Console UI (menus, seat map display)
│── movie.h # Movie base class + Show derived class
│── seat.h # Seat class with booking logic
│── payment.h # Template PaymentProcessor<T>
│── main.cpp # Main program (Theatre, Booking, STL)
│── README.md # Project documentation


---

## ⚙️ How to Compile & Run

### 🔧 Compile
```bash
g++ -std=c++17 main.cpp -o theatre
▶️ Run
Windows:
theatre.exe
Linux / Mac:
./theatre
🧠 OOP Concepts Used
Concept	Implementation
Classes & Objects	All files
Encapsulation	Private members + getters
Inheritance	Show inherits from Movie
Polymorphism	Virtual display()
Constructors	Seat, Movie, Show
Copy Constructor	Seat class
Destructor	Seat, Movie
Static Member	Booking ID counter
Templates	PaymentProcessor<T>
Exception Handling	Seat booking validation
STL Containers	vector, map
STL Algorithms	for_each
🖥️ Sample Output
========== MAIN MENU ==========
1. View Available Movies
2. Book Tickets
3. Cancel Booking
4. View My Bookings
5. Exit
================================
🚀 Future Improvements
Cancel booking functionality
User login system
File storage (save bookings)
GUI version (instead of console)
👨‍💻 Team
RA2511003012378
RA2511003012379
RA2511003012380
🏫 Submitted To
Dr. Sammy F
SRM Institute of Science and Technology
Course: Object Oriented Programming Using C++