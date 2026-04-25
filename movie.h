#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
using namespace std;
// ============================================================
// BASE CLASS: Movie
// Unit 1: Class design, access specifiers, encapsulation
// Unit 2: Virtual function for polymorphism
// ============================================================
class Movie {
protected:
int movieId;
string title;
string genre;
int duration;
public:
// Parameterized Constructor
Movie(int id, string t, string g, int d)
: movieId(id), title(t), genre(g), duration(d) {}
// Virtual function - enables runtime polymorphism
virtual void display() const {
cout << "[" << movieId << "] " << title
<< " | Genre: " << genre
<< " | Duration: " << duration << " min" << endl;
}
// Getters
int getId() const { return movieId; }
string getTitle() const { return title; }
// Virtual Destructor
virtual ~Movie() {}
};
// ============================================================
// DERIVED CLASS: Show (inherits Movie)
// Unit 3: Single Inheritance, Method Overriding
// ============================================================
class Show : public Movie {
string showtime;
double price;
public:
// Constructor calls base class constructor
Show(int id, string t, string g, int d, string st, double p)
: Movie(id, t, g, d), showtime(st), price(p) {}
// Override display() - Runtime Polymorphism
void display() const override {
Movie::display(); // Call base class method
cout << " Showtime : " << showtime
<< " | Price: Rs." << price << endl;
}
double getPrice() const { return price; }
string getShowtime() const { return showtime; }
};
#endif // MOVIE_H
