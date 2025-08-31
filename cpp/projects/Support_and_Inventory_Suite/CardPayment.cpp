#include <stdexcept>
#include <utility>

#include "CardPayment.hpp"

CardPayment::CardPayment(std::string maskedCard) : maskedCard(std::move(maskedCard)), authCode() {
    if (this->maskedCard.empty()) {
        throw std::invalid_argument("maskedCard must not be empty");
    }
};

std::string CardPayment::getMaskedCard() const noexcept {
    return maskedCard;
};
  
std::string CardPayment::getAuthCode() const noexcept {
    return authCode;
};

std::string CardPayment::typePayment() const {
    return "card";
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