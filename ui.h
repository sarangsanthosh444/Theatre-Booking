#ifndef UI_H
#define UI_H
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
// ============================================================
// ConsoleUI - Frontend display class
// Handles all user-facing output: menus, seat maps, headers
// ============================================================
class ConsoleUI {
public:
// Print application banner
static void printHeader() {
cout << "\n" << endl;
cout << "****************************************************" << endl;
cout << "* THEATRE ONLINE BOOKING SYSTEM *" << endl;
cout << "* SRM Institute of Science & Tech *" << endl;
cout << "****************************************************" << endl;
cout << "\n" << endl;
}
// Print main menu
static void printMenu() {
cout << "\n========== MAIN MENU ==========" << endl;
cout << " 1. View Available Movies " << endl;
cout << " 2. Book Tickets " << endl;
cout << " 3. Cancel Booking " << endl;
cout << " 4. View My Bookings " << endl;
cout << " 5. Exit " << endl;
cout << "================================" << endl;
cout << "Enter your choice: ";
}
// Print visual seat map
static void printSeatMap(const vector<bool>& booked) {
cout << "\n========== SEAT MAP ==========" << endl;
cout << " [G] = Available [X] = Booked" << endl;
cout << "\n 1 2 3 4 5" << endl;
char row = 'A';
for (int i = 0; i < 25; i++) {
if (i % 5 == 0) cout << " " << row++ << " ";
cout << (booked[i] ? "[X] " : "[G] ");
if ((i + 1) % 5 == 0) cout << endl;
}
cout << "==============================" << endl;
}
// Print a horizontal divider
static void printDivider() {
cout << "----------------------------------------------" << endl;
}
};
#endif // UI_H