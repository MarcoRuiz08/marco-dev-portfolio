#include <stdexcept>
#include <utility>

#include "DigitalWalletPayment.hpp"

DigitalWalletPayment::DigitalWalletPayment(std::string provider, std::string token) : provider(std::move(provider)), token(std::move(token)){
    if(this->provider.empty()) {
        throw std::invalid_argument("Provider can not be empty");
    }

    if(this->token.empty()) {
        throw std::invalid_argument("Token can not be empty"); 
    }
};
   
std::string DigitalWalletPayment::typePayment() const {
    return "Wallet:" + provider;
};

bool DigitalWalletPayment::authorize(double amount) {
    if(amount <= 0) {
        throw std::invalid_argument("Amount should be greater than 0");
    }

    if(!provider.empty() && !token.empty()) {
        return true;
    }
    else {
        return false;
    }
};