#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
using namespace std;
// ============================================================
// Template Class: PaymentProcessor<T>
// Unit 4: Generic Programming / Templates
// Works with any numeric type: int, float, double
// ============================================================
template <typename T>
class PaymentProcessor {
T amount;
public:
// Constructor
PaymentProcessor(T amt) : amount(amt) {}
// Process the payment
void processPayment() {
cout << "\nProcessing payment of Rs." << amount << "..." << endl;
cout << "Payment Successful! Amount Paid: Rs." << amount << endl;
}
// Getter
T getAmount() const { return amount; }
};
#endif // PAYMENT_H
