#ifndef SEAT_H
#define SEAT_H
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
// ============================================================
// Seat Class
// Unit 2: Constructor, Copy Constructor, Destructor
// Unit 4: Exception Handling (throws runtime_error)
// ============================================================
class Seat {
int seatNumber;
bool isBooked;
string seatType; // Platinum, Gold, Silver
public:
// Parameterized Constructor with default argument
Seat(int n, string type = "Silver")
: seatNumber(n), isBooked(false), seatType(type) {}
// Copy Constructor
Seat(const Seat& s)
: seatNumber(s.seatNumber),
isBooked(s.isBooked),
seatType(s.seatType) {}
// Book a seat — throws exception if already booked
bool book() {
if (isBooked)
throw runtime_error("Seat " + to_string(seatNumber) + " already booked!");
isBooked = true;
return true;
}
// Cancel a booking
void cancel() { isBooked = false; }
// Getters
bool getStatus() const { return isBooked; }
int getNumber() const { return seatNumber; }
string getType() const { return seatType; }
// Destructor
~Seat() {}
};
#endif // SEAT_H
