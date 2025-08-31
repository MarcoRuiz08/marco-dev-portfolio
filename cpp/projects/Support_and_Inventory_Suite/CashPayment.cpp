#include <utility>
#include <stdexcept>

#include "CashPayment.hpp"

CashPayment::CashPayment(double cashGiven) : cashGiven(cashGiven) {
    if(cashGiven <= 0) {
        throw std::invalid_argument("The cash should be greater than 0");
    }
};

std::string CashPayment::typePayment() const {
    return "cash";
};
   
bool CashPayment::authorize(double amount) {
    
    if(amount < 0) {
        throw std::invalid_argument("Amount should be greater than 0");
    }

    if(cashGiven >= amount) {
        return true;
    }
    else {
        return false;
    }
};
