#include <stdexcept>

#include "CardPayment.hpp"

std::string CardPayment::getMaskedCard() const noexcept {
    return maskedCard;
};
  
std::string CardPayment::getAuthCode() const noexcept {
    return authCode;
};

bool CardPayment::authorize(double amount) {
    if(amount <= 0) {
        throw std::invalid_argument("Amoutn must be greater than 0");
    }

    authCode.clear();
    if(maskedCard.empty()) {
        return false;
    }

    authCode = "AUTH-OK";
    return true;
};