#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <limits>

using namespace std;

// ============================================================
// UI CLASS
// ============================================================
class ConsoleUI {
public:
    static void printHeader() {
        cout << "\n===== THEATRE BOOKING SYSTEM =====\n";
    }

    static void printMenu() {
        cout << "\n1. View Movies\n2. Book Ticket\n3. Cancel Ticket\n4. View Bookings\n5. Exit\n";
        cout << "Enter choice: ";
    }

    static void printSeatMap(const vector<bool>& seats) {
        cout << "\nSeat Map (O = Available, X = Booked)\n";
        for (int i = 0; i < seats.size(); i++) {
            cout << (seats[i] ? "X " : "O ");
            if ((i + 1) % 5 == 0) cout << endl;
        }
    }
};

// ============================================================
// MOVIE / SHOW CLASS
// ============================================================
class Show {
    int id;
    string title, genre, showtime;
    int duration;
    double price;

public:
    Show(int i, string t, string g, int d, string st, double p)
        : id(i), title(t), genre(g), duration(d), showtime(st), price(p) {}

    void display() const {
        cout << "\nID: " << id << " | " << title << " (" << genre << ") "
             << duration << "min | " << showtime << " | Rs." << price << endl;
    }

    double getPrice() const { return price; }
    string getTitle() const { return title; }
    string getShowtime() const { return showtime; }
};

// ============================================================
// SEAT CLASS
// ============================================================
class Seat {
    int number;
    bool booked;
    string type;

public:
    Seat(int n, string t) : number(n), booked(false), type(t) {}

    bool book() {
        if (booked)
            throw runtime_error("Seat already booked!");
        booked = true;
        return true;
    }

    void cancel() { booked = false; }

    bool getStatus() const { return booked; }
    int getNumber() const { return number; }
};

// ============================================================
// PAYMENT TEMPLATE CLASS
// ============================================================
template <typename T>
class PaymentProcessor {
    T amount;

public:
    PaymentProcessor(T amt) : amount(amt) {}

    void processPayment() {
        cout << "\nProcessing payment of Rs." << amount << "...\n";
        cout << "Payment Successful!\n";
    }
};

// ============================================================
// BOOKING CLASS
// ============================================================
class Booking {
    static int counter;
    int bookingId;
    string userName;
    Show* show;
    vector<int> bookedSeats;
    double totalAmount;

public:
    Booking(string name, Show* s, vector<int> seats)
        : userName(name), show(s), bookedSeats(seats) {
        bookingId = ++counter;
        totalAmount = seats.size() * s->getPrice();
    }

    void printTicket() const {
        cout << "\n======= BOOKING CONFIRMATION =======" << endl;
        cout << "Booking ID : BK" << bookingId << endl;
        cout << "Name : " << userName << endl;
        cout << "Movie : " << show->getTitle() << endl;
        cout << "Showtime : " << show->getShowtime() << endl;
        cout << "Seats : ";
        for (int s : bookedSeats) cout << s << " ";
        cout << "\nTotal Amount: Rs." << totalAmount << endl;
        cout << "===================================" << endl;
    }
};

int Booking::counter = 0;

// ============================================================
// THEATRE CLASS
// ============================================================
class Theatre {
    string name;
    vector<Seat> seats;

public:
    Theatre(string n, int totalSeats) : name(n) {
        for (int i = 1; i <= totalSeats; i++) {
            string type = (i <= 5) ? "Platinum" :
                          (i <= 15) ? "Gold" : "Silver";
            seats.push_back(Seat(i, type));
        }
    }

    void displaySeats() const {
        vector<bool> status;
        for (const auto& s : seats)
            status.push_back(s.getStatus());
        ConsoleUI::printSeatMap(status);
    }

    bool bookSeat(int seatNo) {
        for (auto& s : seats)
            if (s.getNumber() == seatNo)
                return s.book();
        throw invalid_argument("Invalid seat number!");
    }

    void cancelSeat(int seatNo) {
        for (auto& s : seats)
            if (s.getNumber() == seatNo) {
                s.cancel();
                return;
            }
    }
};

// ============================================================
// MAIN FUNCTION
// ============================================================
int main() {
    ConsoleUI::printHeader();

    map<int, Show*> shows;
    shows[1] = new Show(1, "Kalki 2898 AD", "Sci-Fi", 167, "10:00 AM", 200);
    shows[2] = new Show(2, "The Wild Robot", "Animation", 101, "01:00 PM", 180);
    shows[3] = new Show(3, "Deadpool & Wolverine", "Action", 128, "04:00 PM", 220);

    Theatre theatre("PVR Chennai", 25);
    vector<Booking> allBookings;

    int choice;

    do {
        ConsoleUI::printMenu();
        cin >> choice;

        if (choice == 1) {
            cout << "\n===== NOW SHOWING =====\n";
            for (auto& [id, s] : shows)
                s->display();
        }

        else if (choice == 2) {
            string userName;
            int showChoice;

            cout << "Enter your name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, userName);

            cout << "Select Show (1-3): ";
            cin >> showChoice;

            try {
                if (shows.find(showChoice) == shows.end())
                    throw invalid_argument("Show not found!");

                shows[showChoice]->display();
                theatre.displaySeats();

                int n;
                cout << "How many seats? ";
                cin >> n;

                if (n <= 0 || n > 25) {
                    cout << "Invalid seat count!\n";
                    continue;
                }

                vector<int> selected;

                for (int i = 0; i < n;) {
                    int seat;
                    cout << "Enter seat number: ";
                    cin >> seat;

                    if (find(selected.begin(), selected.end(), seat) != selected.end()) {
                        cout << "Seat already selected!\n";
                        continue;
                    }

                    try {
                        theatre.bookSeat(seat);
                        selected.push_back(seat);
                        i++;
                    } catch (const exception& e) {
                        cout << e.what() << endl;
                    }
                }

                double total = selected.size() * shows[showChoice]->getPrice();
                PaymentProcessor<double> payment(total);
                payment.processPayment();

                Booking b(userName, shows[showChoice], selected);
                b.printTicket();
                allBookings.push_back(b);

            } catch (const exception& e) {
                cout << e.what() << endl;
            }
        }

        else if (choice == 3) {
            cout << "Cancellation coming soon!\n";
        }

        else if (choice == 4) {
            if (allBookings.empty()) {
                cout << "No bookings yet.\n";
            } else {
                for_each(allBookings.begin(), allBookings.end(),
                         [](const Booking& b) { b.printTicket(); });
            }
        }

    } while (choice != 5);

    for (auto& [id, s] : shows)
        delete s;

    cout << "Goodbye!\n";
    return 0;
}